# 容器

## 容器库概览

容器操作

|    类型别名     |                      意义                      |
| :-------------: | :--------------------------------------------: |
|    iterator     |                     迭代器                     |
| const_iterator  |                只读的迭代器类型                |
|    size_type    | 无符号整数类型，足够保存此容器类型最大可能大小 |
| difference_type |      带符号整数类型，两个迭代器之间的距离      |
|   value_type    |                    元素类型                    |
|    reference    |    元素的左值类型：与value_type&含义相同(?)    |
| const_reference |                 const左值类型                  |

|     构造函数     |                           意义                            |
| :--------------: | :-------------------------------------------------------: |
|       C c;       |              默认构造函数，构造空容器(array)              |
|    C c1(c2);     |                      构造c2的拷贝c1                       |
|    C c(b, e);    | 构造c，将迭代器b和e指定的范围内的元素拷贝到c(array不支持) |
| C c{a, b, c...}; |                        列表初始化c                        |

|    赋值与swap     |            意义            |
| :---------------: | :------------------------: |
|      c1 = c2      | 将c1中的元素替换为c2中元素 |
| c1 = {a, b, c...} | 将c1中元素替换为列表中元素 |
|     a.swap(b)     |       交换a和b的元素       |
|    swap(a, b)     |            同上            |

|     大小     |               意义                |
| :----------: | :-------------------------------: |
|   c.size()   | c中元素的数目(不支持forward_list) |
| c.max_size() |      c可以保存的最大元素数目      |
|  c.empty()   |             是否为空              |

| 添/删元素(不适用于array) |             意义              |
| :----------------------: | :---------------------------: |
|      c.insert(args)      |     将args中的元素拷贝进c     |
|     c.emplace(inits)     | 使用inits构造c中的一个元素(?) |
|      c.erase(args)       |      删除args指定的元素       |
|        c.clear()         |  删除c中的所有元素，返回void  |

|  关系运算符  |              意义              |
| :----------: | :----------------------------: |
|    ==, !=    | 所有容器都支持相等(不等)运算符 |
| <, <=, >, >= | 关系运算符(无序关联容器不支持) |

|      获取迭代器      |                   意义                    |
| :------------------: | :---------------------------------------: |
|  c.begin(), c.end()  | 返回指向c的首元素和尾元素之后位置的迭代器 |
| c.cbegin(), c.cend() |            返回const_iterator             |

|   反向容器的额外成员   |                   意义                    |
| :--------------------: | :---------------------------------------: |
|    reverse_iterator    |          按逆序寻址元素的迭代器           |
| const_reverse_iterator |              只读逆序迭代器               |
|  c.rbegin(), c.rend()  | 返回指向c的尾元素和首元素之前位置的迭代器 |
| c.crbegin(), c.crend() |        返回const_reverse_iterator         |

**NOTE**: 关联容器不支持顺序容器的位置相关的操作。


## 顺序容器

顺序容器(sequential container)为程序员提供了控制元素存储和访问顺序的能力。

标准库中有很多顺序容器，所有顺序容器都提供了快速顺序访问元素的能力。但是，这些容器在以下方面都有不同的性能折中：
1. 向容器添加或从容器中删除元素的代价
2. 非顺序访问容器中元素的代价

顺序容器类型

|  container   |                        clarification                         |
| :----------: | :----------------------------------------------------------: |
|    vector    | 可变大小数组。支持快速随机访问。除尾部外插入删除元素可能很慢 |
|    deque     |     双端队列。支持快速随机访问。在头尾插入/删除速度很快      |
|     list     |    双向链表。只支持双向顺序访问。任何位置插入/删除都很快     |
| forward_list |         单向列表。只支持单项顺序访问。插入/删除很快          |
|    array     |      固定大小数组。支持快速随机访问。不能添加或删除元素      |
|    string    |            与vector相似的容器，但专门用于保存字符            |

除了array外，其他容器都提供高效、灵活的内存管理。

选择容器的基本原则
1. 除非有很好的理由，否则应使用vector
2. 如果程序有很多小的元素，且空间的额外开销很重要，则不要使用list或forward_list
3. 如果要求随机访问元素，应使用vector或deque
4. 如果程序只有在读取输入时才需要在容器中间插入元素，随后需要随机访问元素，则：
   1. 首先，确定是否真的需要在容器中间位置添加元素。可以先容易地向vector追加数据，然后再调用标准库的sort函数来重排容器中的元素，从而避免在中间位置添加元素。
   2. 如果必须在中间位置插入元素，考虑在输入阶段使用list，一旦输入完成，将list中的内容拷贝到一个vector中



