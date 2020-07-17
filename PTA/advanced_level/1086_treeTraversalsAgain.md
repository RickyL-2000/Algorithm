# 1086_treeTraversalsAgain

## my sol 1     20/2/5      60 min

不是很会做...

``` C++
#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
    bool visited, left_visited, right_visited;
    Node(int x): val(x), left(nullptr), right(nullptr), parent(nullptr),
                 left_visited(false), right_visited(false), visited(valse) {}
};

int main() {
    int n;
    int stk[35], index = -1;
    cin >> n;
    string line;
    Node* preNode = nullptr;    // pre level
    int val;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        if (line.length() <= 4) {           // pop
            val = stk[index];
            index--;
            if (preNode->visited || 
                (!preNode->visited && preNode->left == nullptr && preNode->right == nullptr)) {
                preNode->visited = true;
                preNode->left_visited = preNode->right_visited = true;
                preNode = preNode->parent;
                continue;
            }
            if (!preNode->visited && preNode->left != nullptr && preNode->right == nullptr) {
                preNode->visited = true;
                continue;
            }
        } else {                            // push
            sscanf(line, "%s%d", &val);
            index++;
            stk[index] = val;
            Node* node = new Node(val);
            if (preNode == nullptr) {   // it's root
                preNode = node;
                continue;
            }
            node->parent = preNode;
            if (!preNode->left_visited && preNode->left != nullptr) {
                preNode->left = node;
            } else {
                preNode->right = node;
            }
            preNode = node;
        }
    }
}
```

做了一些尝试，但是放弃了

还是看答案吧

## ref sol 1

我傻了！

果然这种题目很有技巧！

https://www.cnblogs.com/keelongz/p/10046503.html

不妨看一下例子：Push进栈的有：1 2 3 4 5 6

　　　　　　　　而对应Pop出栈的是：3 2 4 1 6 5

　发现很眼熟，如果对树的遍历很敏感的话。你会发现进栈的顺序是树的先序遍历。而出栈的顺序是中序遍历。

怎么说呢.......这是真的牛逼......

https://blog.csdn.net/ismahui/article/details/76180343

因为先序遍历每次都是以根打头的，可以用于找根，然后就是在中序遍历中凭根找左右子树。

## my sol 2     20/2/5

感觉得需要巩固一下...但是它的这个算法实在是有些复杂

> 1086_treeTraversalsAgain2.cpp

这次为了更好理解，我没有采用ref sol 1里那种高妙的方法，而是先用先序和中序建了一棵树，然后再后序遍历一遍。