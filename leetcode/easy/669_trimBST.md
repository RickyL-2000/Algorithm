# Trim a Binary Search Tree

Given a binary search tree and the lowest and highest boundaries as L and R, trim the tree so that all its elements lies in [L, R] (R >= L). You might need to change the root of the tree, so the result should return the new root of the trimmed binary search tree.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/trim-a-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/16 60 min

主要是把时间花在自己写裁判程序上...

FAIL!

```
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
};
```

我就奇了怪了，我算出来的树明明结点和答案一样，只是结构不一样，怎么就错了呢？？？