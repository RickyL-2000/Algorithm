# Increasing Order Search Tree

Given a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only 1 right child.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/increasing-order-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/14 40 min

FAIL

唉，心累

> increasingBST.cpp

## my solution 2    20/1/14 20 min

FAIL

emmmm

```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> tree;
        traverse(root, tree);
        TreeNode newRoot(-1);
        TreeNode* ans = &newRoot, *ptr = &newRoot;
        for (int i = 0; i < tree.size(); i++) {
            if (ptr->val == -1) {
                ptr->val = tree[i];
            } else {
                ptr->right = new TreeNode;
                ptr = ptr->right;
                ptr->val = tree[i];
            }
        }
        return ans;
    }
    void traverse(TreeNode* node, vector<int>& tree) {
        if (node != NULL) {
            traverse(node->left, tree);
            
            tree.push_back(node->val);

            traverse(node->right, tree);
        }
    }
};
```

## reference solution 1

> increasingBST2.cpp

## my solution 3    20/1/14 15 min

终于通过了！！！！！！

ohhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh!

time:   28 ms   99.65%

memory: 19.1 mb 86.58%

> increasingBST3.cpp

```
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
```