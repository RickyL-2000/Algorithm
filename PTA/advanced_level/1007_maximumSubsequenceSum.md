# maximum Subsequence Sum

## my sol 1     20/1/20     30 min

欸我佛了，为什么还是有一个测试点没有过去...

而且还不告诉我测试样例是什么！

```
#include <iostream>
using namespace std;

int dp[10050][3];   // dp[0] val, dp[1] first's val, dp[2] last's val

int main() {
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> dp[i][0];
    }
    dp[0][1] = dp[0][2] = dp[0][0];
    int maxn = 0;
    for (int i = 1; i < k; i++) {
        if (dp[i-1][0] + dp[i][0] > dp[i][0]) {
            dp[i][2] = dp[i][0];
            dp[i][1] = dp[i-1][1];
            dp[i][0] = dp[i-1][0] + dp[i][0];
        } else {
            dp[i][1] = dp[i][2] = dp[i][0];     // last is itself
        }
        if (dp[i][0] > dp[maxn][0]) maxn = i;
    }
    cout << dp[maxn][0] << ' ' << dp[maxn][1] << ' ' << dp[maxn][2] << endl;
    return 0;
}
```

## my sol 2     20/1/20     15 min

吐血...

在重构代码过程中几乎重新写了一遍，结果发现有一个测试点没有过去的原因居然是没有看清题目...

```
#include <iostream>
using namespace std;

int dp[10050][2];   // dp[0] first val, dp[1] last val

int main() {
    int k;
    cin >> k;

    int thisSum, cur, maxIndex = 0, maxN;
    if (k) cin >> thisSum;
    dp[0][0] = dp[0][1] = maxN = thisSum;

    bool allNegative = true;
    int first = dp[0][0], last = dp[0][0];
    for (int i = 1; i < k; i++) {
        cin >> cur;
        if (cur >= 0) allNegative = false;
        if (i == k-1) last = cur;
        if (thisSum < 0) {
            dp[i][0] = dp[i][1] = cur;
            thisSum = cur;
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = cur;
            thisSum += cur;  
        }
        if (thisSum > maxN) {
            maxIndex = i;
            maxN = thisSum;
        }
    }
    if (allNegative) {
        cout << 0 << ' ' << first << ' ' << last << endl;
    } else
        cout << maxN << ' ' << dp[maxIndex][0] << ' ' << dp[maxIndex][1] << endl;
    return 0;
}
```

又是吐血...本以为这样改好了就能过了...结果同一个测试点还是过不了.......

先不搞了....


## my sol 3 

用 Kadane 算法 做!