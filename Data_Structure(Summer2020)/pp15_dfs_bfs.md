# 06-图1 列出连通集 (25point(s))

给定一个有N个顶点和E条边的无向图，请用DFS和BFS分别列出其所有的连通集。假设顶点从0到N−1编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第1行给出2个整数N(0<N≤10)和E，分别是图的顶点数和边数。随后E行，每行给出一条边的两个端点。每行中的数字之间用1空格分隔。

输出格式:
按照"{ v
​1
​​  v
​2
​​  ... v
​k
​​  }"的格式，每行输出一个连通集。先输出DFS的结果，再输出BFS的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }

## my sol 1     20/7/14     20 min

0	sample 两种顺序不同，也有相同，有未出现的单个顶点	
Accepted
3 ms	424 KB
1	第1个是单独点，最大N	
Accepted
3 ms	492 KB
2	N和E最小	
Accepted
4 ms	384 KB

**NOTE!** 在bfs的时候，更新visited一定要在push的时候！如果在pop的时候才更新，有可能会对同一个节点进行多次push！

``` C++
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
```
