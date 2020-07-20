# 运算符和语句

## 运算符

### 算术运算符

略

### 逻辑和关系运算符

| operator |        meaning        |
| :------: | :-------------------: |
|    !     |          NOT          |
|    <     |     smaller than      |
|    <=    | smaller than or equal |
|    >     |      larger than      |
|    >=    | larger than or equal  |
|    ==    |         equal         |
|    !=    |       not equal       |
|    &&    |          AND          |
|   \|\|   |          OR           |

**NOTE**：短路求值 (short-circuit evaluation)。
1. 对于AND来说，当且仅当左侧运算对象为真时才对右侧求值
2. 对于OR来说，当且仅当左侧运算对象为假时才对右侧求值 

### 赋值运算符=

赋值运算符的左侧运算对象必须是一个可修改的左值。

赋值运算满足右结合律

### 递增和递减运算符

因为很多迭代器本身不支持算术运算，所以此时递增和递减运算除了书写简洁外还是必须的。

递增和递减运算符有两种形式：**前置版本和后置版本**

前置版本首先将对象+-1，然后将改变后的对象作为求值结果。后置版本也会将对象+-1，但是求值结果是运算对象改变之前那个值的版本。example:

    int i = 0, j;
    j = ++i;  // j = 1, i = 1
    j = i++;  // j = 1, i = 2

**NOTE**：**除非必须，否则不用递增递减运算符的后置版本。**
原因非常简单，前置版本的递增运算符避免了不必要的工作。后置版本需要将原始值存储下来以便于返回这个未修改的内容。如果我们不需要修改前的值，那么后置版本的操作就是一种浪费。

#### 在一条语句中混用解引用和递增运算符

example:

    auto pbeg = v.begin();
    while (pbeg != v.end() && *pbeg >= 0)
        cout << *pbeg++ <<endl;

**后置递增运算符的优先级高于解引用运算符**，因此\*pbeg++等价于\*(pbeg++)。这种用法完全是基于一个事实，即后置递增运算符返回初始的未加1的值。

#### 注意运算对象的求值顺序

大多数运算符都没有规定运算对象的求值顺序。如果一条式子表达式改变了某个运算对象的值，另一条子表达式又要使用该值的话，运算对象的求值顺序就很关键了。


### 成员访问运算符.

点运算符和箭头运算符都可以用于访问成员

### 条件运算符

example:

    string finalgrade = (grade < 60) ? "fail" : "pass";
    
    finalgrade = (grade > 90) ? "high pass"
                              : (grade < 60) ? "fail"
                                             : "pass";
    //把成绩分三档


### 位运算符

| operator |  function   |     format     |
| :------: | :---------: | :------------: |
|    ~     | reverse bit |     ~ expr     |
|    <<    | left shift  | expr1 << expr2 |
|    >>    | right shift | expr1 >> expr2 |
|    &     |   bit AND   |  expr & expr   |
|    ^     |   bit XOR   |  expr ^ expr   |
|    \|    |   bit OR    |  expr \| expr  |

**NOTE**：
1. 一般来说，如果对象是“小整型”，则它的值会被自动提升成较大的整数类型。
2. 运算对象可以是带符号的，也可以是无符号的。如果运算对象是负的，那么位运算符如何处理运算对象的“符号位”依赖于机器。而且，此时的左移操作困难会改变符号位的值，因此是一种未定义的行为。所以强烈建议仅将位运算符用于处理无符号类型

#### 移位运算符

**右侧的运算对象一定不能为负，而且值必须严格小于结果的位数，否则就会产生未定义的行为。**

移出边界之外的位会被舍弃。

* 重载运算符

    cout << "hi" << "there" << endl;

移位运算符的优先级比算术运算符的优先级低，但比关系运算符、赋值运算符和条件运算符的优先级高


### sizeof 运算符

返回一条表达式或者一个类型名字所占的字节数。sizeof运算符满足右结合律，其所得的值是一个size_t类型的常量表达式。运算符的运算对象有两种形式：

    sizeof (type)
    sizeof expr //返回表达式结果类型的大小，而且并不实际计算其运算对象的值

