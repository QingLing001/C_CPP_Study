// 循环引用示例 具有隐蔽性
//原文链接：https://blog.csdn.net/xucongyoushan/article/details/102694245
#include <functional>
#include <memory>
#include <iostream>

class ThreadPool
{
	struct Structure
	{
		std::function<void(bool)> _callback;

		~Structure() { std::cout << "~Structure" << std::endl; }
	};

private:
	std::shared_ptr<Structure> _data;

public:
	ThreadPool()
		: _data(std::make_shared<Structure>())
	{
		_data->_callback = [_para = _data](bool) {};
		//_data->_callback = [_para = std::weak_ptr(_data)](bool) {};//解决方法
	}
	~ThreadPool()
	{
		std::cout << "~ThreadPool()" << std::endl;
	}
};

int main()
{
	ThreadPool threadPool;
	return 0;
}
// 构造ThreadPool对象之时，先在构造函数体外的初始化列表之中，调用函数std::make_shared，创建指向Structure实例的共享指针，用以构造成员变量_data。
// 再于构造函数体内，以Lambda表达式初始化Structure成员变量_callback。在Lambda的捕获列表之中，以成员变量_data复制构造非局部变量_data，二者共同指向Structure实例及其引用计数对象。
// 析构ThreadPool对象之时，也会析构成员变量_data，由于存在非局部变量_para，引用计数对象的两个计数器都未归零，即Structure实例及其引用计数对象都未销毁，
// 而Structure成员变量_callback未析构，因此非局部变量_data无法析构，最终导致资源泄漏。