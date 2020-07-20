# 变量和基本类型

"一些语言，如Smalltalk和Python，在程序运行时检查数据类型；与之相反，C++是一种静态数据类型语言，它的类型检查发生在编译时。"
"C++语言主要的一个设计目标就是让程序员自定义的数据类型像内置类型一样好用。"

## 基本内置类型

C++定义了一套包括算术类型(arithmetic type)和空类型(void)在内的基本数据类型。
**NOTE** 空类型不对应具体的值，仅用于一些特殊的场合，例如最常见的是，当函数不返回任何值时使用空类型作为返回类型。

### 2.1.1 算术类型

|    type     |      name      |    space     |
| :---------: | :------------: | :----------: |
|    bool     |      布尔      |      无      |
|    char     |      字符      |    8位bit    |
|   wchar_t   |     宽字符     |     16位     |
|  charl16_t  |  Unicode 字符  |     16位     |
|  charl32_t  |  Unicode 字符  |     32位     |
|    short    |     短整型     |     16位     |
|     int     |      整型      |     16位     |
|    long     |     长整型     |     32位     |
|  long long  |     长整型     |     64位     |
|    float    |  单精度浮点数  | 6位有效数字  |
|   double    |  双精度浮点数  | 10位有效数字 |
| long double | 扩展精度浮点数 | 10位有效数字 |

**NOTE**：在markdown中，|:---:|是用来描述对齐的。

**NOTE**：
1. 使用int进行整数运算。在实际应用中，short常常显得太小而long一般和int有一样的尺寸(?)。如果数值超过了int的表示范围，使用longlong。
2. 在算术表达式中不要使用char或bool。
3. 如果需要使用一个不大的整数，那么明确指定它的类型是signed char或unsigned char。
4. 执行浮点数运算选用double。因为float通常精度不够而且float和double的计算代价相差无几(?)。事实上，对于某些机器来说，双精度运算甚至比单精度还快。long double一般没有必要，而且消耗不容忽视。

### 类型转换

> example: exercise2-3.cpp (!)

1. 非布尔 --> 布尔：初始为0则false，否则true
2. 布尔 --> 非布尔：初始值false则0，初始值true则1
3. 浮点数 --> 整数：保留小数点前部分
4. 整数 --> 浮点数：小数部分为0。若整数空间超过浮点类型的容量，精度可能损失
5. 赋给无符号类型一个超出范围的值时，结果是初始值对无符号类型表示数值总数取模后的余数。(溢出)
   
   example: 
   
        unsigned char c = -1; //假设char占8bit，c的值为255
6. 当赋给signed char一个超出它表示范围的值时，结果时未定义的(undefined)。此时，程序可能继续工作，可能崩溃，也可能生成垃圾数据。

example: 
1.  
        
    for (unsigned u = 10; u >= 0; --u)
    std::cout << u << std::endl;
    //这样会陷入死循环，但是可以用while，因为它可以在输出变量之前(而非之后)先减去1：
2. 
   
    unsigned u = 11;
    while (u > 0){
        --u;
        std::cout << u << std::endl;
    }

### 字面值常量 (literal)

**NOTE**： 以O开头的整数代表八进制数，以0x或者0X开头的代表十六进制数。

**NOTE**： 编译器在每个字符串的结尾处添加一个空字符"\0"，因此，字符串字面值的实际长度要比它的内容多1。

如果两个字符串字面值位置紧邻且仅由空格、缩进和换行符分隔，则它们实际上是一个整体。

**NOTE**： 当书写的字符串字面值比较长，写在一行里不太合适时，就可以采取分开书写的方式：
example: 
        
        std::cout << "a"
                     "b";
        //输出ab

#### 转义序列 (???)

|     名称     | 符号  |
| :----------: | :---: |
|    换行符    |  \n   |
|  纵向制表符  |  \v   |
|  横向制表符  |  \t   |
|    反斜线    |  \\   |
|    回车符    |  \r   |
|    退格符    |  \b   |
|     问号     |  \?   |
|    进纸符    |  \f   |
| 报警(响铃)符 |  \a   |
|    双引号    |  \"   |
|    单引号    |  \'   |

#### 指定字面值的类型 (???)

**NOTE**： 当使用一个长整型字面值时，最好使用L来标记，因为l和数字1太容易混淆了。