**NOTE**：sizeof并不实际计算其运算对象的值。所以在sizeof的运算对象中解引用一个无效指针仍然是一种安全的行为，因为指针实际上并没有被真正使用。

### 逗号运算符

略

### 类型转换和算术转换

#### 类型转换

#### 算术转换

#### 隐式类型转换

#### 显式类型转换


## 循环结构

### while 语句

> example: while_statement.cpp

**NOTE**: 
1. endl默认换行

#### 空语句

空语句是最简单的语句，空语句中只含有一个单独的分号

如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，就可以使用空语句。example:

    while (cin >> s && s != sought)
        ; //空语句

### for 语句

> example: for_statement.cpp

每个for语句包含两部分：循环头和循环体。
循环头控制循环体的执行次数，由三部分组成：
1. 初始化语句 (init-statement)
> int val = 1
2. 循环条件 (condition)
> val <= 10
3. 表达式 (expression)
> ++val

**NOTE**: 
1. 如果循环变量在for循环头中定义，那么该变量是局域变量，不能在循环外使用。
2. 原来使用C或者Java的程序员在转而使用C++之后，会对for循环中使用!=而不是<进行判断有些奇怪。原因和C++的程序员更愿意使用迭代器而非下标的原因一样：因为这种编程风格在标准库提供的所有容器上都有效。只有一部分标准库类型有下标运算符，而且并不是所有容器的迭代器都定义了<>运算符。但是所有标准库容器的迭代器都定义了==和!=。
3. 和其他的声明一样，init-statement也可以定义多个对象，但是init-statement只能有一条声明语句。因此，所有变量的基础类型必须相同


#### 省略 for 语句头的某些部分

for 语句头能省略掉 init-statement、condition 和 expression 中的任何一个(或者全部)。

example:

    //在vector对象中寻找第一个负数
    auto beg = v.begin();
    for ( ; beg != v.end() && *beg >= 0; ++beg)
        ;

注意，分号必须保留以表明我们省略掉了init-statement，是一个空的init-statement

省略condition的效果等价于在条件部分写了一个true。因为条件的值永远是true，所以在循环体内必须有语句负责退出循环。

#### 范围for语句

C++11新标准引入了一种更简单的for语句，这种语句可以遍历容器或其他序列的所有元素


### do while 语句

do while statement 和 while statement 非常相似，唯一的区别是，do while statement 语句先执行循环体后检查条件。不管条件的值如何，都至少执行一次循环。


### 读取数量不定的输入数据

> example: exercise1-16.cpp

核心思想：不断循环，直到没有新的输入为止

**NOTE** 用istream对象作为条件时，其效果时检测流的状态。
         如果流时有效的，那么检测成功，返回true
         如果遇到文件结束符(end-of-file)，或遇到一个无效输入时（例如输入的不是整数），istream的对象的状态就会变为无效。返回false。

**NOTE** 在windows系统中指出文件结束，是输入Ctrl+Z+Enter.
         在UNIX和Mac OS X系统中，输入Ctrl+D


## 分支结构

### if 语句

> example: if_statement.cpp

NOTE: 这个程序有个致命的缺点，就是如果重复的数据是错开的(如：1, 2, 2, 3, 2), 那么程序就会把前后的两组2分开计算，比如(2 times 2, 1 times 1, 1 times 2)

改进过的程序：
> example: if_stm_improved.cpp (未完成)

这种稍微复杂的嵌套需要花一些时间理解了。

### switch语句

example:

    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;
    while (cin >> cn) {
        switch (ch) {
            case 'a':
                ++aCnt;
                break;
            case 'e':
                ++eCnt;
                break;
            case 'i':
                ++iCnt;
                break;
            case 'o':
                ++oCnt;
                break;
            case 'u';
                ++uCnt;
                break;
            default:
                cout << "Error" << endl;
                break;  //虽然这里的break不是必须的，但最好这么做
        }
    }

