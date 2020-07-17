#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode *left;
    AVLNode *right;
    int height;

    AVLNode() = default;
    AVLNode(int data) : data(data), height(0) { left = nullptr, right = nullptr;}
};

int getHeight(AVLNode *node) {
    if (node == nullptr) return 0;
    return node->height;
}

AVLNode* left_rotate(AVLNode *root) {
    /*
     * node->right != nullptr
     * */
    AVLNode *child = root->right;
    root->right = child->left;
    child->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;
    return child;
}

AVLNode* right_rotate(AVLNode *root) {
    /*
     * node->left != nullptr
     * */
    AVLNode *child = root->left;
    root->left = child->right;
    child->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;
    return child;
}

AVLNode* left_right_rotate(AVLNode *root) {
    root->left = left_rotate(root->left);
    return right_rotate(root);
}

AVLNode* right_left_rotate(AVLNode *root) {
    root->right = right_rotate(root->right);
    return left_rotate(root);
}

AVLNode* t_insert(AVLNode *root, int num) {
    if (root == nullptr) {
        root = new AVLNode(num);
    }
    else if (num < root->data) {
        root->left = t_insert(root->left, num);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (num < root->left->data) {
                root = right_rotate(root);
            } else if (num > root->left->data) {
                root = left_right_rotate(root);
            }
        }
    }
    else if (num > root->data) {
        root->right = t_insert(root->right, num);
        if (getHeight(root->right) - getHeight(root->left) == 2) {
            if (num > root->right->data) {
                root = left_rotate(root);
            } else if (num < root->right->data){
                root = right_left_rotate(root);
            }
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

int main() {
    int n, num;
    scanf("%d", &n);
    AVLNode *tree = nullptr;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        tree = t_insert(tree, num);
    }
    printf("%d", tree->data);
    return 0;
}