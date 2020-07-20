#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define INF 1e308

struct Node{
    int x, y;
    int id;
    // double dist = INF;
    int dist = INT_MAX;     // 距离是节点的数量
    vector<Node*> parent = {};
    Node() = default;
    Node(int id, int x, int y): id(id), x(x), y(y) {}
};

bool visited[110];
vector<Node*> nodes, pq, dsts;
vector<vector<Node*>> ans;
int n, d;

double distance(Node* a1, Node* a2) {
    if (a1 == a2) return INF;
    return sqrt((double) (a1->x - a2->x) * (a1->x - a2->x) + (double) (a1->y - a2->y) * (a1->y - a2->y));
}

void dfs(Node* root, vector<Node*>& path) {
    if (root->parent[0] == root) {
        ans.push_back(path);
    }
    path.push_back(root);
    for (auto node : root->parent) {
        dfs(node, path);
        path.pop_back();
    }
}

int main() {
    fill(visited, visited + 110, false);
    scanf("%d %d", &n, &d);
    int x, y;
    Node* root = new Node(0, 0, 0);
    root->parent = {root};
    nodes.push_back(root);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        Node* newNode = new Node(i, x, y);
        nodes.push_back(newNode);
    }
    pq = nodes;

    auto cmp = [](Node* a1, Node* a2) {
        return a1->dist > a2->dist;
    };

    bool flag = false;
    Node* cur = nullptr;
    while (!pq.empty()) {
        make_heap(pq.begin(), pq.end(), cmp);
        pop_heap(pq.begin(), pq.end(), cmp), cur = pq.back(), pq.pop_back();
        visited[cur->id] = true;
        if (cur->parent.empty()) {
            flag = true;
            break;
        }
        if (abs(abs(cur->x) - 50) <= d || abs(abs(cur->y) - 50) <= d) {
            dsts.push_back(cur);
            continue;
        }
        for (int v = 1; v <= n; v++) {
            if (distance(cur, nodes[v]) <= (double) d && visited[v] == false) {
                if (nodes[v]->dist > cur->dist + 1) {
                    nodes[v]->dist = cur->dist + 1;
                    nodes[v]->parent = {cur};
                }
                if (nodes[v]->dist == cur->dist + 1) {
                    nodes[v]->parent.push_back(cur);
                }
            }
        }
    }

    if (flag) {
        printf("0");
        return 0;
    }
    
    sort(dsts.begin(), dsts.end(), [] (Node* a1, Node* a2) {return a1->dist < a2->dist;});
    int min_dist = dsts[0]->dist;
    for (auto dst : dsts) {
        if (dst->dist > min_dist) break;
        vector<Node*> temp;
        dfs(dst, temp);
    }

    double minD = INF; int idx;
    for (int i = 0, len = ans.size(); i < len; i++) {
        if (distance(ans[i][ans[i].size()-1], root) < minD) {
            minD = distance(ans[i][ans[i].size()-1], root);
            idx = i;
        }
    }

    printf("%d\n", min_dist);
    for (int i = 0; i < min_dist-1; i++) {
        auto node = ans[idx][ans[idx].size()-1-i];
        printf("%d %d\n", node->x, node->y);
    }
    return 0;
}