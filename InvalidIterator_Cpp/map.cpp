#include <iostream>
#include <map>
using namespace std;
 
typedef map<int, int> Map;
typedef map<int, int>::iterator MapIt;
 
void print(Map &m)
{
	MapIt it;
	for(it = m.begin(); it != m.end(); it++)
	{
		cout << it->second << " ";
	}
 
	cout << endl;
}

// //错误写法 
// void deleteValue(Map &m, int n = 2)
// {
// 	MapIt it;
// 	for(it = m.begin(); it != m.end(); it++)
// 	{
// 		if(0 == it->second % n)
// 		{
// 			m.erase(it); //erase后迭代器已失效，不能再++
// 		}
// 	}
// }

//正确写法
void deleteValue(Map &m, int n = 2)
{
	MapIt it;
	for(it = m.begin(); it != m.end();)
	{
		if(0 == it->second % n)
		{
			m.erase(it++); //先++，再erase
            //it = m.erase(it); //C++11可采用如此写法
		}
        else
        {
            ++it;
        }
	}
}

// m.erase(it++);就不会产生迭代器失效么？确实不会！
// 例如：* ptr++ ；很多人错误地以为是先执行* p, 然后执行p++, 其实， 这是个天大的误解。 大家可以查一下* 和++的执行顺序， 虽然* 和++的优先级相同， 但此处采取的是右结合方式， 实际上先执行的是p++。
// 不过， p++的返回值是原来的p, 也就是说, *p++的值还是原值，它的内部大致是这样子的：
// temp=*p;
// p++;
// return temp;
// 所以， 在m.erase(it++);中，it++先执行， 此时还没有erase， 程序自然不会崩溃. 当it++执行完后， 已经指向了下一个元素了， 但it++的返回值还是当前元素， 此时再删除它， 合情合理。


int main()
{
	Map m;
	int i = 0;
	for(i = 0; i < 5; i++)
	{
		m[i] = i;
	} 
	print(m);
 
	deleteValue(m); // 程序在此处崩溃
    print(m);

	return 0;
}