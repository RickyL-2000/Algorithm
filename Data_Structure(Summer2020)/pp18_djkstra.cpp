#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 2147483647

int edges[110][110];
bool visited[110];
int parent[110];
vector<pair<int, int>*> nodes, pq, ans;
int n, m;

int main() {
    fill(edges[0], edges[0] + 110*110, -1);
    scanf("%d %d", &n, &m);
    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        edges[v1][v2] = w;
        edges[v2][v1] = w;
    }

    nodes.push_back(nullptr);
    for (int u = 1; u <= n; u++) {
        auto newP = new pair<int, int> (u, INF);
        nodes.push_back(newP);
    }

    auto cmp = [] (pair<int, int>* a1, pair<int, int>* a2) {
        return a1->second > a2->second;
    };

    bool connect = false;
    fill(parent, parent+110, 0);
    for (int v = 1; v <= n; v++) {
        fill(visited, visited + 110, false);
        for (int u = 1; u <= n; u++) {
            nodes[u]->second = INF;
        }
        nodes[v]->second = 0;
        if (!connect) parent[v] = v;
        pq = nodes;
        pair<int, int>* node;
        while (pq.size() > 1) {
            make_heap(pq.begin()+1, pq.end(), cmp);
            pop_heap(pq.begin()+1, pq.end(), cmp), 
            node = pq.back(), pq.pop_back();
            if (!connect && parent[node->first] == 0) {
                printf("0");
                return 0;
            }
            for (int u = 1; u <= n; u++) {
                if (edges[node->first][u] >= 0 && visited[u] == false) {
                    if (nodes[u]->second > nodes[node->first]->second + edges[node->first][u]) {
                        nodes[u]->second = nodes[node->first]->second + edges[node->first][u];
                        if (!connect) parent[u] = node->first;
                    }
                }
            }
        }
        connect = true;
        int max_dist = 0, idx;
        for (int i = 1; i <= n; i++) {
            if (max_dist < nodes[i]->second) {
                max_dist = nodes[i]->second, idx = i;
            }
        }
        auto newP = new pair<int, int> (idx, max_dist);
        ans.push_back(newP);
    }
    int min_dict = INF, idx;
    for (int i = 0; i < n; i++) {
        if (min_dict > ans[i]->second) {
            min_dict = ans[i]->second, idx = i;
        }
    }
    printf("%d %d", idx+1, min_dict);
    return 0;
}