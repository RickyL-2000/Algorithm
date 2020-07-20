# 数据结构

从最基本的层面来讲，数据结构就是把一组相关的数据元素组织起来然后使用它们的策略和方法。

## structure

> example: dataStructIntro.cpp

example:

    struct Sales_data {
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    }

类以关键字struct开始，紧跟着类名和类体(类体部分可以为空(??))。类体由花括号包围(**右花括号要有分号分隔，因为类体后面可以紧跟变量名**)形成一个新的作用域。

**另两种写法**：
1. 
    ``` C++
    struct Sales_data { ... } accum, trans, *salesptr;
    ```
2. 
    ``` C++
    struct Sales_data { ... };
    Sales_data accum, trans, *salesptr;
    //与上一种相同，可能更好
    ```

此种类定义的成员，只有数据成员(data member)。类的数据成员定义了类的对象的具体内容，每个对象有自己的一份数据成员拷贝。

C++11新标准规定，可以为数据成员提供一个类内初始值(in-class initializer)。没有初始值的成员被默认初始化(比如bookNo被初始化为空字符串)

## 编写自己的头文件

在函数体内定义类会受到一些限制(?)，所以，类一般都不定义在函数体内。为了确保各个文件中类的定义一致，类通常被定义在头文件中，而且类所在头文件的名字应与类的名字一样。

头文件通常包含那些只能被定义一次的实体，如类、const和constexpr变量。头文件也经常用到其他文件的功能，同时在函数体中引用这些头文件时也需要再一次包含此头文件中包含的头文件

### 头文件保护符

C++还会用到的一项预处理功能是头文件保护符(header guard)，头文件保护符依赖于预处理变量。预处理变量有两种状态：已定义和未定义。

/#define指令把一个名字设定为预处理器变量，另外两个指令则分别检查某个指定的预处理变量是否已经定义：
1. /#ifdef当且仅当变量已定义时为真
2. /#ifndef当且仅当变量未定义时为真
3. 一旦结果为真，则执行后续操作直至遇到#endif指令为止

example:

    #ifndef SALES_DATA_H
    #define SALES_DATA_H
    #include <string>
    struct Sales_data {
        std::string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };
    #endif
    //使用这些功能就能有效地放置重复包含的发生

↑ 第一次包含Sales_data.h时，/#infndef的检查结果为真，预处理器将顺序执行后面的操作直至遇到/#endif为止。此时，预处理变量SALES_DATA_H的值将变为已定义，而且Sales_data.h也会被拷贝到我们的程序中来。后面如果再一次包含Sales_data.h，则#ifndef的检查结果将为假，编译器将忽略/#ifndef到/#endif之间的部分。


## 标准库类型vector

标准库类型vector表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引，索引用于访问对象。所以vector也常被称作容器(container)

vector是一个封装了动态大小数组的顺序容器(sequence container)，是一个能够存放任意类型的动态数组。

vector被包含在头文件<vector>的标准库中，可以用using声明进行简化：
``` C++
    #include <vector>
    using std::vector;
```
C++语言既有类模板(class template)，也有函数模板，其中vector是一个类模板。模板本身不是类或函数，相反可以将模板看作编译器生成类或者函数编写的一份说明。编译器根据模板创建类或者函数的过程称为实例化(instantiation)，当使用模板时，需要指出编译器应把类或者函数实例化成何种类型。

对于类模板来说，需要提供一些额外信息来指定模板到底实例化成什么样的类。提供信息的方式：在模板名字后面跟一对尖括号，在括号内放上信息。example:
``` C++
    vector<int> ivec;              //ivec保存int类型的对象
    vector<Sales_item> Sales_vec;  //保存Sales_item类型的对象
    vector<vector<string>> file;   //该向量的元素是vector对象
```
**NOTE**：
1. 因为引用不是对象，所以不存在包含引用的vector。
2. 早期版本的C++标准中，如果vector的元素还是vector(或者其他模板类型)，则其定义的形式有所不同，必须在外层vector对象的右尖括号和其元素类型之间添加一个空格:
```vector<vector<int> > file;```


### 定义和初始化vector对象

