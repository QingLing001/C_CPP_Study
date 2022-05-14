//vector list deque是线性容器 erase可能引起的失效是相似的
#include <iostream>
#include <deque>
using namespace std;
 
typedef deque<int> Deque;
typedef deque<int>::iterator DequeIt;

void print(Deque &d)
{
	DequeIt it;
	for(it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
 
	cout << endl;
}

//错误写法
void deleteValue(Deque &d, int n = 2)
{
	for(auto it = d.begin(); it != d.end(); it++)
	{
		if(0 == *it % n)
		{
			d.erase(it);//删除后后面元素自动相当于自动前移，再++相当于一次加了2步，end的时候再++就错了 程序崩溃
		}
	}
}

// //正确写法
// void deleteValue(Deque &d, int n = 2)
// {
// 	for(auto it = d.begin(); it != d.end(); )
// 	{
// 		if(0 == *it % n)
// 		{
// 			it = d.erase(it); //erase 返回it下一个位置,所以不能再把it进行++了
// 		}
// 		else
// 		{
// 			it++;
// 		}
// 	}
// }
 
int main()
{
	Deque d = {0,1,2,3,4};
	print(d);
 
	deleteValue(d);
	print(d);
 
	return 0;
}
