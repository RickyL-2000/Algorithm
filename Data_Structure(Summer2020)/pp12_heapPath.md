# 05-树7 堆中的路径 (25分)

将一系列给定数字插入一个初始为空的小顶堆H[]。随后对任意给定的下标i，打印从H[i]到根结点的路径。

输入格式:
每组测试第1行包含2个正整数N和M(≤1000)，分别是插入元素的个数、以及需要打印的路径条数。下一行给出区间[-10000, 10000]内的N个要被插入一个初始为空的小顶堆的整数。最后一行给出M个下标。

输出格式:
对输入中给出的每个下标i，在一行中输出从H[i]到根结点的路径上的数据。数字间以1个空格分隔，行末不得有多余空格。

输入样例:
5 3
46 23 26 24 10
5 4 3
输出样例:
24 23 10
46 23 10
26 10

## my sol 1     20/7/3      30 min

不知道为啥今天特别困...就写的有点慢

``` C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAXN 20010

int heap[MAXN];
int len = 0;
// map<int, int> mp;

void sift_up(int idx) {
    if (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
        int temp = heap[idx];
        heap[idx] = heap[(idx - 1) / 2];
        heap[(idx - 1) / 2] = temp;
        // mp[heap[idx]] = idx;
        // mp[heap[(idx - 1) / 2]] = (idx - 1) / 2;
        sift_up((idx - 1) / 2);
    }
}

void insert(int num) {
    heap[len] = num;
    // mp[num] = len;
    len++;
    sift_up(len-1);
}


int main() {
    fill(heap, heap + MAXN, 10001);
    int n, m, num;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(num);
    }
    vector<vector<int>> ans;
    vector<int> path;
    int idx;
    for (int i = 0; i < m; i++) {
        scanf("%d", &idx);
        idx--;
        path.clear();
        while (idx >= 0) {
            path.push_back(heap[idx]);
            if (idx == (idx - 1) / 2) break;
            idx = (idx - 1) / 2;
        }
        ans.push_back(path);
    }
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