初始化vector对象的方法：
```
    vector<T> v1;                       //空vector，它潜在的元素是T类型的，执行默认初始化
    vector<T> v2(v1);                   //v2中包含有v1所有元素的副本
    vector<T> v2 = v1;                  //同上
    vector<T> v3(n, val);               //包含了n个重复的元素，每个元素的值都是val
    vector<T> v4(n);                    //包含了n个重复地执行了*值初始化的*对象
    vector<T> v5{a, b, c...}            //列表初始化，包含了初始值个数的元素，每个元素被赋予相应的初始值
    vector<T> v5 = {a, b, c...}         //同上
```
**NOTE**：
1. 拷贝vector对象的时候其类型必须相同
2. 在大多数情况下C++提供的几种初始化方式可以相互等价地使用，不过并非一直如此。几种特殊情况：
   1. 使用拷贝初始化时(即使用=时)，只能提供一个初始值
   2. 如果提供的是一个类内初始值，则只能使用拷贝初始化或使用花括号形式的初始化(?)
   3. 如果提供的是初始元素值的列表，只能把初始值都放在花括号里进行列表初始化，而不能放在圆括号里
3. 通常情况下，可以只提供vector对象容纳的元素数量而不用略去初始值。此时库会创建一个值初始化的(value-initialized)元素初值，并把它赋给所有元素。这个初值由vector对象中元素的类型决定。比如，若vector对象的元素是内置类型，比如int，则元素初始值自动设为0。如果是某种类类型，比如string，则元素由类默认初始化(比如空string对象)。对这种初始化的方式有两个特殊限制：
   1. 有些类要求明确地提供初始值。对这种类型的对象来说，只提供元素的数量而不设定初始值无法完成初始化工作
   2. 如果只提供了元素的数量而没有设定初始值，只能使用直接初始化。
   
        vector<int> ivec(10);     //10个元素，每个都初始化为0
        vector<string> svec(10);  //空string对象
        vector<int> vi = 10;      
        /*错误，必须使用直接初始化的形式指定向量大小。因为我们的本意是想创建含有10个值初始化了的元素的vector对象，而非把数字10“拷贝”到vector中。所以不应该用拷贝初始化


### vector操作

> example: score.cpp  用于计算每个分数段的人数(很像python中的dict计数)

|    operation    |         meaning          |
| :-------------: | :----------------------: |
|    v.empty()    |         返回真假         |
|    v.size()     |         返回个数         |
|      v[n]       |  返回n位置上元素的引用   |
|     v1 = v2     |         拷贝替换         |
| v1 = {a,b,c...} |         拷贝替换         |
|    v1 == v2     |         完全相同         |
|    v1 != v2     |           不同           |
|  <. <=, >, >=   |    以字典顺序进行比较    |
| v.push_back(t)  |     在尾端添加一个t      |
|  v.pop_back()   | 删除最后一个元素（无返） |
|    v.back()     |     返回最后一个元素     |
|    v.clear()    |       删除所有元素       |


* 添加元素 push_back

对于一些vector内元素繁多且各不相同、直到运行时才能知道vector对象中元素的确切个数的情况，最好的方法是一开始声明一个空vector，然后依次往里添加元素。

example:
    
    string word;
    vector<string> text;     // 空vector对象
    while (cin >> word) {
        text.push_back (word);
    }

**NOTE**：
1. 既然vector对象能够高效地增长，那么在定义vector对象的时候设定其大小就没什么必要了，事实上这么做可能性能更差。
2. **不能用下标形式添加元素！**对于下面这个例子，ivec是一个空vector，根本不包含任何元素，当然也就不能通过下标去访问任何元素！正确的做法是用push_back。

        vector<int> ivec;
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
            ivec[ix] = ix;  //严重错误
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
            ivec.push_back(ix);   //正确


* size()和empty()
  
功能与string的成员函数完全一致。size()返回vector对象中元素的个数，返回值的类型是由vector定义的size_type类型

**NOTE**：要使用size_type，需要首先指定它是由哪种类型定义的。

    vector<int>::size_type    //正确
    vector::size_type         //错误


* 下标操作[]

**NOTE**：
1. **不能用下标形式添加元素！**对于下面这个例子，ivec是一个空vector，根本不包含任何元素，当然也就不能通过下标去访问任何元素！正确的做法是用push_back。

        vector<int> ivec;
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix) //(感觉用int ix也没错？
            ivec[ix] = ix;  //严重错误
        for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
            ivec.push_back(ix);   //正确
2. 只能对确定已存在的元素执行下标操作。试图用下标的形式去访问一个不存在的元素将引发错误，不过这种错误不会被编译器发现，而是在运行时产生一个不可预知的值。所谓缓冲区溢出(buffer overflow)指的就是这类错误。
3. 标准库类型限定使用的下标必须是无符号类型。


### 迭代器iterator

所有标准库容器都可以使用迭代器，但是其中只有少数几种才同时支持下标运算符。

和指针不一样的是，获取迭代器不是使用取地址符，有迭代器的类型同时拥有返回迭代器的成员。比如，这些类型都拥有名为begin和end的成员。

begin()成员负责返回指向第一个元素的迭代器，end()成员则负责返回指向容器"尾元素的下一位置(one past the end)"的迭代器，也就是说，该迭代器指示的是容器的一个本不存在的"尾后(off the end)"元素。这样的迭代器没什么实际含义，仅是个标记而已，表示我们已经处理完了容器中的所有元素。

**NOTE**：
1. 如果容器为空，begin和end返回的是同一个迭代器，都是尾后迭代器。
2. C++貌似并不关心迭代器的类型，只需要在iter前面注明auto就可以了。但是iter可以递增或者递减，说明有整数的性质。

example:

    auto b = v.begin(), e = v.end();
    //由编译器决定b和e的类型


#### 迭代器运算符

|    operator    |                         meaning                          |
| :------------: | :------------------------------------------------------: |
|     *iter      |               返回迭代器iter所指元素的引用               |
|   iter->mem    | 解引用iter并获取该元素的名为mem的成员，等价于(*iter).mem |
|     ++iter     |                      指向下一个元素                      |
|     --iter     |                      指向上一个元素                      |
| iter1 == iter2 |                           相等                           |
| iter1 != iter2 |                           不等                           |

example: 利用迭代器把string对象的第一个字母改为了大写形式

    string s("some string");
    if (s.begin() != s.end()) {   //确保s非空
        auto it = s.begin();
        *it = toupper(*it);
    }

example: 利用迭代器和递增运算符把string对象的第一个字母改为了大写形式

    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it);

* begin()和end()运算符

begin和end返回的具体类型由对象是否是常量决定，如果对象是常量，begin和end返回const_iterator，否则是iterator。然而，为了便于专门得到const_iterator类型的返回值，C++11新标准引入了两个新函数：cbegin()和cend()。example:

    auto it3 = v.cbegin(); // it3的类型是vector<int>::const_iterator

* 结合解引用和成员访问操作 箭头运算符

如果解引用迭代器所指的对象恰好是类，就有可能进一步访问它的成员。为了简化这一表达式，C++定义了箭头运算符(->)，example:
    
    *it.empty()    //错误，试图访问it的名为empty的成员，但是it是一个迭代器没有成员
    (*it).empty()  //解引用it，然后调用结果对象的empty成员
    it -> empty()  //与上式相同

    //依次输出text的每一行直至遇到第一个空白为止
    for (auto it = text.cbegin(); it != text.cend() && ！it->empty(); ++it)
        cout << *it << endl;


#### 迭代器类型

一般来说我们无需知道迭代器的精确类型(就像string和vector的size_type成员一样)。而实际上，那些拥有迭代器的标准库类型使用iterator和const_iterator来表示迭代器的类型：

    vector<int>::iterator it;  // it能读写vector<int>的元素
    string::iterator it2;      // it2能读写string对象中的字符
    
    vector<int>::const_iterator it3;  // it3只能读取但不能修改它所指的元素值
    string::const_iterator it4;       // it4只能读取但不能修改它所指的元素值


#### 迭代器的限制

1. 不能在范围for循环中向vector对象添加元素。
2. 任何一种改变vector对象容量的操作，都会使vector对象的迭代器失效。
   

**NOTE**：但凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素。


#### 使用迭代器运算

**vector和string迭代器支持的运算**
|   operation   |             meaning              |
| :-----------: | :------------------------------: |
|   iter + n    |      指向容器内的某一个元素      |
|   iter - n    |               同上               |
|  iter1 += n   |     迭代器加法的复合赋值语句     |
|  iter1 -= n   |     迭代器减法的复合赋值语句     |
| iter1 - iter2 | 同一个容器中两个迭代器之间的距离 |
|   <,<=,>,>=   |        迭代器的关系运算符        |

**NOTE**：注意！两个迭代器不能相加！


使用迭代器运算的一个经典算法是二分搜索。example:

    // text必须有序
    // beg和end表示我们搜索的范围
    auto beg = text.begin(), end = text.end();
    auto mid = text.begin() + (end - beg)/2; //因为迭代器没有加法，所以不能(end+beg)/2
    while (mid != end && *mid != sought) {
        if (sought < *mid)
            end = mid;
        else
            beg = mid + 1;
        mid = beg + (end - beg)/2;
    }



## 数组

数组也是存放类型相同的对象的容器，这些对象本身没有名字，需要通过其所在位置访问。数组的大小确定不变，不能随意向数组中增加元素。

### 定义和初始化内置数组

数组中元素的个数也属于数组类型的一部分，编译的时候维度应该是已知的。也就是说，维度必须是一个常量表达式。example:

    unsigned cnt = 42;            //非常量表达式
    constexpr unsigned sz = 42;   //常量表达式
    int arr[10];                  //含有10个整数的数组(此时数组内元素的值是不确定的)
    int *parr[sz];                //含有42个整型指针的数组
    string bad[cnt];              //错误
    string strs[get_size()];      //当get_size是constexpr时正确(?)

    //显式初始化数组元素
    const unsigned sz = 3;
    int ia1[sz] = {0, 1, 2};
    int a2[] = {0, 1, 2};
    int a3[5] = {0, 1, 2};
    string a4[3] = {"hi", "bye"};  //等价于 a4[] = {"hi", "bye", ""}
    int a5[2] = {0, 1, 2};

**NOTE**：不允许拷贝与赋值！
1. 不能将数组的内容拷贝给其他数组作为其初始值，也不能用数组为其他数组赋值：

    int a[] = {0, 1, 2};
    int a2[] = a;        //错误：不能拷贝初始化
    a2 = a;              //错误：不能赋值

2. 一些编译器支持数组的赋值，这就是所谓的编译器扩展(compiler extension)，但一般来说，最好避免使用非标准特性。


#### 字符数组的特殊性

字符数组有一种额外的初始化形式，我们可以用字符串字面值对此类数组初始化。

    char a1[] = {'C', '+', '+'};        //列表初始化，没有空字符，维度是3
    char a2[] = {'C', '+', '+', '\0'};  //列表初始化，含有显式的空字符，维度是4
    char a3[] = "C++";                  //自动添加表示字符串结束的空字符
    const char a4[6] = "Daniel";        //错误，溢出

#### 复杂的数组声明与指针

数组能存放大多数类型的对象。例如，可以定义一个存放指针的数组，又因为数组本身就是对象，所以允许定义数组的指针及数组的引用。example:

    int *ptrs[10];
    int &refs[10] = /* ? */;   //错误，不存在引用的数组
    int (*Parray)[10] = &arr;  //Parray指向一个含有10个整数的数组
    int (&arrRef)[10] = arr;   //arrRef引用一个含有10个整数的数组