字符和字符串字面值
| 前缀  |   类型   |
| :---: | :------: |
|   u   | char16_t |
|   U   | char32_t |
|   L   | wchar_t  |
|  u8   |   char   |

整型字面值
|   后缀   | 最小匹配类型 |
| :------: | :----------: |
|  u or U  |   unsigned   |
|  l or L  |     long     |
| ll or LL |  long long   |

浮点型字面值
|  后缀  |    类型     |
| :----: | :---------: |
| f or F |    float    |
| l or L | long double |

## 变量

### 变量定义

首先**类型说明符**，随后一个或多个变量名列表，以逗号分隔，以分号结束。

**库类型std::string**
example: 
        
        std::string book("0-201-78345-X");
string是一种表示可边长字符序列的数据类型。

当对象在创建时获得了一个特定的值，我们说这个对象被初始化了(initialized)
**NOTE**: "事实上在C++语言中，初始化和赋值时两个完全不同的操作。"
          初始化的含义时创建变量时赋予其一个初始值，而赋值的含义时把对象的当前值擦除，用一个新值来替代。

#### 默认初始化

如果定义变量时没有指定初始值，则变量被初始化，被赋予了"默认值"。
如果时内置类型的变量未被显式初始化。它的值由定义的位置决定。定义于任何函数体之外的变量被初始化为0.
**NOTE**： 定义在函数体内部的内置类型将不被初始化。一个未被初始化的内置类型变量的值是未定义的，若试图拷贝或者以其他形式访问此类值将引发错误。

### 变量声明和定义的关系

为了支持分离式编译，C++将声明和定义区分开来

**声明**适得名字为程序所知，一个文件如果想使用别处定义的名字则必须包含对那个名字的声明。
而**定义**负责创建与名字关联的实体。

> example： 声明：

    extern int i; //声明i而非定义i
    int j;        //声明并定义j

**NOTE**： 变量能且只能被定义一次，但是可以被多次声明。 (????)
           如果要在多个文件中使用同一个变量，就必须将声明和定义分离。此时，变量的定义必须出现在且只能出现在一个文件中，而其他用到该变量的文件必须对其进行声明，却绝对不能重复定义。

### 标识符

标识符由字母、数字、下划线组成，必须以字母或下划线开头，不能连续出现两个下划线，不能下划线紧连大写字母开头。定义在函数体外的标识符不能以下划线开头。

**NOTE**： 变量名一般用小写字母，类名以大写字母开头。同一种命名规则最好坚持使用。

### 名字的作用域 (scope)

1. 全局作用域(global scope)。定义在函数体外的名字拥有(如main)，在整个程序的范围内都可以使用。
2. 块作用域(block scope)。定义在函数(如main)或语句(如for)内，出了这个块就无法访问了。
   
**NOTE** 一般来说，在对象第一次被使用的地方附近定义它是一种好的选择，因为这样有助于找到它的定义。

#### 嵌套的作用域

内层作用域，外层作用域。允许在内层作用域中重新定义外层作用域已有的名字。

**NOTE**当内层变量名字与外层相同时，内层被覆盖。想访问外层变量时，可以用**作用域操作符**来覆盖默认的作用域规则，因为全局作用域本身并没有名字，座椅当作用域操作符的左侧为空时，向全局作用域发出请求获取作用域操作符右侧名字对应的变量。


### 静态变量

static 关键字

1. A static variable inside a function keeps its value between invocations.
2. A static global variable or a function is "seen" only in the file it's declared in

**NOTE**: Beware, however, this feature should be used very sparingly - it makes your code not thread-safe and harder to understand.

static 的第二层意思和前面的含义相关，即“在某个作用域外不可访问”。当static应用于函数名和所有函数外部的变量时，它的意思是“在文件的外部不可以使用这个名字”。例如，编译和连接下面两个文件会引起连接器错误：

    //: C03:FileStatic.cpp
    // File scope demonstration. Compiling and linking this file with 
    // FileStatic2.cpp
    // will cause a linker error

    // File scope means only  available in this file:
    
    static int fs;

    int main() {
        fs = 1;
    } ///:~

尽管在下面的文件中变量fs被声明为extern，但是连接器不会找到它，因为在FileStatic.cpp中它被声明为static

    //：C03:FileStatic2.cpp {O}
    // Trying to reference fs
    extern int fs;
    void func() {
        fs = 100;
    }


