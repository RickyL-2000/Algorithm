#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<TreeNode*> tree;
        traverse(root, tree);
        TreeNode* ans = tree[0];
        for (int i = 0; i < tree.size()-1; i++) {
            (tree[i])->left = NULL;
            (tree[i])->right = tree[i+1];
        }
        tree[tree.size()-1]->left = NULL;
        tree[tree.size()-1]->right = NULL;
        return ans;
    }
    void traverse(TreeNode* node, vector<TreeNode*>& tree) {
        if (node != NULL) {
            traverse(node->left, tree);
            
            tree.push_back(node);

            traverse(node->right, tree);
        }
    }
};