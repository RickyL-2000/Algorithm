#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// for convenience, assume that -1 <-> null

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<vector<TreeNode*>> levels;
        vector<vector<int>> stk;
        levels.push({root});
        while (!levels.empty()) {
            vector<TreeNode*> cur_level = levels.front();
            levels.pop();
            vector<TreeNode*> next_level;
            vector<int> cur_vals;
            for (int i = 0; i < cur_level.size(); i++) {
                if (cur_level[i] != NULL) {
                    if (cur_level[i]->left != NULL) next_level.push_back(cur_level[i]->left);
                    if (cur_level[i]->right != NULL) next_level.push_back(cur_level[i]->right);
                    cur_vals.push_back(cur_level[i]->val);
                }
            }
            if (!next_level.empty())
                levels.push(next_level);
            if (!cur_vals.empty())
                stk.push_back(cur_vals);
        }
        vector<vector<int>> ans;
        for (int i = stk.size()-1; i >= 0; i--) {
            ans.push_back(stk[i]);
        }
        return ans;
    }
    void buildT(vector<int>& arr, int index, TreeNode* root) {
        if (2*index+1 < arr.size() && arr[2*index+1] != -1) {
            TreeNode* leftN = new TreeNode(arr[2*index+1]);
            root->left = leftN;
            buildT(arr, 2*index+1, leftN);
        }
        if (2*index+2 < arr.size() && arr[2*index+2] != -1) {
            TreeNode* rightN = new TreeNode(arr[2*index+2]);
            root->right = rightN;
            buildT(arr, 2*index+2, rightN);
        }
    }
    void test() {
        vector<int> tree = {1, -1, 2};
        TreeNode* root = new TreeNode(tree[0]);
        buildT(tree, 0, root);
        vector<vector<int>> ans = levelOrderBottom(root);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << ' ';
            }
        }
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}