#### 迭代器

与容器一样，迭代器有着公共的接口：如果一个迭代器提供某个操作，那么所有提供相同操作的迭代器对这个操作的实现方式都是相同的。

##### 迭代器范围

迭代器范围的概念是标准库的基础。

一个迭代器范围由一对迭代器表示：首元素和尾后元素，begin 和 end。 [begin, end)

1. 如果begin和end相等，则范围为空。
2. 如果begin和end不等，则范围至少包含一个元素

#### 容器类型成员

每个容器都定义了多个类型。比如：size_type, iterator, const_iterator。

大多数容器还提供反向迭代器。

剩下的就是类型别名，通过类型别名，可以在不了解容器中元素类型的情况下使用它。如果需要元素类型，可以使用容器的value_type。如果需要元素类型的一个引用，可以使用reference或者const_reference。


#### 容器定义和初始化

每个容器类型都定义了一个默认构造函数。除array之外，其他容器的默认构造函数都会创建一个指定类型的空容器，且都可以接受指定容器大小和元素初始值的参数。

容器定义和初始化

|    statements    |                          meanings                           |
| :--------------: | :---------------------------------------------------------: |
|       C c;       |   默认构造函数，构造空容器(若是array，则按默认方式初始化)   |
|    C c1(c2);     | 构造c2的拷贝c1（必须是相同类型，若是array，还必须有相同大小 |
|     C c1=c2      |                            同上                             |
|    C c(b, e);    |  构造c，将迭代器b和e指定的范围内的元素拷贝到c(array不支持)  |
| C c{a, b, c...}; |                         列表初始化c                         |
|     C seq(n)     |  seq包含n个元素并进行了值初始化，是透明的（string不透明）   |
|    C seq(n,t)    |                 seq包含n个初始化为值t的元素                 |



#### 赋值和swap

##### 使用assign

##### 使用swap

swap操作交换两个相同类型容器的内容。

    vector<string> svec1(10);
    vector<string> svec2(24);
    swap(svec1, svec2);


### 顺序容器操作

#### 向顺序容器添加元素

添加元素的操作(array不支持)

|      operations       |                           meanings                            |
| :-------------------: | :-----------------------------------------------------------: |
|    c.push_back(t)     |                 在c的尾部创建一个值为t的元素                  |
| c.emplace_back(args)  |                  在c的尾部由args创建一个元素                  |
|    c.push_front(t)    |                            同上上                             |
| c.emplace_front(args) |                            同上上                             |
|    c.insert(p, t)     |  在迭代器p的元素前创建一个元素t，返回指向新添加元素的迭代器   |
|   c.emplace(p,args)   |                     同上，由args创建元素                      |
|    c.insert(p,n,t)    | 在迭代器p之前插入n个元素值为t。返回新添加的第一个元素的迭代器 |
|    c.insert(p,b,e)    |   将迭代器b和e指定的范围内的元素插入到迭代器p指向的元素之前   |
|    c.insert(p,il)     |                il是一个花括号包围的元素值列表                 |

**NOTE**：
1. forward_list有自己专有版本的insert和emplaces
2. forward_list不支持push_back和emplace_back
3. vector和string不支持push_front和emplace_front

#### 访问元素

在顺序容器中访问元素的操作

| operations |          meanings          |
| :--------: | :------------------------: |
|  c.back()  |    返回c中尾元素的引用     |
| c.front()  |    返回c中首元素的引用     |
|    c[n]    | 返回c中下标为n的元素的引用 |
|  c.at(n)   |            同上            |

**NOTE**：
1. at和下标操作只适用于string, vector, deque, array
2. back不适用于forward_list


#### 删除元素

顺序容器的删除操作

|  operations   |                           meanings                            |
| :-----------: | :-----------------------------------------------------------: |
| c.pop_back()  |                         删除c中尾元素                         |
| c.pop_front() |                         删除c中首元素                         |
|  c.erase(p)   | 删除迭代器p所制定的元素，返回一个指向被删元素之后元素的迭代器 |
| c.erase(b,e)  | 删除迭代器b和e所指定范围内的元素，返回最后被删元素后的迭代器  |
|   c.clear()   |                       删除c中的所有元素                       |

