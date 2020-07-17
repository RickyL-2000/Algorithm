# 108. Convert Sorted Array to Binary Search Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5


## my sol 1     20/7/3      5 min

36 ms       34.38 %

23.1 mb     24%

就这？

但是我这个方法应该是最简单了吧，为啥成绩不咋地

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
public:
    TreeNode* biSearch(vector<int>& nums, int left, int right) {
        if (left <= right) {
            int mid = left + (right - left) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = biSearch(nums, left, mid-1);
            node->right = biSearch(nums, mid+1, right);
            return node;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return biSearch(nums, 0, nums.size()-1);
    }
};
```
