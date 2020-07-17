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
int n, m, maxN, maxLevel, levelN_len;

void bfs(int root) {
    Node node;
    node._id = root, node._level = 1;
    queue<Node> q;
    q.push(node);
    while (!q.empty()) {
        Node top = q.front();
        q.pop();
        levelN[top._level]++;
        for (size_t i = 0; i < nodes[top._id].size(); i++) {
            node._id = nodes[top._id][i];
            node._level = top._level + 1;
            if (levelN_len < node._level) levelN_len = node._level;
            q.push(node);
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

    bfs(1);

    for (int i = 1; i <= levelN_len; i++) {
        if (maxN < levelN[i]) {
            maxN = levelN[i];
            maxLevel = i;
        }
    }

    cout << maxN << ' ' << maxLevel;

    return 0;
}