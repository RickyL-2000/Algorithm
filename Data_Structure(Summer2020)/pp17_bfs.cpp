#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int edges[1010][1010];
bool visited[1010];

int main() {
    scanf("%d %d", &n, &m);
    fill(edges[0], edges[0] + 1010*1010, 0);
    int a1, a2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a1, &a2);
        edges[a1][a2] = 1, edges[a2][a1] = 1;
    }

    queue<pair<int, int>> q;
    int cnt;
    for (int cur = 1; cur <= n; cur++) {
        while (!q.empty()) q.pop();
        fill(visited, visited + 1010, false);
        cnt = 0;
        q.push(make_pair(cur, 0));
        visited[cur] = true;
        pair<int, int> node;
        while (!q.empty()) {
            node = q.front(), q.pop();
            if (node.second <= 6) cnt++;
            else break;
            for (int next = 1; next <= n; next++) {
                if (edges[node.first][next] && visited[next] == false) {
                    visited[next] = true;
                    q.push(make_pair(next, node.second+1));
                }
            }
        }
        printf("%d: %.2lf%\n", cur, (double)cnt / (double)n * 100);
    }
    return 0;
}