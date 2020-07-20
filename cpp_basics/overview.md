# 概览

## 头文件

确保头文件多次包含仍能安全工作的常用技术是预处理器(preprocessor)，它由C语言继承而来

C++还会用到的一项预处理功能是头文件保护符(header guard)，头文件保护符依赖于预处理变量。预处理变量有两种状态：已定义和未定义。

/#define指令把一个名字设定为预处理器变量，另外两个指令则分别检查某个指定的预处理变量是否已经定义：
1. /#ifdef当且仅当变量已定义时为真
2. /#ifndef当且仅当变量未定义时为真
3. 一旦结果为真，则执行后续操作直至遇到#endif指令为止

**NOTE**: 
1. 对于不属于标准库的头文件，用双引号包围("Sales_item.h")
2. 通常情况下，#include指令必须出现在所有函数之外（开始位置）

### <iostream>

### 容器

### <utility>

内含 pair 标准库类型


### <algorithm>

内含各种数据结构的函数

The algorithms library defines functions for a variety of purposes (e.g. searching, sorting, counting, manipulating) that operate on ranges of elements. 

### <bits/stdc++.h>

C++ 的万能头文件，其中包含了：

``` C++
    #ifndef _GLIBCXX_NO_ASSERT
    #include<cassert>
    #endif
    #include<cctype>
    #include<cerrno>
    #include <cfloat>
    #include <ciso646>
    #include <climits>
    #include <clocale>
    #include <cmath>
    #include <csetjmp>
    #include <csignal>
    #include <cstdarg>
    #include <cstddef>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <ctime>
    #if __cplusplus >= 201103L
    #include <ccomplex>
    #include <cfenv>
    #include <cinttypes>
    #include <cstdalign>
    #include <cstdbool>
    #include <cstdint>
    #include <ctgmath>
    #include <cwchar>
    #include <cwctype>
    #endif
 
    // C++
    #include <algorithm>
    #include <bitset>
    #include <complex>
    #include <deque>
    #include <exception>
    #include <fstream>
    #include <functional>
    #include <iomanip>
    #include <ios>
    #include <iosfwd>
    #include <iostream>
    #include <istream>
    #include <iterator>
    #include <limits>
    #include <list>
    #include <locale>
    #include <map>
    #include <memory>
    #include <new>
    #include <numeric>
    #include <ostream>
    #include <queue>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <stdexcept>
    #include <streambuf>
    #include <string>
    #include <typeinfo>
    #include <utility>
    #include <valarray>
    #include <vector>
 
    #if __cplusplus >= 201103L
    #include <array>
    #include <atomic>
    #include <chrono>
    #include <condition_variable>
    #include <forward_list>
    #include <future>
    #include <initializer_list>
    #include <mutex>
    #include <random>
    #include <ratio>
    #include <regex>
    #include <scoped_allocator>
    #include <system_error>
    #include <thread>
    #include <tuple>
    #include <typeindex>
    #include <type_traits>
    #include <unordered_map>
    #include <unordered_set>
    #endif
```

建议初学的话还是老老实实一个个include比较好...

## bugs

exercise3_10.cpp 不知道为什么，只会输出空的字符串

exercise9_4.cpp 不知道为什么，不会等第二组输入



## 疑难杂症

* size_type ???

example:

    for (vector<int>::size_type i = 0; i != 10; ++i) {}


* process

一个函数需要返回一个pair，可以用花括号包围的初始化器来返回pair：

    pair<string, int>                             //？？？？？？这是什么操作？
    process(vector<string> &v) {
        //处理v
        if (!v.empty())
            return {v.back(), v.back().size()};  //列表初始化
        else
            return pair<string, int>();   //隐式构造返回值
    }
