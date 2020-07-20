# I/O

## 初识输入与输出

库iostream包括输入流(istream)和输出流(ostream)

### 标准库输入输出对象

> 标准库：std
> 作用域运算符： ::
前缀std指出cout和endl是定义在名为std的命名空间(namespace)中的

标准库定义了四个IO对象：
1. cin 标准输入
2. cout 标准输出
3. cerr 输出警告和错误消息 标准错误(standard error)
4. clog 输出一般性信息

> example library.cpp

### 向流写入数据

#### 输出运算符 <<

输出运算符接受**两个**运算对象：左侧是ostream对象，右侧是要打印的值

程序也可以改为：
std::cout << "Enter two numbers:";
std::cout << std::endl;

#### 操纵符(manipulator)：endl

这个操作符的效果是结束当前行，**并将与设备关联的缓冲区(buffer)中的内容刷到设备中**。

**NOTE**：缓冲刷新操作可以保证到目前为止程序所产生的所有输出都真正写入输出流中，而不是仅停留在内存中等待写入流。程序员常常在调试时添加打印语句。这类语句应该保证“一直”刷新流，否则，如果程序崩溃，输出可能还留在缓冲区中，从而导致关于程序崩溃位置的错误推断。

#### 缓冲区 buffer： 

一个存储区域，用于保存数据。IO设施通常将输入输出数据保存在一个缓冲区中，读写缓冲区的动作与程序中的动作是无关的。
默认情况下，读cin会刷新cout；程序非正常终止时也会刷新cout。

#### 输入运算符 >>

**NOTE**： 输入运算不用加"std::endl"

一次 cin >> 只会输入一个数据，即遇到blank后就会停止，所以要想一次输入一整行的数据，需要使用getline，example:

    string response;
    getline(cin, response);


## string 流

https://blog.csdn.net/jllongbell/article/details/79092891

``` C++
    #include <sstream>
```

sstream 库定义了三种类：istringstream、ostringstream和stringstream，分别用来进行流的输入、输出和输入输出操作。

　　1.stringstream::str(); returns a string object with a copy of the current contents of the stream.

　　2.stringstream::str (const string& s); sets s as the contents of the stream, discarding any previous contents.

　　3.stringstream 清空，stringstream s; s.str("");

　　4.实现任意类型的转换
      ``` C++
　　　　template<typename out_type, typename in_value>
　　　　out_type convert(const in_value & t){
　　　　　　stringstream stream;
　　　　　　stream << t;//向流中传值
　　　　　　out_type result;//这里存储转换结果
　　　　　　stream >> result;//向result中写入值
　　　　　　return result;
　　　　}
      ```

    


## cstdio

### printf()

printf()的格式化字符
|         type          | Form  |
| :-------------------: | :---: |
|        int(10)        |  %d   |
|        int(10)        |  %i   |
|       long(10)        |  %ld  |
|        long(8)        |  %lo  |
|       long(16)        |  %lx  |
|     long long(10)     | %lld  |
|       short(10)       |  %hd  |
|       short(8)        |  %ho  |
|       short(16)       |  %hx  |
|   unsigned int(10)    |  %u   |
|    unsigned int(8)    |  %o   |
|     unsigned long     |  %lu  |
|    unsigned short     |  %hu  |
|         char          |  %c   |
|   float/double(10)    |  %f   |
|     double (!!!)      |  %lf  |
| float/double(sci(10)) | %e/%E |
|       %f or %e        |  %g   |
|       %f or %E        |  %G   |
|    long double(10)    |  %Lf  |
| long double(sci(10))  |  %Le  |
|      _Bool (C99)      |   ?   |
|      char string      |  %s   |
|        pointer        |  %p   |
|           %           |  %%   |

**NOTE**：
1. d后缀：表示十进制整数
2. x后缀：表示十六进制整数
3. o后缀：表示八进制整数
4. u后缀：表示unsigned
5. l前缀：表示long
6. ll前缀：表示long long
7. h前缀：表示short
8. 如果用%d格式输出char，则输出ASCII码
9.  对于float一类的带"e"的科学记数法的十六进制格式，只需要把e和E分别用a和A代替即可
10. 字符串被储存在char类型的数组中。数组末尾有一个字符\0，代表空字符(null character)。C语言用它来标记字符串的结束。*这意味着数组的容量必须至少比待存储字符串中的字符数多1*
    example: 

        char name[40];
