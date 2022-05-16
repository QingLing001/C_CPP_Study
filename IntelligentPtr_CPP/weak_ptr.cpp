#include <iostream>
#include <memory>
using namespace std;

class B;
class A
{
public:
	A()
    {
        cout << "A::A() called" << endl; 
    }
	~A()
    {
        cout << "A::~A() called" << endl;
    }
	shared_ptr<B> m_B;
};
 
class B
{
public:
	B()
    {
        cout << "B::B() called" << endl;
    }
	~B()
    {
        cout << "B::~B() called" << endl;
    }
	//shared_ptr<A> m_A; //引起循环引用
    weak_ptr<A> m_A;
};
int main()
{
 
	shared_ptr<A> pA(new A);
	shared_ptr<B> pB(new B);
	cout << "pA use_count: " << pA.use_count() << endl;
	cout << "pB use_count: " << pB.use_count() << endl;
	pA->m_B = pB;
	pB->m_A = pA;
	cout << "pA use_count: " << pA.use_count() << endl;
	cout << "pB use_count: " << pB.use_count() << endl;
    return 0;
}
