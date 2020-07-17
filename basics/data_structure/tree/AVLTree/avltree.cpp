#include <iostream>
#include <vector>
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
        return root;
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

AVLNode* t_delete(AVLNode *root, int num) {
    if (root == nullptr) return root;
    else if (num < root->data) {
        root->left = t_delete(root->left, num);
        if (getHeight(root->right - getHeight(root->left)) == 2) {
            if (getHeight(root->right->left) < getHeight(root->right->right)) {
                root = left_rotate(root);
            } else {
                root = right_left_rotate(root);
            }
        }
    } 
    else if (num > root->data) {
        root->right = t_delete(root->right, num);
        if (getHeight(root->left) - getHeight(root->right) == 2) {
            if (getHeight(root->left->left) < getHeight(root->left->right)) {
                root = left_right_rotate(root);
            } else {
                root = right_rotate(root);
            }
        }
    } 
    else if (num == root->data) {
        //1. if the current node is leaf
        if (!root->left && !root->right) {
            delete root;
            return nullptr;     // delete directly
        }
        if (root->left != nullptr && root->right == nullptr) {
            // delete root;
            return root->left;
        }
        if (root->left == nullptr && root->right != nullptr) {
            // delete root;
            return root->right;
        }
        if (root->left != nullptr && root->right != nullptr) {
            if (getHeight(root->left) < getHeight(root->right)) {
                AVLNode *minNode = root->right;
                while (minNode->left != nullptr) minNode = minNode->left;
                int temp = minNode->data; minNode->data = root->data; root->data = temp;
                root->right = t_delete(root->right, num);
            } else {
                AVLNode *maxNode = root->left;
                while (maxNode->right != nullptr) maxNode = maxNode->right;
                int temp = maxNode->data; maxNode->data = root->data; root->data = temp;
                root->left = t_delete(root->left, num);
            }
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

int main() {
    vector<int> nums = {88, 70, 61, 96, 23, 120, 90, 65, 15};
    AVLNode *tree = nullptr;
    for (int num : nums) {
        tree = t_insert(tree, num);
    }
    tree = t_delete(tree, 88);
    tree = t_delete(tree, 61);
    tree = t_delete(tree, 65);
    return 0;
}