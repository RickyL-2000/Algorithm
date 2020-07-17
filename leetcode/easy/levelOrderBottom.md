# Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

## my solution 1    20/1/15     90 min

time    12  55.84%

mem     14.3    28.52%

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
};
```

确实是很繁琐！

## reference solution 1

```
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root,0,res);
        return vector<vector<int>>(res.rbegin(),res.rend());    // 还有这种操作？？？
    }
        
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res) 
    {
        if(!node) return ;
        if(res.size()==level) res.push_back({});
        res[level].push_back(node->val);    // res内部的向量就是由层数标号的！
        if(node->left) levelorder(node->left,level+1, res);
        if(node->right) levelorder(node->right,level+1,res);
    }
    
};
```

比我第一个方法的优势：
1. 利用了vectore<vector<int>> 中的向量就是由层数标号这一个特征，就不需要申请很多复杂的容器了
2. 利用了rbegin()和rend()，省去了申请一个stack的麻烦