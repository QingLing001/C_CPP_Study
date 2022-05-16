#include <iostream>
#include <memory>
using namespace std;
//weak_ptr<T> 模板类中没有重载 * 和 -> 运算符
struct A
{
    int m_a = 5;
};

int main()
{
	shared_ptr<A> pShared(new A);
	weak_ptr<A> pWeak(pShared);

	cout << pShared->m_a << endl;
    //cout << pWeak->m_a << endl; //error: base operand of ‘->’ has non-pointer type
    //cout << (*pWeak).m_a << endl; //error: no match for ‘operator*’
    cout << pWeak.lock()->m_a << endl;//访问数据

    return 0;
}
