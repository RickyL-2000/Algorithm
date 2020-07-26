#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    int Logn[1100];
    vector<pair<TreeNode*, int>> leaves;
    void pre() {
        Logn[1] = 0;
        Logn[2] = 1;
        for (int i = 3; i < 1100; i++) {
            Logn[i] = Logn[i / 2] + 1;
        }
    }
    void bfs(TreeNode* root) {
        int idx = 1, cur_idx;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, idx));
        TreeNode* cur;
        while (!q.empty()) {
            cur = q.front().first, cur_idx = q.front().second, q.pop();
            if (!cur->left && !cur->right) {
                leaves.push_back(make_pair(cur, cur_idx));
                continue;
            }
            if (cur->left) {
                q.push(make_pair(cur->left, cur_idx * 2));
            }
            if (cur->right) {
                q.push(make_pair(cur->right, cur_idx * 2 + 1));
            }
        }
    }
    int dist(int idx1, int idx2) {
        if (Logn[idx1] > Logn[idx2]) {
            return 1 + dist(idx1 / 2, idx2);
        } else if (Logn[idx1] < Logn[idx2]) {
            return 1 + dist(idx1, idx2 / 2);
        }
        if (idx1 == idx2) return 0;
        else return 2 + dist(idx1 / 2, idx2 / 2);
    }
public:
    int countPairs(TreeNode* root, int distance) {
        pre();
        bfs(root);
        int ret = 0, len = leaves.size();
        for (int i = 0; i < len-1; i++) {
            for (int j = i + 1; j < len; j++) {
                if (dist(leaves[i].second, leaves[j].second) <= distance) ret++;
            }
        }
        return ret;
    }
};

int main() {
    TreeNode* a90 = new TreeNode(90), *a49 = new TreeNode(49, nullptr, a90), *a54 = new TreeNode(54), *a9 = new TreeNode(9),
              *a97 = new TreeNode(97, nullptr, a54), *a60 = new TreeNode(60, nullptr, a49), *a12 = new TreeNode(12, nullptr, a9),
              *a56 = new TreeNode(56), *a66 = new TreeNode(66, a97, a60), *a55 = new TreeNode(55, a12, a56),
              *root = new TreeNode(15, a66, a55);
    Solution s;
    cout << s.countPairs(root, 5);
    return 0;
}