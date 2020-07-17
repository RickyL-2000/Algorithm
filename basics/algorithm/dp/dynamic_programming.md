# 动态规划

## 动态规划原理

我们关注适合应用动态规划方法求解的最优化问题应该具备的两个要素：最优子结构和子问题重叠。

### 最优子结构

如果一个问题的最优解包含其子问题的最优解，我们就称此问题具有最优子结构性质。（当然，具有最优子结构性质也可能意味着适合应用贪心策略）

在发掘最优子结构性质的过程中，实际上遵循了如下的通用模式：
1. 证明问题最优解的第一个组成部分是做出一个选择，例如，选择钢条第一次切割的位置，选择矩阵链的划分位置等。
2. 对于一个给定问题，在其可能的第一步选择中，你假定已经知道哪种选择才会得到最优解。
3. 给定可获得最优解的选择后，你确定这次选择会产生哪些子问题，以及如何最好地刻画子问题空间


### 重叠子问题

## 举例

### 钢条切割

问题：给定一段长度为n英寸的钢条和一个价格表，求切割钢条方案，使得销售收益rn最大。

考虑价格表：

| length |   1   |   2   |   3   |   4   |   5   |   6   |   7   |   8   |   9   |  10   |
| :----: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| price  |   1   |   5   |   8   |   9   |  10   |  17   |  17   |  20   |  24   |  30   |

考虑 n = 4 的情况

自顶向下递归实现:
```
int cut_rod(vector<int>& p, int n) {
    if (n == 0) return 0;
    int q = -INF;
    for (int i = 1; i <= n; i++) {
        q = max(q, p[i] + cut_rod(p, n-i));
    }
    return q;
}
```
我们将钢条从左边切割下长度为i的一段，只对右边剩下的长度为n-i的一段继续进行切割，对左边的一段则不再进行切割。

**但是！！**，这个方法的效率非常非常之低，因为它反复地用相同的参数对自己进行递归调用。

动态规划算法：对每个参数相同的子问题的结果保存下来，以后再遇到这个子问题，只需要查找保存的结果，而不必重新计算。一共有两种方法：
1. 带备忘的自顶向下法。
2. 自底向上法


自顶向下：
```
int memoized_cut_rod(vector<int>& p, int n) {
    vector<int> r(n+1);
    for(int i = 0; i <= n; i++) {
        r[i] = -INF;
    }
    return memoized_cut_rod_aux(p, n, r);
}

int memoized_cut_rod_aux(vector<int>& p, int n, vector<int>& r) {
    if (r[n] >= 0) return r[n];
    int q;
    if (n == 0) q = 0;
    else {
        q = -INF;
        for (int i = 1; i <= n; i++) {
            q = max(q, p[i] + mempozed_cut_rod_aux(p, n-i, r));
        }
    }
    r[n] = q;
    return q;
}
```

自底向上：（更为简单）
```
int bottom_up_cut_rod(vector<int>& p, int n) {
    vector<int> r(n+1);
    r[0] = 0;
    for (int j = 1; j <= n; j++) {
        int q = -INF;
        for (int i = 1; i <= j) {
            q = max(q, p[i]+r[j-i]);
        }
        r[j] = q;
    }
    return r[n];
}
```

重构解
```
vector<vector<int>> extenede_bottom_up_cut_rod(vector<int>& p, int n) {
    vector<int> r(n+1);
    vector<int> s(n+1);
    r[0] = 0;
    int q;
    for (int j = 1; j <= n; j++) {
        q = -INF;
        for (int i = 1; i <= j; i++) {
            if (q < p[i] + r[j - i]) {
                q = p[i] + r[j - i];
                s[j] = i;
            }
            r[j] = q;
        }
    }
    return {r, s}
}
```

practice:
1. leetcode/hard/checkSubarraySum.cpp



### 最长公共子序列