**一般来说，类型修饰符从右向左依次绑定。**
对于ptrs来说，从右向左理解含义比较简单：首先定义了一个大小为10的数组，它的名字是ptrs，然后知道数组中存放的是指向int的指针。
**但是对于Parray来说，从右向左理解就不太合理了。**因为数组的维度是紧跟着被声明的名字的，所以就数组而言，由内向外阅读要比从右向左好多了：首先是圆括号里面的部分，*Parray意味着Parray是个指针，接下来观察右边，可知道Parray是个指向大小为10的数组的指针，最后知道数组中的元素是int。

当然，对修饰符的数量并没有特殊限制：

    int *(&array) [10] = ptrs;  //对数组的引用，该数组含有10个指针
    //首先知道array是个引用
    //右边：array引用的对象是一个大小为10的数组
    //数组的元素类型是指向int的指针

**NOTE**：要想理解数组声明的含义，最好的办法是从数组的名字开始按照由内向外的顺序阅读


### 访问数组元素

与标准库类型vector和string一样，数组的元素也能使用范围for语句或下标运算符来访问。

example:

    //下标运算符
    unsigned scores[11] = {};  //11个固定的分数段，全部初始化为0
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100)
            ++scores[grade/10];
    }

    //范围for语句
    for (auto i : scores)
        std::cout << i << ' ';
    std::cout << std::endl;

