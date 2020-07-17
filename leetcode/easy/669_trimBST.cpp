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

class Solution {
public:
    void flatT(TreeNode* root, vector<TreeNode*>& tree) {
        if (root != NULL) {
            flatT(root->left, tree);
            tree.push_back(root);
            flatT(root->right, tree);
        }
    }
    TreeNode* buildT(vector<TreeNode*>& tree, int left, int right) {
        if (left <= right) {
            int mid = (left + right)/2;
            TreeNode* new_root = tree[mid];
            new_root->left = buildT(tree, left, mid-1);
            new_root->right = buildT(tree, mid+1, right);
            return new_root;
        }
        return NULL;
    }
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        vector<TreeNode*> tree;
        flatT(root, tree);
        int left, right;
        for (int i = 0; i < tree.size(); i++) {
            if (L == tree[i]->val) left = i;
            if (R == tree[i]->val) right = i;
        }
        TreeNode* new_root = buildT(tree, left, right);
        return new_root;
    }
    void test() {
        vector<int> tree_int = {0,1,2};
        int L = 1, 
            R = 2;
        TreeNode* root = buildT_from_int(tree_int, 0, tree_int.size()-1);
        printT(root);
        TreeNode* ans = trimBST(root, L, R);
        printT(ans);
    }
    TreeNode* buildT_from_int(vector<int>& tree_int, int left, int right) {
        if (left <= right) {
            int mid = (left + right)/2;
            TreeNode* new_root = new TreeNode(tree_int[mid]);
            new_root->left = buildT_from_int(tree_int, left, mid-1);
            new_root->right = buildT_from_int(tree_int, mid+1, right);
            return new_root;
        }
        return NULL;
    }
    void printT(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* cur;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            if (cur == NULL) cout << "null ";
            else cout << cur->val << ' ';
            if (cur != NULL && (cur->left != NULL || cur->right != NULL)) {
                que.push(cur->left);
                que.push(cur->right);
            }
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}