# 1077 Kuchiguse

## my sol 1     20/1/28     20 min

遇到了两个问题，导致一个测试点没有过。不过稍微改了一下就过了。在这里记录一下关于测试点的测试（狗头）

代码:
> 1077_kuchiguse.cpp

```
#include <iostream>
#include <vector>
using namespace std;

int minSuffix(vector<string>& lines, int minLen, int num) {
    int index = 0;
    while (index < minLen) {
        char cur = lines[0][lines[0].length()-1-index];
        for (int i = 1; i < num; i++) {
            if (lines[i][lines[i].length()-1-index] != cur) {
                return index-1;
            }
        }
        index++;
    }
    return index-1;
}

int main() {
    int num;
    scanf("%d\n", &num);
    vector<string> lines(num, "");
    int minLen = 99999999;
    for (int i = 0; i < num; i++) {
        getline(cin, lines[i]);
        if (lines[i].length() < minLen) minLen = lines[i].length();
    }

    if (minLen == 0) { printf("nai");   return 0; }
    
    int index = minSuffix(lines, minLen, num);

    if (index == -1) { printf("nai");   return 0; }

    while (lines[0][lines[0].length()-1-index] == ' ') index--;
    int j = 0;
    while (lines[0][lines[0].length()-1-j] == ' ') j++;

    for (int i = index; i >= j; i--) {
        printf("%c", lines[0][lines[0].length()-1-i]);
    }

    return 0;
}
```

1. 改动的第一个地方就是35~37行的循环，用于把答案中头尾的空格删去
2. 改动的第二个地方是16行，这也是对该测试点有效的改动

而16行对应的测试点，我猜，应该是这种情况：
```
3
cccccc
cccccccc
cccc
```
结果我输出了```ccccc```

也就是说，是**重复多次的字符串，一种极端情况**

**所以测试样例一般对应于两种一般情况，三种极端情况**