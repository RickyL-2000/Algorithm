# 类

> example: class_intro.cpp (然而并不存在Sales_item.h的头文件)

在C++中，我们通过定义一个类(class)来定义自己的数据结构。
每个类实际上都定义了一个新的类型。
example: Sales_item item

**NOTE**: 对于不属于标准库的头文件，用双引号包围("Sales_item.h")

对象的加法

(?)**NOTE**： 使用文件重定向


## 定义抽象数据类型

类允许用户直接访问它的数据成员，并且要求由用户来编写操作。一旦类有了它自己的操作，我们就可以封装(隐藏)它的数据成员了。

按照C++Primer这本书，之后的例子估计都会以Sales_data类的形式呈现

### 设计类

example, improved Sales_data class:
``` C++
struct Sales_data {
    // new members, operations:
    std::string isbn() const {return bookNo; }
    Sales_data& combine (const Sales_data&);
    double avg_price() const;

    //data members
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
// Sales_data的非成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream, Sales_data&);

//定义在类内部的函数是隐式的 inline 函数 (???)

//接下来使用Sales_data类
Sales_data total;
if (read(cin, total)) {
    Sales_data trans;
    while(read(cin, trans)) {
        if (total.isbn() == trans.isbn())
            total.combine(trans);
        else {
            print(cout, total) << endl;
            total = trans;
        }
    }
    print(cout, total) << endl;
} else {
    cerr << "No data?!" << endl;
}
//各函数解释：
//combine() 将trans的内容添加到total表示的实时汇总结果中去
//print() 将之前一本书的汇总信息输出出来，返回它的流参数的引用
```

#### 成员函数 (member function)

成员函数是定义为类的一部分的函数，有时候也被成为方法(method)。

定义成员函数的方式与普通函数差不多。尽管所有成员函数都必须在类的内部声明，但是成员函数体可以定义在类内也可以定义在类外。

##### 引入 this

观察对 isbn 成员函数的调用：
``` C++
    total.isbn()
```
当我们调用 isbn 成员函数时，实际上是在替另一个对象 bookNo 调用它。isbn 隐式地指向调用该函数的对象的成员。

成员函数通过一个名为 this 的额外的隐式参数来访问调用它的那个对象。当调用一个成员函数时，用请求该函数的对象地址初始化 this。所以 isbn 成员函数的调用可以认为是被编译器重写成了：

    Sales_data::isbn(&total)

对于我们来说，this 形参是隐式定义的。实际上，任何自定义名为 this 的参数或者变量都是非法的。我们可以在成员函数体内部使用 this，因此尽管没有必要，但是我们还是能把 isbn 定义成如下的形式：

    std::string isbn() const { return this->bookNo; }

this 是一个常量指针

##### 引入 const 成员函数

isbn 函数的另一个关键之处是紧随参数列表之后的 const 关键字，这里，const的作用是修改隐式 this 指针的类型

默认情况下，this 的类型是指向类类型非常量版本的常量指针。例如在 Sales_data 成员函数中，this 的类型是 Sales_data *const。尽管 this 是隐式的，但它仍然需要遵循初始化规则，意味着（在默认情况下）我们不能把 this 绑定到一个常量对象上。这一情况也就使得我们不能在一个常量对象上调用普通的成员函数。

如果 isbn 是一个普通函数而且 this 是一个普通的指针参数，我们就应该把 this 声明成 const Sales_data *const。毕竟，在 isbn 的函数体内不会改变 this 所指的对象，所以把 this 设置为指向常量的指针有助于提高函数的灵活性。

        std::string isbn() const {return bookNo; }

像这样使用 const 的成员函数被称作常量成员函数

##### 类作用域和成员函数

##### 内联成员函数

定义在类中的函数是自动inline的。因此，一般定义在类内的构造函数默认是inline函数。






### 构造函数

每个类都分别定义了它的对象被初始化的方式，类通过一个或几个特殊的成员函数来控制其对象的初始化过程，这些函数叫做构造函数(constructor)。

构造函数的名字和类名相同。和其他函数不一样的是，构造函数没有返回类型。除此之外类似于其他函数，构造函数也有一个（可能为空的）参数列表和一个（可能为空的）函数体。

不同于其他成员函数，构造函数不能被声明成const的。当我们创建类的一个const对象时，直到构造函数完成初始化过程，对象才能真正取得其“常量”属性。因此，构造函数在const对象的构造过程中可以向其写值。

