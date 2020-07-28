#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[1010];

struct Edge {
    int src, dst;
    int w;
    Edge(int src, int dst, int w): src(src), dst(dst), w(w) {}
};

int find(int x) {
    return parent[x] < 0 ? x : parent[x] = find(parent[x]);
}

bool merge(int x1, int x2) {
    if ((x1 = find(x1)) == (x2 = find(x2))) return false;
    if (parent[x1] < parent[x2]) {
        parent[x1] += parent[x2];
        parent[x2] = x1;
    } else {
        parent[x2] += parent[x1];
        parent[x1] = x2;
    }
    return true;
}

int main() {
    fill(parent, parent + 1010, -1);
    int n, m;
    scanf("%d %d", &n, &m);
    vector<Edge*> edges;
    for (int i = 0; i < m; i++) {
        int v1, v2, w;
        // 这里到底需不需要写入两条边？
        scanf("%d %d %d", &v1, &v2, &w);
        edges.push_back(new Edge(v1, v2, w)),
        edges.push_back(new Edge(v2, v1, w));
    }
    sort(edges.begin(), edges.end(), [](Edge* e1, Edge* e2) {
        return e1->w < e2->w;
    });
    vector<Edge*> mst;
    int cnt = n, ans = 0;
    for (auto edge: edges) {
        if (merge(edge->src, edge->dst)) {
            mst.push_back(edge);
            cnt--;
        }
    }
    if (cnt > 1) printf("-1");
    else {
        for (auto edge: mst) {
            ans += edge->w;
        }
        printf("%d", ans);
    }
    return 0;
}