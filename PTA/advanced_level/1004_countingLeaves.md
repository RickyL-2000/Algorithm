# 1004 Counting Leaves

## my sol 1     20/1/20     30 min

基本上这是我第一次比较规范地写dfs的算法，而且这个答案也是我以及看过一遍柳婼的答案后写的，有很大程度上灵感来自与她。

```
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> tree(100);
// @attention 柳神在这里的写法是 vector<int> tree[100]，向量的数组
int level[100];
int maxlevel = -1;

void dfs(int index, int depth) {
    if (tree[index].size() == 0) {
        level[depth]++;
        maxlevel = max(maxlevel, depth);
        return;
    }
    for (int i = 0; i < tree[index].size(); i++) {
        dfs(tree[index][i], depth+1);
    }
}

int main() {
    int n, m, id, k, child;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> id >> k;
        for (int j = 0; j < k; j++) {
            cin >> child;
            tree[id].push_back(child);
        }
    }
    fill(level, level+100, 0);

    dfs(1, 0);

    printf("%d", level[0]);
    for (int i = 1; i <= maxlevel; i++) {
        printf(" %d", level[i]);
    }
    return 0;
}
```