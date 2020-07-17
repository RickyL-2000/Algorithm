#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define INF = __DBL_MAX__

struct Node {
    int id;
    int x, y;
    double dist = __DBL_MAX__;
    Node* parent = nullptr;
    Node (int id, int x, int y): id(id), x(x), y(y) {}
    Node () = default;
};

double distance(Node* a, Node* b) {
    return sqrt((double)((a->x - b->x) * (a->x - b->x)) + 
                (double)((a->y - b->y) * (a->y - b->y)));
}

int lake[110][110];
vector<Node*> pq;
bool visited[110];
int n, d;

int main() {
    scanf("%d %d", &n, &d);
    fill(lake[0], lake[0] + 110 * 110, -1);
    int x, y;
    auto cmp = [] (Node* a, Node* b) {return a->dist > b->dist;};
    Node* root = new Node(0, 0, 0);
    root->dist = 0.0;
    root->parent = root;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        Node* newNode = new Node(i, x, y);
        lake[x+50][y+50] = i;
        // if (distance(newNode, root) <= 7.5) newNode->dist = 0;  // 中央小岛
        pq.push_back(newNode);
    }
    lake[50][50] = 0;
    pq.push_back(root);
    // make_heap(pq.begin(), pq.end(), cmp);
    visited[0] = true;
    Node* cur = nullptr;
    while (!pq.empty()) {
        make_heap(pq.begin(), pq.end(), cmp);
        pop_heap(pq.begin(), pq.end(), cmp);
        cur = pq.back();
        pq.pop_back();
        visited[cur->id] = true;
        // 判断是否已经穷尽所有能到的地方
        if (cur->parent == nullptr) {
            printf("No");
            return 0;
        }
        // 判断是否可以到边界
        if (abs(abs(cur->x) - 50) <= d || abs(abs(cur->y) - 50) <= d) {
            printf("Yes");
            return 0;
        }
        int len = pq.size();
        for (int i = 0; i < len; i++) {
            // 判断当前点是否在岛上
            if (cur == root) {
                // 判断是否为邻居
                double dist = distance(pq[i], cur);
                if (dist - 7.5 <= (double) d && visited[pq[i]->id] == false) {
                    // 判断是否需要松弛
                    if (pq[i]->dist > cur->dist + dist - 7.5) {
                        pq[i]->dist = cur->dist + dist - 7.5;
                        pq[i]->parent = cur;
                    }
                }  
            } else {
                // 判断是否为邻居
                double dist = distance(pq[i], cur);
                if (dist <= (double) d && visited[pq[i]->id] == false) {
                    // 判断是否需要松弛
                    if (pq[i]->dist > cur->dist + dist) {
                        pq[i]->dist = cur->dist + dist;
                        pq[i]->parent = cur;
                    }
                }
            }
        }
    }
    printf("No");
    return 0;
}