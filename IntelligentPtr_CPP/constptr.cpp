#include <iostream>
#include <memory>
using namespace std;
//const总结四个字:就近原则　const int * const ptr =;精髓就在这

void Test1()
{
    //shared_ptr< T> p; —> T * p; : nothing is const
    cout << "--------------非const 指针---------------" << endl;
    shared_ptr<int> p1 = make_shared<int>(1);
    cout << p1 << endl;
    p1.reset();
    cout << p1 << endl;
}

void Test2()
{
    shared_ptr<int> p1 = make_shared<int>(1);

    // const shared_ptr< T> p; —> T * const p; : p is const
    cout << "--------------指针指向不可改,可改指向的值---------------" << endl;
    const shared_ptr<int> p2 = make_shared<int>(1);
    //p2 = p1;//不允许
    //p2.reset();//不允许
    *p2 = 2;
    cout << *p2 << endl;
}

void Test3()
{
    shared_ptr<int> p1 = make_shared<int>(1);

    //shared_ptr< const T> p; —> const T * p; <=> T const * p; : *p is const
    cout << "--------------指针本身指向可改,不可改指向的值---------------" << endl;
    shared_ptr<const int> p3 = make_shared<int>(1);
    //*p3 = 2; //不允许改值
    p3 = p1;//允许
    p3.reset();//允许
}

void Test4()
{
    shared_ptr<int> p1 = make_shared<int>(1);

    // const shared_ptr< const T> p; —> const T * const p; <=> T const * const p; : p and *p are const.
    cout << "--------------指针指向不可改,指向的值也不可改---------------" << endl;
    const shared_ptr<const int> p4 = make_shared<int>(1);
    // *p3 = 2; //不允许改值
    // p4 = p1;//不允许
    // p4.reset();//不允许
}

int main()
{
    Test1();
    Test2();
    Test3();
    Test4();
	return 0;
}