#### 特殊的forward_list操作(?)

#### 改变容器大小

顺序容器大小操作（不适用于array）

|  operations   |            meanings             |
| :-----------: | :-----------------------------: |
|  c.resize(n)  |      调整c的大小为n个元素       |
| c.resize(n,t) | 同上，新添加的元素被初始化为值t |


#### 容器操作可能导致迭代器失效

#### vector对象是如何增长的

vector和string类型提供了一些成员函数，允许我们与它的实现中内存分配部分互动

容器大小管理操作

|    operations     |                 meanings                  |
| :---------------: | :---------------------------------------: |
| c.shrink_to_fit() |   请将capacity()减少为与size()相同大小    |
|   c.capacity()    | 不重新分配内存空间的话，c可以保存多少元素 |
|   c.reserve(n)    |      分配至少能容纳n个元素的内存空间      |

**NOTE**：
1. shrink_to_fit只适用于vector、string和deque
2. capacity和reserve只适用于vector和string


### 额外的string操作(?)

略


### 容器适配器(?????)



### 标准库类型vector

标准库类型vector表示对象的集合，其中所有对象的类型都相同。集合中的每个对象都有一个与之对应的索引，索引用于访问对象。所以vector也常被称作容器(container)

vector是一个封装了动态大小数组的顺序容器(sequence container)，是一个能够存放任意类型的动态数组。

vector被包含在头文件<vector>的标准库中，可以用using声明进行简化：

    #include <vector>
    using std::vector;

C++语言既有类模板(class template)，也有函数模板，其中vector是一个类模板。模板本身不是类或函数，相反可以将模板看作编译器生成类或者函数编写的一份说明。编译器根据模板创建类或者函数的过程称为实例化(instantiation)，当使用模板时，需要指出编译器应把类或者函数实例化成何种类型。

对于类模板来说，需要提供一些额外信息来指定模板到底实例化成什么样的类。提供信息的方式：在模板名字后面跟一对尖括号，在括号内放上信息。example:

    vector<int> ivec;              //ivec保存int类型的对象
    vector<Sales_item> Sales_vec;  //保存Sales_item类型的对象
    vector<vector<string>> file;   //该向量的元素是vector对象

**NOTE**：
1. 因为引用不是对象，所以不存在包含引用的vector。
2. 早期版本的C++标准中，如果vector的元素还是vector(或者其他模板类型)，则其定义的形式有所不同，必须在外层vector对象的右尖括号和其元素类型之间添加一个空格:

        vector<vector<int> > file;


#### 定义和初始化vector对象

初始化vector对象的方法：

    vector<T> v1;                       //空vector，它潜在的元素是T类型的，执行默认初始化
    vector<T> v2(v1);                   //v2中包含有v1所有元素的副本
    vector<T> v2 = v1;                  //同上
    vector<T> v3(n, val);               //包含了n个重复的元素，每个元素的值都是val
    vector<T> v4(n);                    //包含了n个重复地执行了*值初始化的*对象
    vector<T> v5{a, b, c...}            //列表初始化，包含了初始值个数的元素，每个元素被赋予相应的初始值
    vector<T> v5 = {a, b, c...}         //同上

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


#### vector操作

> example: score.cpp  用于计算每个分数段的人数(很像python中的dict计数)

|    operation    |        meaning        |
| :-------------: | :-------------------: |
|    v.empty()    |       返回真假        |
|    v.size()     |       返回个数        |
|      v[n]       | 返回n位置上元素的引用 |
|     v1 = v2     |       拷贝替换        |
| v1 = {a,b,c...} |       拷贝替换        |
|    v1 == v2     |       完全相同        |
|    v1 != v2     |         不同          |
|  <. <=, >, >=   |  以字典顺序进行比较   |
| v.push_back(t)  |    在尾端添加一个t    |
|    v.front()    |    返回第一个元素     |
|    v.back()     |   返回最后一个元素    |


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


#### 迭代器iterator

所有标准库容器都可以使用迭代器，但是其中只有少数几种才同时支持下标运算符。

和指针不一样的是，获取迭代器不是使用取地址符，有迭代器的类型同时拥有返回迭代器的成员。比如，这些类型都拥有名为begin和end的成员。