考虑Sales_data类并没有定义任何构造函数，可是之前使用了其对象的程序仍然可以编译和运行：

    Sales_data total;
    Sales_data trans;

我们没有为这些对象提供初始值，因为它们执行了默认初始化。类通过一个特殊的构造函数来控制默认初始化过程，这个函数叫做默认构造函数。默认构造函数无须任何实参。编译器创建的构造函数又被称为合成的默认构造函数。


#### 定义构造函数

定义Sales_data的构造函数

对于Sales_data来说，我们将使用下面的参数定义4个不同的构造函数：
1. 一个istream，从中读取交易信息
2. 一个const strings，表示ISBN编号；一个unsigned，表示售出的图书数量；以及一个double。表示图书的售出价格。
3. 一个const strings，表示ISBN编号；编译器将赋予其他成员默认值。
4. 一个空参数列表（默认构造函数）

给类添加了这些成员之后，将得到：
``` C++
    struct Sales_data {
        Sales_data() = default; //默认构造函数
        Sales_data(const std::string &s) : bookNo(s) {}
        Sales_data(const std::string &s, unsigned n, double p):
                bookNo(s), units_sold(n), revenue(p*n) {}
        Sales_data(std::istream &);
    
        std::string isbn() const {return bookNo;}
        Sales_data& combine(const Sales_data&);
        double avg_price() const;
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    }
```
在第二个和第三个构造函数中，冒号以及冒号和花括号之间的代码被称为**构造函数初始值列表**，它负责为新创建的对象的一个或几个数据成员赋初值。

在第二个构造函数中，只有一个string类型参数被初始化了，其他数据成员被构造函数初始值列表忽略了，此时，它们将以与合成默认构造函数相同的方式隐式初始化。因此只接受一个string参数的构造函数等价于：

    Sales_data(const std::string &s):
            bookNo(s), units_sold(0), revenue(0) {}

#### 在类的外部定义构造函数

#### 拷贝构造函数

如果我们没有为一个类定义拷贝构造函数，编译器会为我们定义一个。

#### 定义删除的函数

删除函数是这样一种函数：我们虽然声明了它们，但不能以任何方式使用它们。(?????)

> example:
```
struct NoCopy {
    NoCopy() = default;
    NoCopy(const NoCopy&) = delete;     // 阻止拷贝
}
```



### 访问控制与封装

在C++中，我们使用访问说明符(access specifiers)加强类的封装性：
1. 定义在 public 说明符之后的成员在整个程序内可被访问，public 成员定义类的接口
2. 定义在 private 说明符之后的成员可以被类的成员函数访问，但是不能被使用该类的代码访问，private部分封装了(即隐藏了)类的实现细节

example:

    class Sales_data {
    public:
        Sales_data() = default;
        Sales_data(const std::string &s, unsigned n, double p): 
                bookNo(s), units_sold(n), revenue(p*n) {}
        Sales_data(const std::string &s): bookNo(s) {}
        Sales_data(std::istream&);
        std::string isbn() const {return bookNo;}
        Sales_data &combine(const Sales_data&);
    private:
        double avg_price() const
            { return units_sold ? revenue/units_sold : 0; }
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };

#### 使用 class 或 struct 关键字

class 和 struct 仅仅是形式上有所不同。唯一的一点区别是，struct 和 class 的默认访问权限不太一样。

类可以在它的第一个访问说明符之前定义成员，对这种成员的访问权限依赖于类定义的方式。如果是 struct 关键字，则默认是 public；如果是 class 关键字，则是 private 的。


### 结构体指针

一个结构体变量的指针就是该变量所占据的内存段的起始地址。可以设一个指针变量，用来指向一个结构体变量，此时该指针变量的值是结构体变量的起始地址。指针变量也可以用来指向结构体数组中的元素。

初始化一个结构体指针并不会自动创建一个结构体变量

#### Constructor Reference

Copy constructor and pass by constant reference!

```
class Rectangle {
    int width, height;
    public:
    // copy construct
        Rectangle(const Rectangle &obj) {
            width = obj.width;
            height = obj.height;
        }
};
```

### 友元

如果一个类指定了友元类，则友元类的成员函数可以访问此类**包括非公有成员**在内的所有成员。