## 复合类型

### 引用 (???)

引用(reference)为对象起了另外一个名字，引用类型引用(refers to)另外一种类型。通过将声明符写成&d的形式来定于引用类型，其中d是声明的变量名:
example: 

    int ival = 1024;
    int &refVal = ival; // refVal 指向 ival (是ival的另一个名字)
    int &refVal2; //报错：引用必须被初始化

**NOTE**： 定义引用时，程序把引用和它的初始值绑定(bind)在一起，而不是将初始值拷贝给引用。一旦初始化完成，引用将和它的初始值对象一直绑定在一起。因为无法令引用重新绑定到另外一个对象，因此引用必须初始化。

**NOTE**： **引用即别名。**

**NOTE**：关于引用和指针：
1. A pointer can be re-assigned any number of times while a reference cannot be reassigned after binfing. 
2. Pointers can point nowhere (NULL), whereas a reference always refers to an abject. 
3. You can't take the address of a reference like you can with pointers.
4. There's no "reference arithmetic" (but you can take the address of an object pointed by a reference and do pointer arithmetic on it as in &obj+5).
5. A pointer and a reference both use the same amount of memory.


### 指针

> example: exercise2_18.cpp

指针(pointer)是“指向另一种类型的符合类型。
1. 指针本身就是一个对象，允许对指针赋值和拷贝，而且在指针的生命周期内它可以先后指向几个不同的对象。
2. 指针无需在定义时赋初值。
   
定义指针类型的方法将声明符写成*d的形式，其中d是变量名。
example: 

    int *ip1, *ip2;  //ip1和ip2都是指向int型对象的指针
    double dp, *dp2;  //dp2是指向double型对象的指针，dp是double型对象


指针存放某个对象的地址，要想获取该地址，需要使用**取地址符(&)**
example: 

    int ival = 42;
    int *p = &ival; //p存放ival的地址，或者p是指向ival的指针

**NOTE**： 因为在声明语句中指针的类型实际上被用于指定它所指向对象的类型，所以二者必须匹配。

指针的值：
1. 指向一个对象
2. 指向紧邻对象所占空间的下一个位置(?)
3. 空指针(null pointer)，没有任何对象
4. 无效指针
   
**NOTE**： 访问无效指针的值会引发错误。试图访问2、3型指针(假定的)对象的行为也不被允许

如果指针指向了一个对象，则允许使用**解引用符(操作符)**来访问该对象
example: 
         
        int ival = 42;
        int *p &ival;
        cout << *p;

如果给解引用的结果赋值，实际上也就是给指针所指的对象赋值
example: 

        *p = 0;
        cout << *p; //输出0

生成空指针(null pointer)

    int *p1 = nullptr;        //最直接的方法，也是最建议的方法
    int *p2 = 0;
    //需要先#include cstdlib
    int *p3 = NULL;

**NOTE**： 使用未经初始化的指针式引发运行时错误的一大原因。所以建议初始化所有指针，并且在可能的情况下，尽量等定义了对象后再定义指向它的指针。如果实在不清楚指针一个指向何处，就把它初始化为nullptr或者0。

#### void*指针

void*是一种特殊的指针类型，可用于存放任意对象的地址。然而，我们对该地址中到底是个什么类型的对象并不了解。
example: 

    double obj = 3.14, *pd = &obj;
    void *pv = &obj;                //obj可以是任意类型的对象
    pv = pd;                        //pv可以存放任意类型的指针

void指针的功能：拿它和别的指针比较、作为函数的输入或输出，或者赋给另一个void指针 (?)

### 2.3.3 理解符合类型的声明

指向指针的指针：**表示指向指针的指针，
              ***表示指向指针的指针的指针，以此类推
example:
int ival = 1024;
int *pi = &ival;
int **ppi = & pi;

存在对指针的引用

## const 限定符

example:
    
    const int bufSize = 512;

const对象一旦创建后其值就不能再改变

**NOTE**：默认状态下，const对象仅在文件内有效

### 2.4.1 const的引用

### 2.4.2 指针和const

### 2.4.3 顶层const

### 2.4.4 constexpr和常量表达式

常量表达式(const expression)是指不会改变并且在编译过程就能得到计算结果的表达式。

