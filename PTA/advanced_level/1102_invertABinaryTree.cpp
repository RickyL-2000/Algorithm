#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int _key, _left, _right;
};

int n, root;
vector<Node*> nodes;
vector<int> ans;
bool notRoot[12];

void levelOrder() {
    queue<Node*> q;
    q.push(nodes[root]);
    while (!q.empty()) {
        Node* node = q.front(); q.pop();
        if (node != nodes[root]) printf(" ");
        printf("%d", node->_key);
        if (node->_right != -1) {
            q.push(nodes[node->_right]);
        }
        if (node->_left != -1) {
            q.push(nodes[node->_left]);
        }
    }
}

void inOrder(int index) {
    if (index != -1) {
        inOrder(nodes[index]->_right);
        ans.push_back(nodes[index]->_key);
        inOrder(nodes[index]->_left);
    }
}

int main() {
    cin >> n;
    char left, right;
    for (int i = 0; i < n; i++) {
        cin >> left >> right;
        Node* node = new Node;
        node->_key = i;
        if (left != '-') {
            node->_left = left - '0';
            notRoot[node->_left] = true;
        } else node->_left = -1;
        if (right != '-') {
            node->_right = right - '0';
            notRoot[node->_right] = true;
        } else node->_right = -1;
        nodes.push_back(node);
    }
    for (int i = 0; i < n; i++) {
        if (!notRoot[i]) {
            root = i;
            break;
        }
    }

    levelOrder();
    printf("\n");
    ans.clear();
    inOrder(root);
    for (int i = 0;  i < ans.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", ans[i]);
    }

    return 0;
}