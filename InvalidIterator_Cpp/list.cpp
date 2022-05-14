//vector list deque是线性容器 erase可能引起的失效是相似的
#include <iostream>
#include <list>
using namespace std;
 
typedef list<int> List;
typedef list<int>::iterator ListIt;
 
void print(List &l)
{
	ListIt it;
	for(it = l.begin(); it != l.end(); it++)
	{
		cout << *it << " ";
	}
 
	cout << endl;
}

//错误写法
void deleteValue(List &l, int n = 2)
{
	for(auto it = l.begin(); it != l.end(); it++)
	{
		if(0 == *it % n)
		{
			l.erase(it);//删除后当前位置迭代器失效，再++就出错
		}
	}
}

// //正确写法
// void deleteValue(List &l, int n = 2)
// {
// 	for(auto it = l.begin(); it != l.end(); )
// 	{		
// 		if(0 == *it % n)
// 		{
// 			//l.erase(it++);  //写法1
// 			it = l.erase(it); //写法2 erase 返回it下一个位置,所以不能再把it进行++了
// 		}
// 		else
// 		{
// 			it++;
// 		}
// 	}
// }
 
int main()
{
	List l = {0,1,2,3,4};
	print(l);
 
	deleteValue(l);
	print(l);
 
	return 0;
}
