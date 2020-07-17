#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, e;
int edges[11][11];
bool visited[11];

void dfs(int node, vector<int> &part) {
    visited[node] = true;
    part.push_back(node);
    for (int v = 0; v < n; v++) {
        if (edges[node][v] && visited[v] == false) {
            dfs(v, part);
        }
    }
}

void bfs(int node, vector<int> &part) {
    queue<int> q;
    q.push(node);
    visited[node] = true;
    int v;
    while (!q.empty()) {
        v = q.front(), q.pop();
        part.push_back(v);
        for (int u = 0; u < n; u++) {
            if (edges[v][u] && visited[u] == false) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    fill(edges[0], edges[0] + 11*11, 0);
    scanf("%d %d", &n, &e);
    int node1, node2;
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &node1, &node2);
        edges[node1][node2] = 1;
        edges[node2][node1] = 1;
    }
    fill(visited, visited + 11, false);
    vector<vector<int>> ans;
    for (int v = 0; v < n; v++) {
        if (visited[v] == false) {
            vector<int> part;
            dfs(v, part);
            ans.push_back(part);
        }
    }
    for (auto p : ans) {
        printf("{ ");
        for (int i : p) {
            printf("%d ", i);
        }
        printf("}\n");
    }
    ans.clear();
    fill(visited, visited + 11, false);
    for (int v = 0; v < n; v++) {
        if (visited[v] == false) {
            vector<int> part;
            bfs(v, part);
            ans.push_back(part);
        }
    }
    for (auto p : ans) {
        printf("{ ");
        for (int i : p) {
            printf("%d ", i);
        }
        printf("}\n");
    }
    return 0;
}