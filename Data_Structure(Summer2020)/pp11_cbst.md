## 04-树6 Complete Binary Search Tree (30分)

A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive integer N (≤1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:
For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:
10
1 2 3 4 5 6 7 8 9 0
Sample Output:
6 3 8 1 5 7 9 0 2 4

## my sol 1     20/7/1  50 min

FAIL

想找捷径，结果越找越麻烦...

> pp11.cpp

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, num;
    vector<int> nums;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    int k = 0;  // height
    while ((1<<k) < n) k++;
    k = max(0, k-1);
    int root;
    if (n + 1 - (1<<k) <= (1<<(k-1))) {
        root = n - (1<<(k-1));
    } else {
        root = (1<<k) - 1;
    }
    queue<vector<int>> q;
    vector<int> node = {root, 0, (int)nums.size()};
    q.push(node);
    vector<int> ans;
    while (!q.empty()) {
        node = q.front(), q.pop();
        ans.push_back(node[0]);
        // left
        int n_ = node[0] - node[1];
        int k_ = 0;
        while ((1<<k_) < n_) k_++;
        k_ = max(0, k_-1);
        int root_;
        if (n_ + 1 - (1<<k_) <= (1<<(k_-1))) {
            root_ = n_ - (1<<(k_-1)) + node[1];
        } else {
            root_ = (1<<k_) - 1 + node[1];
        }
        vector<int> newNode = {root_, node[1], node[0]-1};
        q.push(newNode);

        // right
        n_ = node[2] - node[0] - 1;
        k_ = 0;
        while ((1<<k_) < n_) k_++;
        k_ = max(0, k_-1);
        if (n_ + 1 - (1<<k_) <= (1<<(k_-1))) {
            root_ = n_ - (1<<(k_-1)) + node[0] + 1;
        } else {
            root_ = (1<<k_) - 1 + node[0] + 1;
        }
        newNode = {root_, node[0]+1, node[2]};
        q.push(newNode);
    }
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}
```

网上找了一圈，我这个方法应该是对的，但是非常麻烦，特别是debug非常恶心。有没有其他方法？

## ref sol 1    20/7/1

> pp11_2.cpp

``` C++
#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int b[1001];
int cnt;
int n;
void dfs(int x)
{
    if(x>n)
        return ;
    dfs(2*x);
    b[x]=++cnt;//对应应该第x号输出对应的第a数组的第cnt元素。
    dfs(2*x+1);
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    dfs(1);
    for(int i=1; i<=n; i++)
        if(i==1)
            printf("%d",a[b[i]]);
        else
            printf(" %d",a[b[i]]);
}
```

？？？这是魔法吗？

这方法简直神仙啊！重新跑了一遍dfs，而且是中序遍历，是左中右的顺序。然后按顺序把idx填入dfs的顺序列表里。这个左中右的顺序就能保证这个遍历的结果是完全二叉树了！