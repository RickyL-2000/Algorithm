# 08-图8 How Long Does It Take (25分)

Given the relations of all the activities of a project, you are supposed to find the earliest completion time of the project.

Input Specification:
Each input file contains one test case. Each case starts with a line containing two positive integers N (≤100), the number of activity check points (hence it is assumed that the check points are numbered from 0 to N−1), and M, the number of activities. Then M lines follow, each gives the description of an activity. For the i-th activity, three non-negative numbers are given: S[i], E[i], and L[i], where S[i] is the index of the starting check point, E[i] of the ending check point, and L[i] the lasting time of the activity. The numbers in a line are separated by a space.

Output Specification:
For each test case, if the scheduling is possible, print in a line its earliest completion time; or simply output "Impossible".

Sample Input 1:
9 12
0 1 6
0 2 4
0 3 5
1 4 1
2 4 1
3 5 2
5 4 0
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4
Sample Output 1:
18
Sample Input 2:
4 5
0 1 1
0 2 2
2 1 3
1 3 4
3 2 5
Sample Output 2:
Impossible

## my sol 1     20/7/28     76 min

花了一个多小时写的，因为之前基本没有实际操作过拓扑排序，而且对用拓扑排序检测是否有环也没有经验，就重新学了一遍，自己从零开始写了一个拓扑排序，所以花了点时间。

然而，题干给出的两个样例只能过一个...第一个答案18我却输出16...

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    vector<pair<int, int>> pre, next;
    int cost = 0;
};

Node* nodes[110];
bool visited[110];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        nodes[i] = new Node();
    }
    fill(visited, visited + 110, false);
    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        nodes[v1]->next.push_back(make_pair(v2, w)),
        nodes[v2]->pre.push_back(make_pair(v1, w));
    }
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        if (nodes[i]->pre.empty()) stk.push_back(i);
    }
    int cur;
    while (!stk.empty()) {
        cur = stk.back(), stk.pop_back();
        visited[cur] = true;
        sort(nodes[cur]->next.begin(), nodes[cur]->next.end(), [](pair<int, int> &a1, pair<int, int> &a2) {return a1.second < a2.second;});
        int w;
        for (auto next_p : nodes[cur]->next) {
            if (visited[next_p.first]) continue;
            // 判断是否是入度为零的点
            bool isZero = true;
            for (auto pre_p : nodes[next_p.first]->pre) {
                if (visited[pre_p.first] == false) {
                    isZero = false;
                    break;
                }
            }
            if (isZero) {
                stk.push_back(next_p.first);
                nodes[next_p.first]->cost = nodes[cur]->cost + next_p.second;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            printf("Impossible");
            return 0;
        }
    }
    int ans = 0;;
    for (int i = 0; i < n; i++) {
        ans = max(ans, nodes[i]->cost);
    }
    printf("%d", ans);
    return 0;
}
```
