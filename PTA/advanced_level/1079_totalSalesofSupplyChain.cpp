#include <iostream>
#include <vector>
using namespace std;

struct Node {
    bool isRet;
    vector<int> neighbors;
};

Node* nodes[100010];
bool visited[100010];   // 貌似不需要
int tot_num;
double price;
double r;

void dfs(int index, double mult, long double &sum) {
    visited[index] = true;
    if (nodes[index]->isRet) {
        sum += nodes[index]->neighbors[0] * price * mult;
        return;
    }
    for (size_t i = 0; i < nodes[index]->neighbors.size(); i++) {
        if (visited[nodes[index]->neighbors[i]] == false) {
            dfs(nodes[index]->neighbors[i], mult * (1+r/100), sum);
        }
    }
}

int main() {
    scanf("%d %lf %lf", &tot_num, &price, &r);
    for (int i = 0; i < tot_num; i++) {
        int nei_num;
        scanf("%d", &nei_num);
        Node* node = new Node;
        if (nei_num == 0) {
            node->isRet = true;
            int cus_num;
            scanf("%d", &cus_num);
            node->neighbors.push_back(cus_num);
        } else {
            node->isRet = false;
            int id;
            for (int j = 0; j < nei_num; j++) {
                scanf("%d", &id);
                node->neighbors.push_back(id);
            }
        }
        nodes[i] = node;
    }

    long double sum = 0.000;
    dfs(0, 1, sum);

    printf("%.1Lf", sum);

    return 0;
}