begin()成员负责返回指向第一个元素的迭代器，end()成员则负责返回指向容器"尾元素的下一位置(one past the end)"的迭代器，也就是说，该迭代器指示的是容器的一个本不存在的"尾后(off the end)"元素。这样的迭代器没什么实际含义，仅是个标记而已，表示我们已经处理完了容器中的所有元素。

**NOTE**：
1. 如果容器为空，begin和end返回的是同一个迭代器，都是尾后迭代器。
2. C++貌似并不关心迭代器的类型，只需要在iter前面注明auto就可以了。但是iter可以递增或者递减，说明有整数的性质。

example:

    auto b = v.begin(), e = v.end();
    //由编译器决定b和e的类型


##### 迭代器运算符

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


##### 迭代器类型

一般来说我们无需知道迭代器的精确类型(就像string和vector的size_type成员一样)。而实际上，那些拥有迭代器的标准库类型使用iterator和const_iterator来表示迭代器的类型：

    vector<int>::iterator it;  // it能读写vector<int>的元素
    string::iterator it2;      // it2能读写string对象中的字符
    
    vector<int>::const_iterator it3;  // it3只能读取但不能修改它所指的元素值
    string::const_iterator it4;       // it4只能读取但不能修改它所指的元素值


##### 迭代器的限制

1. 不能在范围for循环中向vector对象添加元素。
2. 任何一种改变vector对象容量的操作，都会使vector对象的迭代器失效。
   

**NOTE**：但凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素。


##### 使用迭代器运算

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






## 关联容器

关联容器都支持本md开始时的容器操作，除了顺序容器的位置相关的操作。

关联容器类型
一， 按关键字有序保存元素
   
| containers |       clarifications        |
| :--------: | :-------------------------: |
|    map     |  关联数组：保存key-value对  |
|    set     | 关键字即值，只保存key的容器 |
|  multimap  |    关键字可重复出现的map    |
|  multiset  |    关键字可重复出现的set    |

**NOTE**：如果一个multimap或multiset中有多个元素具有给定关键字，则这些元素在容器中会相邻存储


二， 无序集合
   
|     containers     |   clarifications    |
| :----------------: | :-----------------: |
|   unordered_map    | 用散列函数组织的map |
|   unordered_set    | 用散列函数组织的set |
| unordered_multimap |       可重复        |
| unordered_multiset |       可重复        |

类型map和multimap定义在头文件< map >中； 
set和multiset定义在头文件<set>中；
无序容器则定义在头文件unordered_map和unordered_set中。



### 定义关联容器

初始化一个map时，必须提供关键字类型和值类型。但是可以默认初始化，也可以用花括号将每个关键字-值对包围着初始化：

    map<string, size_t> word_count;
    map<string, string> authors = { {"Joyce", "James"},
                                    {"Austen", "Jane"},
                                    {"Dickens", "Charles"} };  // {key, value}

初始化set就不需要构建键值对。

一个map或set中的关键字必须是唯一的。即，对于一个给定的关键字，只能由一个元素的关键字等于它。而容器multimap和multiset没有此限制。举例：用vector保存20个元素：0到9每个整数有两个拷贝：

    vector<int> ivec;
    for (vector<int>::size_type i = 0; i != 10; ++i) {
        ivec.push_back(i);
        ivec.push_back(i);
    }

    set<int> iset(ivec.cbegin(), ivec.cend());        // C c(b, e) 构造函数
    multiset<int> miset(ivec.cbegin(), ivec.cend());


#### 关键字类型的要求 (?)

关联容器对其关键字类型有一些限制。

##### 对有序关联容器

关键字必须定义元素比较的方法。

默认情况下，标准库使用关键字类型的 < 运算符来比较两个关键字。在集合类型中，关键字类型就是元素类型；在映射类型中，关键字类型是元素的第一部分的类型。

可以向一个算法提供给我们自己定义的比较操作(泛型算法)，与之类似，也可以提供自己定义的操作来代替关键字上的 < 运算符。所提供的操作必须在关键字类型上定义一个严格弱序(strict weak orering)。可以将严格弱序看作“小于等于”。


#### pair 类型

pair是定义在头文件utility中的标准库类型

