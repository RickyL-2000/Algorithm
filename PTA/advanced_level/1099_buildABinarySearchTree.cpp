#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, index;
struct Node {
    int _left, _right;
    int _val;
};
vector<Node*> tree;
vector<int> vals;

void inOrder(int root) {
    if (root != -1) {
        inOrder(tree[root]->_left);
        tree[root]->_val = vals[index];
        index++;
        inOrder(tree[root]->_right);
    }
}

int main() {
    cin >> n;
    int left, right;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &left, &right);
        Node* node = new Node;
        node->_left = left, node->_right = right;
        tree.push_back(node);
    }
    int val;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        vals.push_back(val);
    }
    sort(vals.begin(), vals.end());
    index = 0;
    inOrder(0);

    queue<Node*> q;
    q.push(tree[0]);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node != tree[0]) printf(" ");
        printf("%d", node->_val);
        if (node->_left != -1) q.push(tree[node->_left]);
        if (node->_right != -1) q.push(tree[node->_right]);
    }

    return 0;
}