//这是一个shared_ptr的伪实现
//原文链接：https://blog.csdn.net/wu___hao/article/details/108506243
#include <iostream>
#include <exception>
using namespace std;
class mem_ref//结构体方法的接口
{
public:
	mem_ref()//默认的构造函数
	{
		size = 0;//将下标置为0
	}
	void addref(void* ptr)//添加一个新节点
	{
		if (ptr == NULL)//如果指针为空（指向的是空）
		{
			return;//不做处理，直接return出去
		}
		int index = find(ptr);//定义一个整形值来结构find的返回值
		if (index < 0)//如果返回值小于0，说明没有找到这个节点，这时需要为结构添加一个新节点
		{
			node[size].addr = ptr;//添加新堆内存地址到新节点中
			node[size].ref = 1;//将新节点的引用计数初始化为1
			size++;//当前下标已经有了地址，将下标往下走一个
		}
		else//如果大于0，说明找到了指针指向所对应的地址
		{
			node[index].ref++;//将引用计数++(此时又多了一个指针指向该堆内存)
		}
	}
	void deleteref(void* ptr)//删除一个指向
	{
		if (ptr == NULL)//如果指针为空（指向的是空）
		{
			return;//不做处理，直接return出去
		}
		int index = find(ptr);//定义一个整形值来结构find的返回值
		if (index < 0)//如果没有找到指针对应的地址，说明在结构体中没有存储该指针的地址
		{
			throw "ptr is error!";//发出异常
		}
		else
		{
			if (node[index].ref > 0)//返回值大于0表明找到了该内存的位置
			{
				node[index].ref--;//将引用计数--
			}
		}
	}
	int getref(void* ptr)//查找一个地址，并返回指向该地址的个数
	{
		if (ptr == NULL)//指向为空
		{
			return -1;//返回-1
		}
		int index = find(ptr);//定义一个整形值来结构find的返回值
		if (index < 0)//返回值小于0，没有找到
		{
			return -1;//报错
		}
		else
		{
			return node[index].ref;//返回相应的个数
		}
	}
private:
	int find(void* ptr)
	{
		for (int i = 0; i < size; i++)//i小于当前存数个数的下标
		{
			if (node[i].addr = ptr)//遍历下标中的堆内存，查看是否相匹配
			{
				return i;
			}
		}
		return -1;
	}
	struct Node
	{
		Node(void* add=NULL, int cnt = 0)//Node的构造函数
			:addr(add), ref(cnt)
		{}
		void* addr;//定义一个void*的指针来指向该内存（不能保证堆内存的类型，所以使用void*）
		int ref;//引用计数
	};
	Node node[10];//申请10个空间存放堆内存和引用个数
	int size;
};
template <typename T>
class shared_ptr
{
public:
	shared_ptr(T* ptr = NULL)
		:mptr(ptr)//构造函数初始化
	{
		mm.addref(mptr);//每初始化一个就调用一次addref()接口
	}
	shared_ptr(shared_ptr<T>& rhs)//拷贝构造函数
	{
		mptr = rhs.mptr;//将mptr指向rhs.mptr
		mm.addref(mptr);//每次指向一个堆内存，该堆内存的引用计数++
	}
	shared_ptr<T>& operator=(shared_ptr<T>& rhs)//赋值运算符的重载函数
	{
		if (this != &rhs)//判断是否自赋值
		{
			mm.deleteref(mptr);//将赋值的引用计数--
			if (mm.getref(mptr) == 0)//如果--后引用计数为0，则删除该堆内存
			{
				delete mptr;
			}
			mptr = rhs.mptr;//rhs.mptr指向mptr
			mm.addref(mptr);//赋值后，多了一个指向来指向该堆内存，调动该addref()函数
		}
		return *this;//如果是自赋值，直接将this指针return出去
	}
	~shared_ptr()
	{
		mm.deleteref(mptr);//调动deleteref删除一个引用计数
		if (mm.getref(mptr) == 0)//判断是否为0
		{
			delete mptr;//如果是，删除该堆内存
		}
		else
		{
			mptr = NULL;//如果不是，说明还有其他的指针指向该堆内存，将该指针的指向置为空
		}
	}
	T* operator->()
	{
		return mptr;
	}
	T& operator*()
	{
		return *mptr;
	}
private:
	T* mptr;
	static mem_ref mm;//定义一个全局变量来调动接口
};
template <typename T>
mem_ref shared_ptr<T>::mm;//mem_ref类型的,在shared_ref作用于下的一个全局静态变量
int main()
{
	int* p = new int;
	shared_ptr<int> sp1(p);
	shared_ptr<int> sp2(p);
	shared_ptr<int> sp3(p);
	return 0;
}