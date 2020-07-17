# 124_BST_maximumPathSum

Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

## ref sol 1    20/6/21

``` C++
class Solution {
private:
    int maxSum = INT_MIN;

public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + leftGain + rightGain;

        // 更新答案
        maxSum = max(maxSum, priceNewpath);

        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
```

递归的算法啊...这算法确实妙啊，学一下再仿写。


## my sol 1     20/6/21     10 min

48 ms   54.29%

28.4 ms 7.69%

这个算法真是非常简洁，要说有什么缺点的话就是递归比较消耗内存

``` C++
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int maxSum = INT_MIN;
public:
    int maxGain(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftGain = max(maxGain(root->left), 0);
        int rightGain = max(maxGain(root->right), 0);
        int newSum = root->val + leftGain + rightGain;
        maxSum = max(maxSum, newSum);
        return root->val + max(leftGain, rightGain);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};

int main() {}
```