#### constexpr变量

在一个复杂系统中，很难(几乎肯定不能)分辨一个初始值到底是不是常量表达式。

C++11新标准规定，允许将变量声明为constexpr类型以便由编译器来验证变量的值是否是一个常量表达式。声明为constexpr的变量一定是一个常量，而且必须用常量表达式初始化：

    constexpr int mf = 20;
    constexpr int limit = mf + 1;
    constexpr int sz = size();     //只有当size是一个constexpr函数时才是正确的

**NOTE**：一般来说，如果你认定变量是一个常量表达式，那就把它声明成constexpr类型。

#### 字面值类型

常量表达式的值需要在编译时就得到计算，因此对声明constexpr时用到的类型必须有所限制。因为这些类型一般比较简单，就被称为“字面值类型”(literal type)

算术类型、引用和指针都属于字面值类型。自定义类、IO库、string类型则不属于字面值类型，也就不能被定义成constexpr。

尽管指针和引用都能定义成constexpr，但它们的初始值却受到严格限制。一个constexpr指针的初始值必须是nullptr或0，或存储于某个固定地址中的对象。

**NOTE**：在constexpr声明中如果定义了一个指针，限定符constexpr仅对指针有效，与指针所指的对象无关：

    const int *p = nullptr;      //p是一个指向整型常量的指针
    constexpr int *q = nullptr;  //q是一个指向整数的常量指针

## 2.5 处理类型

### 2.5.1 类型别名

### 2.5.2 auto类型说明符

### 2.5.3 decltype类型指示符






## 标准库类型string

使用string类型必须首先包含string头文件。作为标准库的一部分，string定义在命名空间std中。
example:

    #include <string>
    using std::string;

### 命名空间的using声明

有了using声明就无须专门的前缀(形容命名空间::)也能使用所需的名字了。用了using的语句，就可以直接访问命名空间中的名字:
example: 
    
    #include <iostream>
    using std::cin;
    int main()
    {
        int i;
        cin >> i;         //正确
        cout << i;        //错误
        std::cout << i;   //正确
        return 0;
    }

每个名字都需要独立的using声明，而**头文件不应包含using声明**


### 定义和初始化string对象

example:

    string s1;           //空字符串(不需要初始化字符数组的大小，这一点和C不一样)
    string s2 = s1;      //s2是s1的副本(拷贝初始化)
    string s2(s1);       //等价于上(直接初始化)
    string s3 = "hiya";  //s3是该字符串字面值的副本
    string s3("hiya");   //等价于上
    string s4(10,'c');   //cccccccccc

### string对象上的操作

string的操作
|    operation     |                   意义                    |
| :--------------: | :---------------------------------------: |
|     os << s      |       将s写到输出流os中，返回os(?)        |
|     is >> s      | 从is中读取字符串赋给s，以空白分隔，返回is |
|  getline(is, s)  |     从is中读取一行赋给s，返回is的状态     |
|    s.empty()     |       s为空返回true，否则返回false        |
|     s.size()     |             返回s中字符的个数             |
|       s[n]       |       返回s中第n个字符的引用，从0起       |
|      s1+s2       |          返回s1和s2连接后的结果           |
|      s1=s2       |       用s2的副本代替s1中原来的字符        |
|      s1==s2      |                   相等                    |
|      s1!=s2      |                  不相等                   |
|   <, <=, >, >=   |                  不等号                   |
| s.substr(pos, n) |      返回从pos位置开始n个字符的子串       |
|    s.c_str()     |        返回C格式的字符数组的字符串        |
(以上的is,os分别是istream和ostream的缩写)

**NOTE**:
1. 在用scanf()等函数读取字符串的内容时，需要用.c_str()函数

> example: exercise_getline.cpp


#### string::size_type类型

size()函数返回的是一个string::size_type类型的值

在C++11新标准中，允许编译器通过auto或者decltype来推断变量的类型。example:

    auto len = line.size();  //len的类型是string::size_type

**NOTE**：如果一条表达式中已经有了size()函数就不要再使用int了，这样可以避免混用int和unsigned可能带来的问题。例如，假设n是一个具有负值的int，则表达式s.size() < n的判断结果几乎肯定是true，因为负值n会自动地转换成一个比较大的无符号值。所以在用index遍历string(或者vector)的时候，尽量用size_t i定义

