#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    vector<pair<int, int>> pre, next;
    int cost = 0;
};

Node* nodes[110];
bool visited[110];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
    }
    fill(visited, visited + 110, false);
    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        nodes[v1]->next.push_back(make_pair(v2, w)),
        nodes[v2]->pre.push_back(make_pair(v1, w));
    }
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        if (nodes[i]->pre.empty()) stk.push_back(i);
    }
    int cur;
    while (!stk.empty()) {
        cur = stk.back(), stk.pop_back();
        visited[cur] = true;
        sort(nodes[cur]->next.begin(), nodes[cur]->next.end(), [](pair<int, int> &a1, pair<int, int> &a2) {return a1.second < a2.second;});
        int w;
        for (auto next_p : nodes[cur]->next) {
            if (visited[next_p.first]) continue;
            // 判断是否是入度为零的点
            bool isZero = true;
            for (auto pre_p : nodes[next_p.first]->pre) {
                if (visited[pre_p.first] == false) {
                    isZero = false;
                    break;
                }
            }
            if (isZero) {
                stk.push_back(next_p.first);
                nodes[next_p.first]->cost = nodes[cur]->cost + next_p.second;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            printf("Impossible");
            return 0;
        }
    }
    int ans = 0;;
    for (int i = 0; i < n; i++) {
        ans = max(ans, nodes[i]->cost);
    }
    printf("%d", ans);
    return 0;
}
