# 03-树3 Tree Traversals Again (25分)

An inorder binary tree traversal can be implemented in a non-recursive way with a stack. For example, suppose that when a 6-node binary tree (with the keys numbered from 1 to 6) is traversed, the stack operations are: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop(). Then a unique binary tree (shown in Figure 1) can be generated from this sequence of operations. Your task is to give the postorder traversal sequence of this tree.


Figure 1
Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤30) which is the total number of nodes in a tree (and hence the nodes are numbered from 1 to N). Then 2N lines follow, each describes a stack operation in the format: "Push X" where X is the index of the node being pushed onto the stack; or "Pop" meaning to pop one node from the stack.

Output Specification:
For each test case, print the postorder traversal sequence of the corresponding tree in one line. A solution is guaranteed to exist. All the numbers must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
6
Push 1
Push 2
Push 3
Pop
Pop
Push 4
Pop
Pop
Push 5
Push 6
Pop
Pop
Sample Output:
3 4 2 6 5 1

## my sol 1     20/6/29     30 min

这道题我貌似做过

push: 1 2 3 4 5 6   preoder

pop: 3 2 4 1 6 5    inorder

out: 3 4 2 6 5 1    postorder

唉，还是看了一下以前的笔记，我还是太菜了。不过好在是做出来了。

``` C++
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void posttraversal(int idx, int left, int right, vector<int>& pre, vector<int>& in, vector<int>& post) {
    if (left > right) return;
    int mid = left;
    while (in[mid] != pre[idx]) mid++;
    posttraversal(idx+1, left, mid-1, pre, in, post);
    posttraversal(idx+1+mid-left, mid+1, right, pre, in, post);
    post.push_back(in[mid]);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    string op;
    int num;
    stack<int> stk;
    vector<int> preorder, inorder, postorder;
    for (int i = 0; i < 2 * n; i++) {
        cin >> op;
        if (op == "Push") {
            scanf("%d", &num);
            stk.push(num);
            preorder.push_back(num);
        } else {
            num = stk.top();
            stk.pop();
            inorder.push_back(num);
        }
    }
    posttraversal(0, 0, n-1, preorder, inorder, postorder);
    printf("%d", postorder[0]);
    for (int i = 1; i < postorder.size(); i++) {
        printf(" %d", postorder[i]);
    }
    return 0;
}
```
