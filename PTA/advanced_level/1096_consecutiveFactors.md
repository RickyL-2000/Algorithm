# 1096_consecutiveFactors

## my sol 1     20/2/12     30 min

我好像把题目理解错了....

这个factors....有点难啊

啥叫list the smallest sequence of the consecutive factors？

那就不知道怎么做了

```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    vector<int> factors;
    int maxNum, pre, minLen = 999999999, begin, len, minBegin;
    for (long long int i = 2; i * i <= n; i++) {
        if (i * i == n) {
            n = i;
        } else if (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }
    sort(factors.begin(), factors.end());
    pre = factors[0];
    begin = 0;
    maxNum = 1;
    len = 1;
    for (size_t i = 1; i < factors.size(); i++) {
        if (factors[i] = pre + 1) {
            maxNum++;
            len++;
            pre = factors[i];
        } else if (factors[i] = pre) {
            continue;
        } else {
            if (len < minLen && len != 1) {
                minLen = len;
                minBegin = begin;
            }
            len = 1;
            begin = i;
        }
    }
    cout << maxNum << endl;
    int index = 1, cnt = 0;
    pre = factors[minBegin];
    printf("%d", factors[minBegin]);
    while (cnt != minLen) {
        while (factors[index] == pre) {
            index++;
        }
        cnt++;
        printf("*%d", factors[index]);
        index++;
    }
    return 0;
}
```

## ref sol 1

> 1096_consecutiveFactors.cpp

没太看懂这写了啥...感觉还是没有理解题意...