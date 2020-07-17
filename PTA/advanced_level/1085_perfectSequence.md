# 1085_perfectSequence

## my sol 1     20/2/4      20 min

22/25

又把long long 的scanf()格式化字符搞错了，导致一个point过不去。改了就好了

但是，还是有一个过不去...倒数第二个...

> 1085_perfectSequence.cpp

## my sol 2

最后发现是自己算法有问题...可能两边同时夹中间达到最大值...

但是...seriously?

```
#include <iostream>
#include <algorithm>
using namespace std;

long long int nums[100010];

int main() {
    long long int p;
    int n;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        scanf("%Ld", &nums[i]);
    }

    sort(nums, nums+n);

    int curN, maxN = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j >= i; j--) {
            if (nums[j] <= nums[i] * p) {
                curN = j - i + 1;
                break;
            }
        }
        if (curN > maxN) maxN = curN;
    }

    cout << maxN;

    return 0;
}
```

我都从右边往左边算了还超时？

那好吧...

## my and ref sol 3

ok....

算是知道了为什么自己会超时了...这道题目的时间应该卡得很紧，然后可以用maxN来减少运算的时间：

只需要在内层循环中检测是否少于maxN个数字，如果少了就直接跳过这一层循环。那么我原来的算法也是可以的...

## my sol 3

超时...

很好，至少知道了我原来的算法还是不行的...

```
#include <iostream>
#include <algorithm>
using namespace std;

long long int nums[100010];

int main() {
    long long int p;
    int n;
    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        scanf("%Ld", &nums[i]);
    }

    sort(nums, nums+n);

    int curN, maxN = 0;
    for (int i = 0; i < 2*n; i++) {
        for (int j = n-1; j >= i + maxN; j--) {
            if (nums[j] <= nums[i] * p) {
                curN = j - i + 1;
                break;
            }
        }
        if (curN > maxN) maxN = curN;
    }

    cout << maxN;

    return 0;
}
```

↑这是修改后的原来的算法，还是不行，看来数据是真的紧...