#### 下标类型

在使用数组下标的时候，通常将其定义为 size_t 类型，一种机器相关的无符号类型，被设计得足够大以便能表示内存中任意对象的大小。**这个类型定义在cstddef头文件中，这个文件是C标准库stddef.h头文件的C++语言版本。

数组除了大小固定这一特点外，其他用法与vector基本类似。vector可以拷贝赋值但是数组不可以。另外一处不太明显的区别是，数组的下标运算符是C++语言直接定义的，这个运算符能用在数组类型的运算对象上，但是vector上的下标运算符是库模板vector定义的，只能用于vector类型的运算对象。

**NOTE**：要注意下标越界的问题，大多数常见的安全问题都源于缓冲区溢出错误。


### 使用for语句处理(修改)数组

这个有可能涉及到多维数组，所以笔记在之后的多维数组中


### 指针和数组

在大多数表达式中，编译器会自动将数组的名字替换为一个指向数组首元素的指针。

这一结论有很多隐含的意思。其中一层意思是当使用数组作为一个auto变量的初始值时，推断得到的类型是指针而非数组。而必须指出的是，**当使用decltype关键字时上述转换不会发生：**

    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    auto ia2(ia);                //ia2是一个整型指针，指向ia的第一个元素（不是拷贝！！！！）
    decltype(ia) ia3 = {0,1,2};  //ia3是一个含有10个整数的数组


