
//以下代码来源于网络，原始文章里构造函数里没有给flag设置true并且模板的写法有点问题，此处已更正 20220516 王亚飞

//--------------------------------以下内容来源于网络----------------------------------------------
//https://blog.csdn.net/wu___hao/article/details/108506243
// 为了解决auto_ptr让指针提前失效的方法,又出现了一种带标志位的指针。它取消了堆内存的唯一权，即一块内存可以有多个指针指向。但是它的释放权此时唯一，
// 也就是说当最后一个指针（拥有释放权的指针一旦释放）执行析构函数，那么指向这块空间的所有指针也将会释放。
// 基本概念：新智能指针获取到释放权后，取消掉旧智能指针的释放权
#include <iostream>
//#include <memory>
using std:: ostream;
template <typename T>
class smartptr
{
public:
	smartptr(T* ptr) : mptr(ptr) , flag(true)
	{}
	smartptr(smartptr<T>& rhs)
	{
		mptr = rhs.mptr;
		flag = rhs.flag;
		rhs.flag = false;
	}
	smartptr<T>& operator=(smartptr<T>& rhs)
	{
		if (this != &rhs)
		{
			if (flag)
			{
				delete mptr;
			}
			mptr = rhs.mptr;
			flag = rhs.flag;
			rhs.flag = false;
		}
		return *this;
	}
	~smartptr()
	{
		if (flag)
		{
			delete mptr;
		}
		mptr = NULL;
	}
	T& operator*()
	{
		return *mptr;
	}
	T* operator->()
	{
		return mptr;
	}

private:
	template <typename Y>//这里使用另一个typename 不会产生编译期认为的已定义的现象。
	friend ostream& operator<<(ostream& os, smartptr<Y>& rhs);
	T* mptr;
	bool flag;
};
template <typename Y>
ostream& operator<<(ostream& os, smartptr<Y> &rhs)
{
	os << "mptr=" << rhs.mptr << " ";
	os << "flag=" << std::boolalpha << rhs.flag;
	return os;
}

int main()
{
	smartptr<int> p1 = new int;
    std::cout << p1 << std::endl;
	smartptr<int> p2 = p1;
	std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
	return 0;
}