一个pair保存两个数据成员。类似容器，pair是一个用来生成特定类型的模板。当创建一个pair时，我们必须提供两个类型名：

    pair<string, string> anon;
    pair<string, size_t> word_count;
    pair<string, vector<int>> line;
    // pair 的默认构造函数对数据成员进行值初始化

    pair<string, string> author{"James", "Joyce"};

与其他标准库类型不同，pair的数据成员是public的。两个成员分别命名为first和second。example:

    cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times" : " time") << endl;

**NOTE**: first和second成员没有括号！


##### pair上的操作

> example: exersize11_13.cpp

|        operations         |                          meanings                          |
| :-----------------------: | :--------------------------------------------------------: |
|       pair<T1, T2>        |                          值初始化                          |
|  pair<T1, T2> p(v1, v2)   |              first和second分别用v1和v2初始化               |
| pair<T1, T2> p = {v1, v2} |                            同上                            |
|     make_pair(v1, v2)     |     返回一个用v1和v2初始化的pair。pair的类型从v中推断      |
|          p.first          |              返回p的名为first的(公有)数据成员              |
|         p.second          |                           second                           |
|        p1 relop p2        | 关系运算符按字典定义：p1.first < p2.first当p1 < p2时为true |
|         p1 == p2          |             当first和second成员分别相等时相等              |
|         p1 != p2          |                            同上                            |

##### 创建pair对象的函数

一个函数需要返回一个pair，可以用花括号包围的初始化器来返回pair：

    pair<string, int>                             //？？？？？？这是什么操作？
    process(vector<string> &v) {
        //处理v
        if (!v.empty())
            return {v.back(), v.back().size()};  //列表初始化
        else
            return pair<string, int>();   //隐式构造返回值
    }

在较早的C++版本中，不允许用花括号包围的初始化器来返回pair这种类型的对象，必须显式地构造返回值：

    if (!v.empty())
        return pair<string, int>(v.back(), v.back().size());

还可以用make_pair来生成pair对象：

    if (!v.empty())
        return make_pair(v.back(), v.back().size());



### 关联容器操作

关联容器还定义了以下类型：

|    types    |                          clarifications                          |
| :---------: | :--------------------------------------------------------------: |
|  key_type   |                      此容器类型的关键字类型                      |
| mapped_type |                每个关键字关联的类型，只适用于map                 |
| value_type  | 对set,与key_type相同；对map，为pair<const key_type, mapped_type> |

与顺序容器一样，我们使用作用域运算符来提取一个类型的成员。example:

    map<string, int>::key_type key;




example: 用map实现单词计数程序

``` C++
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word]; //如果有此关键字，+1；如果没有，默认初始化为0再+1
    for (const auto &w : word_count)
        cout << w.first << " occurs " << w.second
            << (w.second > 1) ? " times" : " time" << endl;
```

example: 用set实现忽略特定单词程序

``` C++
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But","And","Or","An","A",
                            "the","but","and","or","an","a"};
    string word;
    while (cin >> word) {
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    }
```

find()函数返回一个迭代器。如果给定关键字在set中，迭代器指向该关键字。否则，find()返回尾后迭代器。


#### 关联容器迭代器

当解引用一个关联容器迭代器时，我们会得到一个类型为容器的value_type的值的引用。对map而言，value_type是一个pair类型，其first成员保存const的关键字，second成员保存值。example:

    auto map_it = word_count.begin(); //map_it指向一个pair
    cout << map_it->first;
    cout << " " << map_it->second;
    map_it->first = "new key";  //错误，关键字是const的，无法修改
    ++map_it->second;           //正确，可以改变值

**NOTE**：一个map的value_type是一个pair，可以改变pair的值，不能改变关键字成员的值。


**NOTE**：set的迭代器是const的，尽管set类型同时定义了iterator和const_iterator类型。两种类型只允许只读访问set中的元素。


##### 遍历关联容器

有顺序的关联容器可以被遍历。example:

    auto map_it = word_count.cbegin();
    while (map_it != word_count.cend()) {
        cout << map_it->first << " occurs " << map_it->second << " times" << endl;
    ++map_it;
    }

**NOTE**：本程序是按字典顺序排列的。当使用一个迭代器遍历一个map、multimap、set或multiset时，迭代器按关键字升序遍历元素。


##### 关联容器和算法

通常不对关联容器使用泛型算法。关键字是const这一特性意味着不能将关联容器传递给修改或重排容器元素的算法，因为这类算法需要向元素写入值。



