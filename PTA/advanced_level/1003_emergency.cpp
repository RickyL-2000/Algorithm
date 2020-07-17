/**
 * @bug FIXME: can't pass some tests! 
 */

#include <iostream>
#include <algorithm>
using namespace std;

/**
 * @details
 * use matrix to represent edges, the values are costs
 * use dist[N] to represent shortest distance
 * use teams[N] to represent the num of teams
 * use num[i] to represent the num of ways to city i
 * use sum_team[N] to store the most num of team to city i
 * use visited[N] to represent if a city is visited (to analog undirected graph)
 */

int edge[550][550],
    dist[550],
    num[550],
    team[550],
    sum_team[550];
bool visited[550];
const int INF = 99999999;

int main() {
    // init
    fill(edge[0], edge[0] + 550*550, INF);
    fill(dist, dist + 550, INF);
    fill(visited, visited + 550, false);

    int N, M, C1, C2;
    // scanf("%d %d %d %d", &N, &M, &C1, &C2);
    cin >> N >> M >> C1 >> C2;
    for (int i = 0; i < N; i++) {
        // scanf("%d", &team[i]);
        cin >> team[i];
        visited[i] = false;
    }
    for (int i = 0; i < M; i++) {
        int c1, c2, w;
        // scanf("%d %d %d", &c1, &c2, &w);
        cin >> c1 >> c2 >> w;
        edge[c1][c2] = edge[c2][c1] = w;
    }

    dist[C1] = 0;
    num[C1] = 1;
    sum_team[C1] = team[C1];
    for (int i = 0; i < N; i++) {   // outer loop
        // find the min ele
        int u = 0, min = INF;
        for (int j = 0; j < N; j++) {
            if (dist[j] < min && visited[j] == false) {
                u = j;
                min = dist[j];
            }
        }
        // if (u == -1) break;
        visited[u] = true;
        for (int j = 0; j < N-1; j++) {
            if (edge[u][j] != INF && visited[j] == false) {
                if (dist[j] > dist[u] + edge[u][j]) {   // relax
                    dist[j] = dist[u] + edge[u][j];
                    num[j] = num[u];
                    sum_team[j] = sum_team[u] + team[j];
                } else if (dist[j] == dist[u] + edge[u][j]) {
                    num[j] = num[u] + num[j];
                    if (sum_team[u] + team[j] > sum_team[j]) 
                        sum_team[j] = sum_team[u] + team[j];
                }
            }
        }
    }
    printf("%d %d", num[C2], sum_team[C2]);
    return 0;
}