//C++98 应尽量避免使用
// 1.所有权唯一（即一个堆内存只能有一个指针指向，绝对占有）
// 2.新智能指针获取到所有权时，取消掉旧智能指针的所有权
// 3.缺点：所有权的权限转移，会使得对象提前失效。不适合放在容器中
#include <iostream>
#include <memory>
template <typename T>
class auto_ptr {
public:
	auto_ptr(T* ptr)
		:mptr(ptr)
	{}
	auto_ptr(auto_ptr<T>& rhs)//浅拷贝构造函数
	{
		mptr = rhs.Release();//让新的指针指向内存块，同时让旧的指针指向为空
		/*
		T* ptr = rhs.mptr;
		mptr = NULL;
		mptr=ptr;
		*/
	}
	auto_ptr<T>& operator=(auto_ptr<T>& rhs)//赋值运算符重载函数
	{
		if (this != &rhs)//判断是否自赋值
		{
			delete mptr;
			mptr = rhs.Release();
		}
		return *this;
	}
	~auto_ptr()
	{
		delete mptr;
	}
	T* operator->()//->运算符重载
	{
		return mptr;
	}
	T& operator*()//*运算符重载
	{
		return *mptr;
	}
private:
	T* Release()
	{
		T* ptr = mptr;
		mptr = NULL;
		return ptr;
	}
	T* mptr;
};
int main()
{
	auto_ptr<int> p1 = new int(5);
	auto_ptr<int> p2 = p1;//此时p1的唯一权已经转移到p2中，此时p1已经失效
	//std::cout << *p1 << std::endl;//非法内存使用
    std::cout << *p2 << std::endl;
	return 0;
}