#### 添加元素

* c.insert(v)  // v是value_type类型的对象

关联容器的insert成员向容器中添加一个元素或一个元素范围。

由于map和set包含不重复的关键字，因此插入一个以存在的元素对容器没有任何影响：

    vector<int> ivec = {2,4,6,8,2,4,6,8};
    set<int> set2;
    set2.insert(ivec.cbegin(), ivec.cend());  // 迭代器范围插入
    set2.insert({1,3,5,7,1,3,5,7});           // 列表插入

**NOTE**；insert有两个版本，分别接受一对迭代器，或是一个初始化器列表，这两个版本的行为类似对应的构造函数：

    set.insert(b, e);
    set.insert({...});


* c.emplace(args)   //args用来构造一个元素

对于map和set，只有当元素的关键字不在c中时才插入(或构造)元素。函数返回一个pair，包含一个迭代器，指向具有指定关键字的元素(???)，以及一个指示插入是否成功的bool值。


* c.insert(p, v) & c.emplace(p, args)

类似insert(v) & emplace(args)，但将迭代器p作为一个提示，指出从哪里开始搜索新元素应该存储的位置。返回一个迭代器，指向具有给定关键字的元素。


##### 向 map 添加元素

必须记住元素类型是pair。example:

    word_count.insert({word, 1});
    word_count.insert(make_pair(word, 1));
    word_count.insert(pair<string, size_t>(word, 1));
    word_count.insert(map<string, size_t>::value_type(word, 1));
    // 一个比一个繁琐


##### 检测 insert 的返回值

insert(or emplace)返回的值的类型依赖于容器类型和参数。

一：对于不包含重复关键字的容器，添加单一元素的insert和emplace版本返回一个pair，表明插入操作是否成功。pair的first成员是一个迭代器，指向具有给定关键字的元素；second成员是一个bool值，指出插入是否成功。

如果关键字已在容器中，则insert什么事情也不做，且返回值中的fool部分为false，否则为true。

example: 重写单词计数程序

    map<string,size_t> word_count;
    string word;
    while (cin >> word) {
        auto ret = word_count.insert({word,1});
        if (!ret.second)
            ++ret.first->second;  // 等价于：++((ret.first)->second);
    }


二：对于向multiset或multimap添加元素，容器中的关键字不必唯一，在这些类型上调用insert总会插入一个元素。example:

    //建立一个作者到他所著的每个书籍的题目的映射
    multimap<string, string> authors;
    authors.insert({"Barth, John". "Sot-Weed Factor"});
    authors.insert({"Barth, John", "Lost in the Funhouse"});
    //对于添加的第二个元素，关键字也是Barth, John。

对允许重复关键字的容器，接受单个元素的insert操作返回一个指向新元素的迭代器。这里无需返回一个bool值，因为insert总是向这类容器中加入一个新元素。



#### 删除元素

关联容器定义了三个版本的 erase。与顺序容器一样，我们可以通过传递给erase一个迭代器或一个迭代器对来删除一个元素或者一个元素范围。这两个版本的erase与对应的顺序容器的操作非常相似：指定的元素被删除，函数返回void。

|  operations   |                           meanings                            |
| :-----------: | :-----------------------------------------------------------: |
| c.pop_back()  |                         删除c中尾元素                         |
| c.pop_front() |                         删除c中首元素                         |
|  c.erase(p)   | 删除迭代器p所制定的元素，返回一个指向被删元素之后元素的迭代器 |
| c.erase(b,e)  | 删除迭代器b和e所指定范围内的元素，返回最后被删元素后的迭代器  |
|   c.clear()   |                       删除c中的所有元素                       |

关联容器提供一个额外的erase操作，**它接受一个key_type参数。**此版本删除所有匹配给定关键字的元素(如果存在的话)，**返回实际删除的元素的数量。**我们可以用此版本在打印结果之前从word_count中删除一个特定的单词：

    if (word_count.erase(removal_word))
        cout << "ok: " << removal_word << " removed\n";
    else cout << "oops: " << removal_word << " not found!\n";

从关联容器删除元素

|   functions   |                        clarification                         |
| :-----------: | :----------------------------------------------------------: |
|  c.erase(k)   | 删除每个关键字为k的元素。返回一个size_type值，指出删除的数量 |
|  c.erase(p)   |    删除迭代器p指定的真实元素，返回p后元素或尾后元素迭代器    |
| c.erase(b, e) |                  删除b和e所表示的范围的元素                  |




