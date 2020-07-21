#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2147483647
#define MAXN 510

int n, m, s, d;
int edges[MAXN][MAXN][2];
int dist[MAXN];
int price[MAXN];
bool visited[MAXN];

int main() {
    fill(edges[0][0], edges[0][0] + MAXN*MAXN*2, INF);
    // for (int i = 0; i < MAXN; i++) fill(edges[i][0][0], edges[i][0][0] + MAXN * 2, INF);
    fill(visited, visited + MAXN, false);
    fill(dist, dist + MAXN, INF);
    fill(price, price + MAXN, INF);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    int c1, c2, l, p;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &c1, &c2, &l, &p);
        edges[c1][c2][0] = l, edges[c1][c2][1] = p,
        edges[c2][c1][0] = l, edges[c2][c1][1] = p;
    }

    dist[s] = 0, price[s] = 0;
    for (int i = 0; i < n; i++) {

        int cur, minD = INF;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && dist[j] < minD) {
                minD = dist[j], cur = j;
            }
        }

        visited[cur] = true;
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && edges[cur][v][0] != INF) {
                if (dist[v] > dist[cur] + edges[cur][v][0]) {
                    dist[v] = dist[cur] + edges[cur][v][0];
                    price[v] = price[cur] + edges[cur][v][1];
                } else if (dist[v] == dist[cur] + edges[cur][v][0] &&
                           price[v] > price[cur] + edges[cur][v][1]) {
                    price[v] = price[cur] + edges[cur][v][1];
                }
            }
        }
    }

    printf("%d %d", dist[d], price[d]);
    return 0;
}