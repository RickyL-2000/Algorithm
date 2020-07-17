#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int _val;
    Node* _left;
    Node* _right;
    Node(int x): _val(x), _left(nullptr), _right(nullptr) {}
};

vector<int> pre, in, post;
int stk[35], top = -1, vals[35], index = -1;

Node* buildT(int root, int begin, int end) {
    if (begin > end || root >= pre.size()) return nullptr;
    int i = begin;
    while (i < end && in[i] != pre[root]) i++;
    Node* node = new Node(vals[pre[root]]);
    Node* left = buildT(root+1, begin, i-1);
    Node* right = buildT(root+1+i-begin, i+1, end);
    node->_left = left;
    node->_right = right;
    return node;
}

void postTraverse(Node* root, vector<int>& post) {
    if (root != nullptr) {
        postTraverse(root->_left, post);
        postTraverse(root->_right, post);
        post.push_back(root->_val);
    }
}

int main() {
    int n, val;
    cin >> n;
    string command;
    for (int i = 0; i < 2*n; i++) {
        cin >> command;
        if (command.length() == 4)  {   // push
            cin >> val;
            vals[++index] = val;
            stk[++top] = index;
            pre.push_back(index);
        } else {
            in.push_back(stk[top--]);
        }
    }

    Node* root = buildT(0, 0, pre.size());

    postTraverse(root, post);

    cout << post[0];
    for (size_t i = 1; i < post.size(); i++) {
        cout << ' ' << post[i];
    }

    return 0;
}