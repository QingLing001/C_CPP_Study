#include <iostream>
#include <memory>
#include <utility>
#include <vector>

using namespace std;
 //初始化
void init()
{
	unique_ptr<int> pUniq(new int(1));
	//unique_ptr<int> pUniq1 = make_unique<int>(2); //std::make_unique’ is only available from C++14 onwards -std=c++14
	cout << *pUniq << endl;
	//cout << *pUniq1 << endl;
}
//拷贝构造、赋值
void copy()
{
	//初始化
	//unique_ptr<int> pUniq(new int(1));
	//unique_ptr 没有copy构造函数，不支持普通的拷贝和赋值操作。
	//unique_ptr<int> pUniq2(pUniq);    // 报错
	//unique_ptr<int> pUniq3 = pUniq;   // 报错
	//unique_ptr<int> pUniq4;
	//pUniq4 = pUniq; // 报错
}
//移动语义
void move()
{
	unique_ptr<int> pUniq(new int(1));
	unique_ptr<int> pUniq1 = std::move(pUniq);// 转移所有权 写法1
	//cout << *pUniq << endl; // 运行时报段错误，pUniq已为空
	cout << *pUniq1 << endl;
	unique_ptr<int> pUniq2(std::move(pUniq1));// 转移所有权 写法2
    *pUniq2 = 2;
    cout << *pUniq2 << endl;
}

unique_ptr<int> clone()
{
    unique_ptr<int> pInt(new int(1));
    return pInt;    //此时作为临时对象可以返回
}
//使用临时对象
void usetmp()
{
    //使用从函数中返回的临时对象
    unique_ptr<int> p = clone();
    cout << *p << endl;
}
//容器
void container()
{
    vector<unique_ptr<int>> vec;
    unique_ptr<int> p(new int(1));
    //vec.push_back(p);    //不可以
    vec.push_back(std::move(p));// 使用移动语义
    cout << *vec[0] << endl;
}

//unique_ptr有std::unique_ptr<T[]>的重载函数
void arr()
{
    unique_ptr<int[]> pArr(new int[5]{0,1,2,3,4});
    for (int i = 0; i < 5; ++i)
    {
        cout << pArr[i] << " ";
    }
    cout << endl;
}

int main()
{
	// init();
	// copy();
	// move();
    // usetmp();
    // container();
    arr();

    return 0;
}