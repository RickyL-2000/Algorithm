#include <iostream>
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
        TreeNode newRoot(-1);
        TreeNode* ans = &newRoot, *ptr = &newRoot;
        traverse(root, ptr);
        return ans;
    }
    void traverse(TreeNode* node, TreeNode* newNode) {
        if (node != NULL) {
            traverse(node->left, newNode);
            
            if (newNode->val == -1) {   // empty root
                newNode->val = node->val;
            } else {
                TreeNode newn(node->val);
                newNode->right = &newn;
                newNode = newNode->right;
            }

            traverse(node->right, newNode);
        }
    }
    void printT(TreeNode* node) {
        if (node != NULL) {
            printT(node->left);
            cout << node->val << ' ';
            printT(node->right);
        }
    }
    TreeNode* buildT(vector<int> arr) {
        int left = 0,
            right = arr.size() - 1,
            mid = left + (right - left) / 2;
        TreeNode* root;
        linkNodes(arr, root, left, mid, right);
    }
    void linkNodes(vector<int> arr, TreeNode* node, int left, int mid, int right) {
        if (mid < right) {
            // TODO
        }
    }

};