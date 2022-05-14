//vector list deque是线性容器 erase可能引起的失效是相似的
#include <iostream>
#include <vector>
using namespace std;
 
typedef vector<int> Vec;
typedef vector<int>::iterator VecIt;


void print(Vec &v)
{
	VecIt it;
	for(it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
 
	cout << endl;
}

//错误写法
void deleteValue(Vec &v, int n = 2)
{
	for(auto it = v.begin(); it != v.end(); it++)
	{
		if(0 == *it % n)
		{
			//vector元素自动向前挪动了(关联的map容器元素不会自动挪动)
			//删除后it的实际指向相当于已经指向下一个元素，继续++相当于一次加了2步，
			//因此删除最后一个元素的时候，迭代器已经指向end,再++就错了 程序崩溃
			//如果本例中Vec v = {0,1,2,3,4}; 把4去掉就又不会崩溃了。
			v.erase(it);
		}
	}
}

// //正确写法
// void deleteValue(Vec &v, int n = 2)
// {
// 	for(auto it = v.begin(); it != v.end();)
// 	{
// 		if(0 == *it % n)
// 		{
// 			it = v.erase(it); //erase 返回it下一个位置,所以不能再把it进行++了
// 		}
// 		else
// 		{
// 			it++;
// 		}
// 	}
// }
 
int main()
{
	Vec v = {0,1,2,3,4};
	print(v);
 
	deleteValue(v);
	print(v);
 
	return 0;
}