#### map 的下标操作

map 和 unordered_map 容器提供了下标运算符和一个对应的 at 函数。set类型不支持下标，因为 set 中没有与关键字相关联的“值”。不能对一个 multimao 或一个 unordered_multimap进行下标操作，因为这些容器中可能有多个值与一个关键字相关联。

类似其他下标运算符，map 下标运算符接受一个索引 (即，一个关键字)，获取与此关键字相关联的值。**与其他下标运算符不同的是，如果关键字并不在 map 中，会为它创建一个元素并插入到 map 中，关联值将进行值初始化。

example:

    map <string, size_t> word_count;
    word_count["Anna"] = 1;

**NOTE**：只可以对非 const 的 map 使用下标操作。


| operations |                          clarifications                           |
| :--------: | :---------------------------------------------------------------: |
|    c[k]    |             返回关键字为k的元素，或添加元素并值初始化             |
|  c.at(k)   | 访问关键字为k的元素，带参数检查：若k不在c中，抛出out_of_range异常 |

**NOTE**：
1. 当对一个 map 进行下标操作时，会获得一个 mapped_type 对象；但当解引用一个 map 迭代器时，会得到一个 value_type 对象。
2. 与其他下标运算符相同的是，map 的下标运算符返回一个左值。



#### 访问元素

关联容器提供多种查找一个指定元素的方法。

例如，如果要判断一个特定元素是否已在容器中，可能 find 是最佳选择。对于不允许重复关键字的容器，可能使用 find 还是 count 没什么区别。但对于允许重复关键字的容器，count 还会做更多的工作：如果元素在容器中，它还会统计有多少个元素有相同的关键字。example:

    set<int> iset = {0,1,2,3,4,5,6,7,8,9};
    iset.find(1);   //返回一个迭代器，指向key==1的元素
    iset.find(11);  //返回尾后元素的迭代器
    iset.count(1);  //返回1
    iset.count(11); //返回0


在一个关联容器中查找元素的操作

|    operations    |                       clarifications                       |
| :--------------: | :--------------------------------------------------------: |
|    c.find(k)     |       返回第一个关键字为k的元素的迭代器或尾后迭代器        |
|    c.count(k)    |                返回关键字等于k的元素的数量                 |
| c.lower_bound(k) |           返回第一个关键字不小于k的元素的迭代器            |
| c.upper_bound(k) |        返回一个迭代器，指向第一个关键字大于k的元素         |
| c.equal_range(k) | 返回迭代器pair，表示关键字等于k的元素范围，或都等于c.end() |


在一个允许重复关键字的关联容器中查找一个元素会相对复杂一些。但是**如果一个multimap 或 multiset 中有多个元素具有给定关键字，则这些元素在容器中会相邻存储**。例如，给定一个从作者到著作题目的映射，要打印一个特定作者的所有著作，有三种不同的方法：

**第一种**最直观的方法是用 find 和 count

    string search_item("Alain de Botton");
    auto entries = authors.count(search_item);
    auto iter = authors.find(search_item);
    while (entries) {
        cout << iter->second << endl;
        ++iter;
        --entries;
    }


**第二种**，用lower_bound和upper_bound来解决问题。因为lower指向第一个符合的元素，upper指向最后一个符合的元素。当然，**这两个操作返回的迭代器可能是容器的尾后迭代器**。如果查找的元素具有容器中最大的关键字，则此关键字的upper_bound返回尾后迭代器。如果关键字不存在，且大于容器中任何关键字，则lower_bound也返回尾后迭代器。

**NOTE**：如果关键字不在容器中，则lower_bound会返回关键字的第一个安全插入点————补影响容器中元素顺序的插入位置

使用这个操作，重写之前的程序：

    for (auto beg = authors.lower_bound(search_item),
                end = authors.upper_bound(search_item);
        beg != end; ++beg)
        cout << beg->second << endl;

此程序与之前相同，但更直接。如果容器中没有这样的元素，beg 将指向第一个关键字大于 search_item 的元素，有可能是尾后迭代器。此时 beg 和 end 应该相等，尽管这两个操作并不报告关键字是否存在。


