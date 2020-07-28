# 08-图7 公路村村通 (30分)

现有村落间道路的统计数据表中，列出了有可能建设成标准公路的若干条道路的成本，求使每个村落都有公路连通所需要的最低成本。

输入格式:
输入数据包括城镇数目正整数N（≤1000）和候选道路数目M（≤3N）；随后的M行对应M条道路，每行给出3个正整数，分别是该条道路直接连通的两个城镇的编号以及该道路改建的预算成本。为简单起见，城镇从1到N编号。

输出格式:
输出村村通需要的最低成本。如果输入数据不足以保证畅通，则输出−1，表示需要建设更多公路。

输入样例:
6 15
1 2 5
1 3 3
1 4 7
1 5 4
1 6 2
2 3 4
2 4 6
2 5 2
2 6 6
3 4 6
3 5 1
3 6 1
4 5 10
4 6 8
5 6 3
输出样例:
12

## my sol 1     20/7/27     24 min

2020/07/27 10:53:36	
答案正确
30	08-图7	C++ (g++)	5 ms	Ricky
测试点	提示	结果	耗时	内存
0	sample换数字，各种回路判断	
答案正确
3 ms	384 KB
1	M<N-1，不可能有生成树	
答案正确
2 ms	368 KB
2	M达到N-1，但是图不连通	
答案正确
3 ms	384 KB
3	最大N和M，连通	
答案正确
5 ms	640 KB
4	最大N和M，不连通	
答案正确
5 ms	640 KB

一道非常经典的MST题目，因为先稍微复习了下kruskal算法所以花了点时间，但是还算比较熟练

``` C++
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
```
