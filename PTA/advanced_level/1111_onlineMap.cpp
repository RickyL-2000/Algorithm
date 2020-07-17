#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 999999999;
int n, m;
int src, dst;
int l_edge[510][510], t_edge[510][510];
int dist[510], cost[510];   // dist is the sum of len, cost is the sum of t_edge
int len_pre[510], time_pre[510];
int path_nodes[510], dist_cost[510];    // used in dist calc, for the fastest path among the same dist paths
bool visited[510];

int main() {
    cin >> n >> m;
    fill(l_edge[0], l_edge[0]+510*510, INF);
    fill(t_edge[0], t_edge[0]+510*510, INF);
    fill(len_pre, len_pre+510, -1);
    fill(time_pre, time_pre+510, -1);
    for (int i = 0; i < m; i++) {
        int v1, v2, is_one_way, len, t;
        scanf("%d %d %d %d %d", &v1, &v2, &is_one_way, &len, &t);
        l_edge[v1][v2] = len;
        t_edge[v1][v2] = t;
        if (!is_one_way) {
            l_edge[v2][v1] = len;
            t_edge[v2][v1] = t;
        }
    }
    scanf("%d%d", &src, &dst);

    fill(dist, dist+510, INF);
    fill(cost, cost+510, INF);
    dist[src] = 0; cost[src] = 0;
    len_pre[src] = -1; time_pre[src] = -1;
    path_nodes[src] = 0;
    for (int i = 0; i < n; i++) {
        int u, min_cost = INF+1;
        // finding the least
        for (int j = 0; j < n; j++) {
            if (cost[j] < min_cost && visited[j] == false) {
                u = j;
                min_cost = cost[j];
            }
        }
        visited[u] = true;
        // release
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && t_edge[u][j] != INF) {
                if (cost[j] > cost[u] + t_edge[u][j]) {
                    cost[j] = cost[u] + t_edge[u][j];
                    time_pre[j] = u;
                    path_nodes[j] = path_nodes[u] + 1;
                } else if (cost[j] == cost[u] + t_edge[u][j]) {
                    if (path_nodes[u] + 1 < path_nodes[j]) {
                        time_pre[j] = u;
                        path_nodes[j] = path_nodes[u] + 1;
                    }
                }
            }
        }
    }
    fill(visited, visited+510, false);
    fill(dist_cost, dist_cost+510, INF);
    dist_cost[src] = 0;
    for (int i = 0; i < n; i++) {
        int u, min_dist = INF+1;
        for (int j = 0; j < n; j++) {
            if (dist[j] < min_dist && visited[j] == false) {
                min_dist = dist[j];
                u = j;
            }
        }
        visited[u] = true;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && l_edge[u][j] != INF) {
                if (dist[j] > dist[u] + l_edge[u][j]) {
                    dist[j] = dist[u] + l_edge[u][j];
                    len_pre[j] = u;
                    dist_cost[j] = dist_cost[u] + t_edge[u][j];
                } else if (dist[j] == dist[u] + l_edge[u][j]) {
                    if (dist_cost[u] + t_edge[u][j] < dist_cost[j]) {
                        len_pre[j] = u;
                        dist_cost[j] = dist_cost[u] + t_edge[u][j];
                    }
                }
            }
        }
    }
    
    vector<int> len_path, time_path;
    int index = dst;
    while (index != -1) {
        len_path.push_back(index);
        index = len_pre[index];
    }
    index = dst;
    while (index != -1) {
        time_path.push_back(index);
        index = time_pre[index];
    }
    if (len_path == time_path) {
        printf("Distance = %d; Time = %d: ", dist[dst], cost[dst]);
        for (int i = len_path.size()-1; i >= 0; i--) {
            printf("%d", len_path[i]);
            if (i != 0) printf(" -> ");
        }
    } else {
        printf("Distance = %d: ", dist[dst]);
        for (int i = len_path.size()-1; i >= 0; i--) {
            printf("%d", len_path[i]);
            if (i != 0) printf(" -> ");
        }
        printf("\n");
        printf("Time = %d: ", cost[dst]);
        for (int i = time_path.size()-1; i >= 0; i--) {
            printf("%d", time_path[i]);
            if (i != 0) printf(" -> ");
        }
    }

    return 0;
}