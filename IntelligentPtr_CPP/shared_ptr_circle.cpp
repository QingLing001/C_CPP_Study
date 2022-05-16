#include <iostream>
#include <memory>
// 循环引用示例
//原文链接：https://blog.csdn.net/xucongyoushan/article/details/102694245
struct Node
{
	std::shared_ptr<Node> _prev;
	std::shared_ptr<Node> _next;

	~Node() { std::cout << "~Node" << std::endl; }
};

int main()
{
	auto head = std::make_shared<Node>();
	auto tail = std::make_shared<Node>();
	head->_next = tail;
	tail->_prev = head;
	return 0;
}
// 在退出函数之时，局部变量因超出作用域而结束生命周期，依次销毁共享指针tail和head。
// 在析构tail之时，head所指节点的后继仍指向tail所指节点及其引用计数对象，导致引用计数对象的两个计数器都未归零，即tail所指节点及其引用计数对象无法销毁。
// 在析构head之时，由于tail所指节点未被销毁，而节点的前驱仍指向head所指节点及其引用计数对象，同样导致引用计数对象的两个计数器未归零，即head所指节点及其引用计数对象无法销毁。
// 所有节点及其引用计数对象未正常销毁，最终导致资源泄漏。