**第三种**，这种方法是三种方法中最直接的：直接调用 equal_range。此函数接受一个关键字，返回一个迭代器 pair。若关键字存在，则第一个迭代器指向第一个与关键字匹配的元素，第二个迭代器指向最后一个匹配元素之后的位置。若未找到匹配元素，则两个迭代器都指向关键字可以插入的位置————两个迭代器相等。

    for (auto pos = authors.equal_range(search_item);
        pos.first != pos.second; ++pos.first)
        cout << pos.first->second << endl;



> example: 一个单词转换的 map。包括两个文件和程序：


## 无序容器

新标准定义了4个无序关联容器 (unordered associative container)。这些容器不是使用比较运算符来组织元素，而是使用一个哈希函数(hash function)和关键字类型的==运算符。

虽然理论上哈希技术能获得更好的平均性能，但在实际中想要达到很好的效果还需要进行一些性能测试和调优工作。

**NOTE**：如果关键字类型固有就是无序的，或者性能测试发现问题可以用哈希计数解决，就可以使用无序容器。


### 无序容器操作

除了哈希管理操作之外，无序容器还提供了与有序容器相同的操作(find, insert等)。这意味着map和set的操作也能用于unordered_map和unordered_set。无序容器也有允许重复关键字的版本。

因此，通常可以用一个无序容器替换对应的有序容器，反之亦然。但是由于元素未按顺序存储，一个使用无序容器的程序的输出(t通常)会与使用有序容器的版本不同。

重写单词计数程序：

    unordered_map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (count auto &w : word_count)
        cout << w.first << " occurs " << w.second
            << ((w.second > 1) ? " times" : " time") << endl;
    // 对于每个单词，和之前的程序相比，我们将得到相同的计数结果。但单词不太可能按字典序输出。


### 管理桶

无序容器在存储上组织为一组桶，每个桶保存零个或多个元素。无序容器使用一个哈希函数将元素映射到桶。

为了访问一个元素，容器首先计算元素的哈希值，指出应该搜索哪个桶。容器将具有一个特定哈希值的所有元素都保存在相同的桶中，如果容器允许重复关键字，所有具有相同关键字的元素也都会在同一个桶中。因此，无序容器的性能依赖于哈希函数的质量和桶的数量和大小。

当一个桶保存多个元素时，需要顺序搜索这些元素来查找我们想要的那个。计算一个元素的哈希值和在桶中搜索通常都是很快的操作。但是，如果一个桶中保存了很多元素，那么查找一个特定元素就需要大量比较操作。


无序容器管理操作

|        桶接口        |       clarifications       |
| :------------------: | :------------------------: |
|   c.bucket_count()   |     正在使用的桶的数目     |
| c.max_bucket_count() | 容器能容纳的最多的桶的数量 |
|   c.bucket_size(n)   |    第n个桶中有多少元素     |
|     c.bucket(k)      | 关键字为k的元素在哪个桶中  |

|         桶迭代         |          clarifications          |
| :--------------------: | :------------------------------: |
|     local_iterator     | 可以用来访问桶中元素的迭代器类型 |
|  const_local_iterator  |       桶迭代器的const版本        |
|  c.begin(n), c.end(n)  |  桶n的首元素迭代器和尾后迭代器   |
| c.cbegin(n), c.cend(n) |           同上，const            |

|      哈希策略       |                                        clarifications                                         |
| :-----------------: | :-------------------------------------------------------------------------------------------: |
|   c.load_factor()   |                               每个桶的平均元素数量，返回float值                               |
| c.max_load_factor() | c试图维护的平均桶大小，返回float值。c会在需要时添加新的桶，以使得load_factor<=max_load_factor |
|     c.rehash(n)     |               重组存储，使得bucket_count>=n且bucket_count>size/max_load_factor                |
|    c.reserve(n)     |                          重组存储，使得c可以保存n个元素且不必rehash                           |


### 无序容器对关键字类型的要求 (??????)





## 栈

### 栈的操作

| operations |             clarifications             | time complexity |
| :--------: | :------------------------------------: | :-------------: |
|  empty()   |   returns whether the stack is empty   |      O(1)       |
|   size()   |     returns the size of the stack      |      O(1)       |
|   top()    | returns a reference to the top element |      O(1)       |
|  push(g)   |    adds the element 'g' at the top     |      O(1)       |
|   pop()    |        deletes the top element         |      O(1)       |
