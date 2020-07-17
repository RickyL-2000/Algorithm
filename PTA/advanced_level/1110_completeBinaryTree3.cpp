#include <iostream>
using namespace std;

struct Node {
    int _left, _right;
};

int n, root = 0;
Node* tree[25];
bool notRoot[25];

int max_index = -1, last;
void dfs(int root, int index) {
    if (index > max_index) {
        max_index = index;
        last = root;
    }
    if (tree[root]->_left != -1) dfs(tree[root]->_left, 2*index);
    if (tree[root]->_right != -1) dfs(tree[root]->_right, 2*index+1);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        tree[i] = new Node;
        string l, r;
        cin >> l >> r;
        if (l == "-") tree[i]->_left = -1;
        else {
            tree[i]->_left = stoi(l);
            notRoot[tree[i]->_left] = true;
        }
        if (r == "-") tree[i]->_right = -1;
        else {
            tree[i]->_right = stoi(r);
            notRoot[tree[i]->_right] = true;
        }
    }
    while (notRoot[root]) root++;
    dfs(root, 1);   // index 从0开始，dfs里的计算也需要注意
    if (max_index == n) printf("YES %d", last);
    else printf("NO %d", root);
    return 0;
}