**NOTE**：
1. case之间如果没有break是可以继承的
2. 即使不准备在default标签下做任何工作，定义一个default标签也是有用的



## 跳转语句

### break 语句

break 语句的作用范围仅限于最近的循环或者switch

### continue 语句

### goto 语句

向后跳过一个已经执行的定义是合法的。跳回到变量定义之前意味着系统将销毁该变量，然后重新创建它。

example:

    begin:
        int sz = get_size();
        if (sz <= 0) {
            goto begin;
        }


**NOTE**：不要使用 goto 语句


## try 语句块和异常处理

### throw 表达式

example:

    Sales_item item1, item2;
    cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn()) {
        cout << item1 + item2 << endl;
        return 0;
    } else {
        throw runtime_error("Data must refer to same ISBN");
    }

类型runtime_error是标准库异常类型的一种，定义在stdexcept头文件中

我们必须初始化runtime_error的对象，方式是给它提供一个string对象或者一个C风格的字符串，这个字符串中有一些关于异常的辅助信息。

### try 语句块

通用语法形式：

    try {
        program-statements              //正常逻辑
    } catch (exception-declaration) {   //异常声明
        handler-statements
    } catch (exception-declaration) {
        handler-statements
    } // ...

try 语句块中的 program-statement 组成程序的正常逻辑，像其他任何块一样，它可以有包括声明在内的C++语句。try语句块内声明的变量在块外部无法访问，在catch中也无法访问。

我们把之前“使用throw表达式以避免把两个代表不同书籍的Sales_item相加”的例子用try-catch重写：

    while (cin >> item1 >> item2) {
        try {
            //执行添加两个Sales_item对象的代码
            //如果添加失败，代码抛出一个runtime_error异常
        } catch (runtime_error err) {   // err的类型是runtime_errod
            cout << err.what()
                << "\nTry Again? Enter y or n" << endl;
            char c;
            cin >> c;
            if (!cin || c == 'n')
                break;  //跳出循环
        }
    }

**NOTE**：
给用户的提示信息中输出了 err.what() 的返回值。err是runtime_error类的一个成员函数。每个标准库异常类都定义了名为what的成员函数，这些函数没有参数，返回值是C风格字符串(即const char*)。其中，runtime_error的what成员返回的是初始化一个具体对象时所用的对象的副本(????)。

#### 函数在寻找处理代码的过程中退出

### 标准异常

C++标准库定义了一组类，用于报告标准库函数遇到的问题。这些异常类也可以在用户编写的程序中使用，它们分别定义在4个头文件中：
1. exception  定义了最通用的异常类exception。只报告异常的发生，不提供任何额外信息。
2. stdexcept  定义了几种常用的异常类。
3. new  定义了bad_alloc异常类型
4. type_info  定义了bad_cast异常类型

标准库的异常类只定义了几种运算，包括创建或拷贝异常类型的对象，以及为异常类型的对象赋值。

我们只能以默认初始化的方式初始化exception、bad_alloc和bad_cast对象，不允许为这些对象提供初始值。其他异常类型的行为则恰好相反。

异常类型只定义了一个名为what的成员函数，该函数没有任何参数，返回值是一个指向C风格字符串的const char*。该字符串的目的是提供关于异常的一些文本信息。

<stdexcept> 定义的异常类
|      class       |                 clarification                  |
| :--------------: | :--------------------------------------------: |
|    exception     |                  最常见的问题                  |
|  runtime_error   |          只有在运行时才能检测出的问题          |
|   range_error    |  运行时错误：生成的结果超出了有意义的值域范围  |
|  overflow_error  |              运行时错误：计算上溢              |
| underflow_error  |              运行时错误：计算下溢              |
|   logic_error    |                  程序逻辑错误                  |
|   domain_error   |        逻辑错误：参数对应的结果值不存在        |
| invalid_argument |               逻辑错误：无效参数               |
|   langth_error   | 逻辑错误：试图创建一个超出该类型最大长度的对象 |
|   out_of_range   |       逻辑错误：使用一个超出有效范围的值       |