# 03-?2 List Leaves (25point(s))

Given a tree, you are supposed to list all the leaves in the order of top down, and left to right.

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node, and gives the indices of the left and right children of the node. If the child does not exist, a "-" will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in one line all the leaves' indices in the order of top down, and left to right. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
4 1 5


## my sol 1     20/6/29     20 min

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int left[12],
        right[12];
    bool visited[12];
    fill(left, left+12, -1);
    fill(right, right+12, -1);
    fill(visited, visited+12, false);

    int n, root;
    char temp1, temp2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // scanf("%c %c", &temp1, &temp2);
        cin >> temp1 >> temp2;
        if (temp1 != '-') {
            left[i] = temp1 - '0';
            visited[left[i]] = true;
        }
        if (temp2 != '-') {
            right[i] = temp2 - '0';
            visited[right[i]] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            root = i;
            break;
        }
    }

    vector<int> ans;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (left[node] == -1 && right[node] == -1) {
            ans.push_back(node);
            continue;
        }
        if (left[node] != -1) {
            q.push(left[node]);
        }
        if (right[node] != -1) {
            q.push(right[node]);
        }
    }
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}
```
