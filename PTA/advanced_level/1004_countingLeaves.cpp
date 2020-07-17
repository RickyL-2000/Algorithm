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
        maxlevel = m    ax(maxlevel, depth);
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