#### 指针也是迭代器

获取数组尾元素之后的那个并不存在的元素的地址：

    int* e = &arr[10];

这个不存在的元素的唯一的用处就是提供其地址用于初始化e。就像尾后迭代器一样，尾后指针也不指向具体的元素。因此，不能对尾后指针执行解引用或递增的操作。

example:

    int* e = &arr[10];
    for (int* b = arr; b != e; ++b)
        std::cout << *b << endl;

##### 标准库函数begin()和end()

尽管能计算得到尾后指针，但这种用法极易出错。C++11新标准引入了两个名为begin和end的函数，与容器中的两个同名函数同能类似。

不过数组比较不是类类型，因此这两个函数不是成员函数。正确的使用形式是将数组作为它们的参数(而不是作为成员)：

    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    int* beg = begin(ia);
    int* last = end(ia);

    while (beg != last) {
        std::cout << *beg << std::endl;
        ++beg;
    }

#### 指针的运算

指针使用于vector迭代器的所有运算(指针也不能相加！)

下标和指针本质上是一致的。

**NOTE**：虽然标准库类型string和vector也能执行下标运算，但是数组与它们想必还是有所不同。标准库类型限定使用的下标必须是无符号类型，而内置的下标运算无此要求:

    int ia[] = {0,2,4,6,8};
    int* p = ia;

    int i = ia[2];
        i = *(p + 2);  //这两句本质上是一样的

    int* p = &ia[2];
    int j = p[1];      //此时p[1]等价于ia[3]
    int k = p[-2];     //表示ia[0]。数组的内置的下标运算可以是负数，只要不溢出(不过vector好像很难搞出这种操作？)

### 多维数组

example:

    int ia[3][4];
    int arr[10][20][30] = {0};  //将所有元素初始化为0
    int ia[3][4] = {
        {0,1,2,3},
        {4,5,6,7},
        {8,9,10,11}
    };
    int ia[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11}; //与上一条等价
    int ia[3][4] = {{0},{4},{8}};  //只显式地初始化每行的首元素

    ia[2][3] = arr[0][0][0];
    int (&row)[4] = ia[1];  //把row绑定到ia的第二个4元素数组上


