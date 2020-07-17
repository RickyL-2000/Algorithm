#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

struct Node {
    int _left, _right;
    int _level = 0;
};

int n, root;
vector<int> depth[25];
Node* tree[25];
bool isRoot[25];
int max_d = 0;

int main() {
    cin >> n;
    fill(isRoot, isRoot + n, true);
    string l_s, r_s;
    int l, r;
    for (int i = 0; i < n; i++) {
        Node* node = new Node;
        cin >> l_s >> r_s;
        if (l_s == "-") {
            node->_left = -1;
        } else {
            sscanf(l_s.c_str(), "%d", &l);
            isRoot[l] = false;
            node->_left = l;
        }
        if (r_s == "-") {
            node->_right = -1;
        } else {
            sscanf(r_s.c_str(), "%d", &r);
            isRoot[r] = false;
            node->_right = r;
        }
        tree[i] = node;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (isRoot[i]) {
            q.push(root = i);
            break;
        }
    }
    int last;
    bool pre = true, cur_l = true, cur_r = true, isComp = true;
    while (!q.empty()) {
        int top = q.front(); q.pop();
        last = top;
        depth[tree[top]->_level].push_back(top);
        if (max_d < tree[top]->_level) max_d = tree[top]->_level;
        if (tree[top]->_left != -1) {
            tree[tree[top]->_left]->_level = tree[top]->_level + 1;
            q.push(tree[top]->_left);
        } else {
            cur_l = false;
        }
        if (tree[top]->_right != -1) {
            tree[tree[top]->_right]->_level = tree[top]->_level + 1;
            q.push(tree[top]->_right);
        } else {
            cur_r = false;
        }
        // check if full 
        if ((cur_l == false && cur_r == true) || (pre == false && (cur_l == true || cur_r == true))) {
            isComp = false;
        }
        pre = cur_r;
    }

    for (int d = 0; d < max_d; d++) {
        if (depth[d].size() != (int)pow(2.0, (double)d) || !isComp) {
            printf("NO %d", root);
            return 0;
        }
    }

    printf("YES %d", last);
    return 0;    
}