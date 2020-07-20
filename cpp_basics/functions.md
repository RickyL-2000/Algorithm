# 函数

## 基本常用函数

* getline()

    string str;
    getline(cin, str);

* to_string(val)

    int val = 123;
    string str = to_string(val);

一组重载函数，返回数值val的string表示。定义在<string>头文件中

## 容器常用函数

* .find()

    vector<int> nums = {2,4,6,8,10};
    for (int i = 0; i < 10; ++i) {
        if (nums.find(i) != nums.end())
            cout << i << endl;
    }

find()函数返回一个迭代器。如果给定关键字在set中，迭代器指向该关键字。否则，find()返回尾后迭代器。
    


## 函数基础

### 局部对象

在C++语言中，名字有作用域，对象有生命周期：
1. 名字的作用域是程序文本的一部分，名字在其中可见。
2. 对象的生命周期是程序执行过程中该对象存在的一段时间。



### 函数声明

### 分离式编译 (???)

## 参数传递

形参的类型决定了形参和实参交互的方式。如果形参是引用类型，它将绑定到对应的实参上；否则，将实参的值拷贝后赋给形参。

当形参是引用类型时，我们说它对应的实参被引用传递(passed by reference)或者函数被传引用调用(called by reference)。

当实参的值被拷贝给形参时，就是值传递或者传值调用。

### 传引用参数

对于引用的操作实际上是作用在引用所引的对象上。

可以使用引用来避免拷贝。因为拷贝大的类类型对象或者容器对象比较低效，甚至有点类类型(包括IO类型在内)根本就不支持拷贝操作。example:

    bool isShorter(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

### 数组形参

数组的两个特殊性质对我们定义和使用作用在数组上的函数有影响：
1. 不允许拷贝数组。所以无法以值传递的方式使用数组参数。
2. 使用数组时会将其转换成指针。所以为函数传递一个数组时，实际上传递的是指向数组首元素的指针，所以一开始函数并不知道数组的确切尺寸。

为了传递数组参数，需要提供一些额外的信息。一般有三种常用的技术：

* 使用标记指定数组长度

典型是C风格字符串，在最后一个字符后面跟着一个空字符

* 使用标准库规范

传递指向数组首元素和尾后元素的指针。example:

    void print(const int *beg, const int *end)  //指向整型常量
    {
        while (beg != end)
            cout << *beg++ <<endl;
    }

* 显式传递一个表示数组大小的形参

example:

    void print(const int ia[], size_t size)
    {
        for (size_t i = 0; i = size; ++i) {
            cout << ia[] << endl;
        }
    }

### main: 处理命令行选项 (???)

main 函数是演示C++程序如何向函数传递数组的好例子

### 含有可变形参的函数



## 返回类型和 return 语句

返回void的函数不要求非得有return语句，因为在这类函数的最后一句后面会隐式地执行return

### 主函数main的返回值 (??)

### 返回数组指针



## 函数重载 (function overloaded)

(?)

### 重载与作用域


## 特殊用途语言特性

### 默认实参

### 内联函数和 constexpr 函数

在大多数机器上，一次函数调用其实包含着一系列工作：调用前要先保存寄存器，并在返回时回复；可能需要拷贝实参；程序转向一个新的位置继续执行。
内联函数可以避免函数调用的开销。将函数指定为内联函数(inline)，通常就是将它在每个调用点上“内联地”展开。

example:

    inline const string &shorterString(const string &s1, const string &s2) {
        return s1.size() <= s2.size() ? s1 : s2;
    }

### 调试帮助

assert 预处理宏

NDEBUG 预处理变量



## 函数匹配

针对多个重载函数(?)

### 实参类型转换



## 函数指针

函数指针指向的是函数而非对象