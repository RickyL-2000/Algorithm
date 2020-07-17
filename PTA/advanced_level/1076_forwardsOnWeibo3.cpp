#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
int edges[1010][1010];
bool visited[1010];

int main() {
    scanf("%d %d", &n, &l);
    fill(edges[0], edges[0] + 1010*1010, 0);
    for (int i = 1; i <= n; i++) {
        int num, src;
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &src);
            edges[src][i] = 1;
        }
    }

    queue<pair<int, int>> q;
    int k, cnt;
    scanf("%d", &k);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        int cur;
        scanf("%d", &cur);

        while (!q.empty()) q.pop();
        fill(visited, visited + 1010, false);
        q.push(make_pair(cur, 0));
        cnt = -1;
        visited[cur] = true;
        pair<int, int> node;
        while (!q.empty()) {
            node = q.front(), q.pop();
            if (node.second <= l) cnt++;
            else break;
            for (int next = 1; next <= n; next++) {
                if (edges[node.first][next] && visited[next] == false) {
                    visited[next] = true;
                    q.push(make_pair(next, node.second+1));
                }
            }
        }
        ans.push_back(cnt);
    }
    for (int e : ans) printf("%d\n", e);
    return 0;
}