#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int _id;
    int _level;
};

vector<int> nodes[105];
int levelN[105];
bool visited[105];
int n, m, maxN, maxLevel, levelN_len;

void dfs(int root, int level) {
    visited[root] = true;
    levelN[level]++;
    if (levelN_len < level) levelN_len = level;
    for (size_t i = 0; i < nodes[root].size(); i++) {
        if (visited[nodes[root][i]] == false) {
            dfs(nodes[root][i], level+1);
        }
    }
}

int main() {
    cin >> n >> m;
    int k, id, child;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &id, &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &child);
            nodes[id].push_back(child);
        }
    }

    dfs(1, 1);

    for (int i = 1; i <= levelN_len; i++) {
        if (maxN < levelN[i]) {
            maxN = levelN[i];
            maxLevel = i;
        }
    }

    cout << maxN << ' ' << maxLevel;

    return 0;
}