# 112. Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,
```
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
```

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

## my sol 1     20/7/7      10 min

12 ms   84.38%

18.9 ms 100%

本来5min就写完了，结果没想到有这么多的坑

坑：
1. 空树的路径和不为零！
2. 只有一个孩子的节点不是叶子！

``` C++
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
private:
    set<int> path;
public:
    void dfs(TreeNode* root, int sum) {
        // if (root) {
        //     dfs(root->left, sum + root->val);
        //     dfs(root->right, sum + root->val);
        // } else {
        //     path.insert(sum);
        // }
        if (root->left) dfs(root->left, sum + root->val);
        if (root->right) dfs(root->right, sum + root->val);
        if (!root->left && !root->right) path.insert(sum + root->val);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        dfs(root, 0);
        if (path.find(sum) == path.end()) return false;
        return true;
    }
};
```

加注释的地方是错的，把只有一个孩子的节点也当作叶子节点了
