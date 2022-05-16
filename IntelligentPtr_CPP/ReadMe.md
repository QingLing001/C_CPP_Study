# **1.shared_ptr**
    // shared_ptr应注意：
    // 不使用相同的内置指针值初始化（或reset）多个智能指针，同理不使用get()初始化或reset另一个智能指针
    // 不delete get()返回的指针
    // 如果你使用get()返回的指针，记住当最后一个对应的智能指针销毁后，你的指针就变为无效了
    // 如果你使用智能指针管理的资源不是new分配的内存，记住传递给它一个删除器。
    // 如果非要混合使用shared_ptr和原始裸指针时，尽量使用shared_ptr来管理delete.
    // shared_ptr 具有 “传染性”：一个对外的接口中使用了shared_ptr，那么所有使用这个接口的地方全都要改为使用shared_ptr，否则shared_ptr无法覆盖到对象整个生命周期，就成了摆设。
    // shared_ptr本身线程也不安全，多线程使用要先复制一个。
    // 可在够用的情况下考虑使用unique_ptr替代。
    // 初始化时尽量使用make_shared
    // shared_ptr对象里再套shared_ptr对象时务必小心，是否有场景存在循环引用

# **2.weak_ptr**
    // weak_ptr设计之初就是为了服务于shared_ptr的，不增加引用计数就是它的核心功能。
    // weak_ptr 是一种不控制对象生命周期的智能指针, 它指向一个 shared_ptr 管理的对象. 进行该对象的内存管理的是那个强引用的 shared_ptr. 
    // weak_ptr虽然是一个模板类，但是不能用来直接定义指向原始指针的对象。
    // weak_ptr.use_count() 返回与 shared_ptr 共享的对象的引用计数.
    // weak_ptr.reset() 将 weak_ptr 置空
    // 使用expired函数检测weak_ptr所指向的对象是否已被析构掉
    // weak_ptr.lock() 如果当前 weak_ptr 已经过期，则该函数会返回一个空的 shared_ptr 指针；反之，该函数返回一个和当前 weak_ptr 指向相同的 shared_ptr 指针。
    // weak_ptr<T> 模板类中没有重载 * 和 -> 运算符，这也就意味着，weak_ptr 类型指针只能访问所指的堆内存，而无法修改它。

# **3.unique_ptr**
    // unique_ptr独占管理对象，只有移动语义，禁止拷贝和赋值;
    // unique_ptr可以为空