#### 使用范围for语句处理(修改)多维数组

因为要改变数组元素的值，所以我们选用引用类型作为循环控制变量(貌似C语言中不需要？)：

    size_t cnt = 0;
    for (auto &row : ia)
        for (auto &col : row) {  //要改变数组元素的值，选用引用类型
            col = cnt;
            ++cnt;
        }

但是其实还有一个深层次的原因促使我们这么做，example:

    for (const auto &row : ia)
        for (auto col : row)
            cout << col << endl;

↑这个循环中没有任何写操作，但还是将外层循环的控制不了声明成了引用类型，这是为了避免数组被自动转成指针。假设不用引用，example:

    for (auto row : ia)
        for (auto col : row)

**程序将无法通过编译。**因为row不是引用，所以编译器初始化row时会自动将这些数组形式的元素(和其他类型的数组一样)转换成指向该数组内首元素的指针。这样得到的row的类型就是int*，显然内层的循环就不合法了

**NOTE**：要使用for语句处理多维数组，除了最内层的循环外，其他所有循环的控制变量都应该是引用类型


#### 指针和多维数组

因为多维数组实际上是数组的数组，所以由多维数组名转换得来的指针实际上是指向第一个内层数组的指针

example:

    int* ip[4];    //整型指针的数组
    int* (*ip)[4]; //指向含有4个整数的数组

在C++11新标准中，通过使用auto或者decltype就能尽可能地避免在数组前面加上一个指针类型了：

    int ia[3][4] = {};
    for (auto p = ia; p != ia + 3; ++p) {
        for (auto q = *p; q != *p + 4; ++q)  //q一开始指向内层数组的第一个元素
            cout << *q << ' ';
        cout << endl;
    }

当然，使用标准库函数begin和end也能实现同样的功能：

    for (auto p = begin(ia); p != end(ia); ++p) {
        for (auto q = begin(*p); q != end(*p); ++q)
            cout << *q << ' ';
        cout << endl;
    }

##### 类型别名简化多维数组的指针 (??????)

读、写和理解一个指向多维数组的指针是很繁琐的，使用类型别名能让这项工作变得简单一点，example:

    using int_array = int[4];
    typedef int int_array[4];
    for (int_array *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    /* 将类型“4个整数组成的数组”命名为int_array，用类型名int_array定义外层循环的控制变量


## algorithm

C++ 中这些数据结构全部有标准模板库，存放在头文件<algorithm>中

### heap

Heap data structure can be implemented in a range using STL which allows faster input into heap and retrieval of a number always results in the largest number i.e. largest number of the remaining numbers is popped out each time. Other numbers of the heap are arranged depending upon the implementation.

### heap 操作

1. make_heap()  
   used to convert a range (iterator) in a container to a heap (in situ exchange)
   **NOTE**: excluding upper limit, i.e. make_heap[ v1.begin(), v1.end() )

        vector<int> v1 = {20, 30, 40, 25, 15};
        make_heap(v1.begin(), v1.end());

2. front()
   displays the first element of heap which is the maximum number

        root = v1.front();

3. push_heap()
   insert elements into heap. New element is placed appropriately in the heap. (used to reorder elements)
   (it's much like make_heap())

        v1.push_back(50);
        push_heap(v1.begin(), v1.end());

4. pop_heap()
   used to delete the maximum element of the heap. The heap elements are reorganised accordingly after this operation. The deleted element will be placed in the back of vector.

        pop_heap(v1.begin(), v1.end());
        v1.pop_back();

5. sort_heap()
   used to sort the heap. After this operation, the container is **no longer a heap.** (from small to large)

        sort_heap(v1.begin(), v1.end());

6. is_heap()
   used to check whether the container is heap or not. Generally, in most implementations, the **reverse sorted container** is considered as heap.

    while (is_heap(v1.begin(), v1.end())) {/*...*/}

7. is_heap_until()
   returns the iterator to the position till the container is the heap. 

        auto it = is_heap_until(v1.begin(), v1.end());
        // this *it is not included in the heap