11. 用""括起来的是字符串数组，而用''括起来的是字符
12. 转换说明%p通常以十六进制显示指针的值
13. printf() 不自带换行符
    


**printf()的修饰符**
1. 标记：五种标记(-、+、空格、#、和0)
   示例："%-10d"
2. 数字：最小字段宽度。若该字段不能容纳待打印的数字或者字符串，系统会使用更宽的字段
   示例："%4d"
3. .数字：精度(?????)
   示例："%5.2f"打印一个浮点数，字段宽度为5字符，其中小数点后有两位数字
4. h前缀：和整型转换说明一起使用，表示short int 或 unsigned short int类型的值
5. hh前缀：和整型转换说明一起使用，表示signed char 或 unsigned char
6. j前缀：和整型转换说明一起使用，表示intmax_t 或 uintmax_t类型的值。定义在stdint.h中
7. l前缀：long int, unsigned long int
8. ll前缀：long long int, unsigned long long int (C99)
9. L前缀：long double
10. t前缀：ptrdiff_t (是两个指针差值的类型)
11. z前缀：size_t (C99) (????)

> example:

    exercise4_8_2.c  (不过这最后一小题怎么做??????)

**修饰符中的标记**
1. \-  待打印项左对齐
2. \+  有符号值若为正，则在值前面显示加号，否则显示减号
3. 空格  有符号值若为正，则在值前面显示前导空格(不显示任何符号)，否则显示减号+标记覆盖一个空格
4. \#  把结果转换成另一种形式(??????)
5. 0  对于数值格式，用前导0代替空格填充字段宽度。对于整数格式，如果出现-标记或指定精度，则忽略该标记

**NOTE**：使用足够大的固定字段宽度可以让输出整齐美观
example:

    printf("%9d %9d %9d\n", val1, val2, val3);
output:

           12      234     1222
            4        5       23
        22334     2322    10001


### scanf()

简单的规则：
1. 如果用scanf()读取基本变量类型的值，在变量名前加上一个&
2. 如果用scanf()把字符串读入字符数组中，不要使用&

**NOTE** 
1. scanf()的一大用处就是检测数据流。example:

        while (scanf("%f", n) == 1) {...}
    
    如果系统检测到的是符合scanf()预期的浮点数，那么scanf()就会返回1，否则就不会返回1(0或者EOF)，就不会进行循环体内的操作。scanf()返回的数字代表的是检测到的数据的个数。
2. scanf()在遇到第一个空白(空格、制表符或者换行符)时就不再读取输入了，因此，scanf()只会读取字符串中的第一个单词，而不是一整句。
3. 逐个读取数字的方法：

        for (int i = 0; i < length; i++)
            scanf("%1d", &array[i]);     //用字段宽度限制scanf()的读取范围！




scanf()的转换说明
|     转换说明     |       含义        |
| :--------------: | :---------------: |
|        %c        |       char        |
|      %d,%i       |  signed int (10)  |
| %e,%f,%g,%a(C99) |       float       |
|        %o        |  signed int (8)   |
|        %x        |  signed int (16)  |
|        %p        |      pointer      |
|        %s        |      string       |
|        %u        | unsigned int (10) |

scanf()转换说明中的修饰符
|  转换说明   |                               含义                               |
| :---------: | :--------------------------------------------------------------: |
|     \*      |       抑制赋值 e.g. "%*d"  **很重要！可以忽略特定输入！**        |
|    数字     |                           最大字段宽度                           |
|     hh      |     把整数作为signed char或unsigned char类型读取 e.g. "%hhd"     |
|     ll      | 把整数作为long long或unsigned long long类型读取(C99) e.g. "%lld" |
|   %hd,%hi   |                            short int                             |
| %ho,%hx,%hu |                        unsigned short int                        |
| %lo,%lx,%lu |                          unsigned long                           |
| %le,%lf,%lg |                              double                              |
| %Le,%Lf,%Lg |                           long double                            |



## string

### getline()

```
istream& getline (istream&  is, string& str, char delim);
istream& getline (istream&& is, string& str, char delim);
istream& getline (istream&  is, string& str);
istream& getline (istream&& is, string& str);
```

读取的istream是作为参数is传进函数的。读取的字符串保存在string类型的str中。使用过程中不需要将str变为C风格字符串