### 处理string对象中的字符

cctype头文件：在C语言中，cctype头文件就是ctype.h头文件，只不过在C++中去掉了.h的后缀并在前面加上了c的前缀

cctype头文件中的函数
|  function   |                        meaning                        |
| :---------: | :---------------------------------------------------: |
| isalnum(c)  |                 当c是字母或数字时为真                 |
| isalpha(c)  |                    当c是字母时为真                    |
| iscntrl(c)  |                  当c是控制字符时为真                  |
| isdigit(c)  |                    当c是数字时为真                    |
| isxdigit(c) |                当c是十六进制数字时为真                |
| isgraph(c)  |               当c不是空格但可打印时为真               |
| islower(c)  |                  当c是小写字母时为真                  |
| isupper(c)  |                  当c是大写字母式为真                  |
| isprint(c)  |     当c是可打印字符时为真(c是空格或c具有可视形式)     |
| ispunct(c)  |                  当c是标点符号时为真                  |
| isspace(c)  | 空白时真(空格、横/纵向制表符、回车符、换行符、进纸符) |
| tolower(c)  |                  输出对应的小写字母                   |
| toupper(c)  |                  输出对应的大写字母                   |

#### 基于范围的for语句

可以用for语句遍历给定序列(比如string)中的每一个元素 (貌似C里面不能这么写)

example:

    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    //punct_cnt的类型和s.size的返回类型一样
    for (auto c : s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << endl;

#### **使用范围for语句改变字符串中的字符**  (!!!!!!)

要改变string对象中字符的值，必须把循环变量定义成引用类型。引用只是给定对象的一个别名，因此当使用引用作为循环控制变量时，这个变量实际上被依次绑定到了序列的每个元素上。

> example: 
> 
> range_for.cpp; 
> 
> exercise_string_empty_size.cpp

    string s("Hello World!!!");
    for (auto &c : s)
        c = toupper(c);
    cout << s << endl;

### 只处理一部分字符

要想访问string对象中的单个字符有两种方式：一种是使用下标，另外一种是使用迭代器。

#### 下标运算符

下标运算符[]接收的输入参数是string::size_type类型的值，这个参数表示要访问的字符的位置，返回值是该位置上字符的**引用**。(从0计起)

**NOTE**： string对象的下标必须大于等于0而小于s.size()，使用超出此范围的下标将引发不可预知的结果，使用下标访问空string也会。所以，**在访问指定字符之前，首先检查s是否为空**

使用下标执行迭代，example:

    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]);index++)
        s[index] = toupeer(s[index]);
    //依次处理s中的字符直至处理完全部字符或者遇到一个空白

当输入: some string的时候，程序将输出：

    SOME string

#### 迭代器

严格来说，string对象不属于容器类型，但是string支持很多与容器类型类似的操作。比如迭代器和下标操作。


### C风格字符串

**NOTE**：尽管C++支持C风格字符串，但在C++程序中最好还是不要使用它们。因为C风格字符串不仅使用起来不太方便，而且极易引发程序漏洞，是诸多安全问题的根本原因。

**NOTE**：对大多数应用来说，使用标准库string要比使用C风格字符串更安全、高效。

### 与旧代码的接口

很多C++程序在标准库出现之前就已经写成了，它们肯定没有用到string和vector类型。而且，有一些C++程序实际上是与C语言或其他语言的接口程序，当然也无法使用C++标准库。

C++专门提供了一组功能来与那些充满了数组和/或C风格字符串的代码相衔接。


### 改变string的其他方法

|      operations      |                           meanings                            |
| :------------------: | :-----------------------------------------------------------: |
|    c.push_back(t)    |                 在c的尾部创建一个值为t的元素                  |
| c.emplace_back(args) |                  在c的尾部由args创建一个元素                  |
|    c.insert(p, t)    |  在迭代器p的元素前创建一个元素t，返回指向新添加元素的迭代器   |
|  c.emplace(p,args)   |                    同上，由args创建元素(?)                    |
|   c.insert(p,n,t)    | 在迭代器p之前插入n个元素值为t。返回新添加的第一个元素的迭代器 |
|   c.insert(p,b,e)    |   将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前   |
|    c.insert(p,il)    |                il是一个花括号包围的元素值列表                 |
