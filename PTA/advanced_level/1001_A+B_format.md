# 1001 A+B format

Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input Specification:
Each input file contains one test case. Each case contains a pair of integers a and b where −106≤a,b≤10​6. The numbers are separated by a space.

Output Specification:
For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input:
-1000000 9
Sample Output:
-999,991

## my sol 1

> 1001_A+B_format.cpp

现在看我以前写的代码，感觉真的有点傻...

## ref sol 1

> 1001_A+B_format2.cpp

```
#include <iostream>
#include <string>
using namespace std;

int main() {
    long int a, b;
    scanf("%ld %ld", &a, &b);
    string ret = to_string(a+b);
    int len = ret.length();
    for (int i = 0; i < len; i++) {
        printf("%c", ret[i]);
        if (ret[i] == '-') continue;
        if ((i+1) % 3 == len % 3 && i != len - 1) printf(",");
    }
    return 0;
}
```

这里用了to_string()函数
