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