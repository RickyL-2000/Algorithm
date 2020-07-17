# 06-图3 六度空间 (30point(s))

“六度空间”理论又称作“六度分隔（Six Degrees of Separation）”理论。这个理论可以通俗地阐述为：“你和任何一个陌生人之间所间隔的人不会超过六个，也就是说，最多通过五个人你就能够认识任何一个陌生人。”如图1所示。


图1 六度空间示意图
“六度空间”理论虽然得到广泛的认同，并且正在得到越来越多的应用。但是数十年来，试图验证这个理论始终是许多社会学家努力追求的目标。然而由于历史的原因，这样的研究具有太大的局限性和困难。随着当代人的联络主要依赖于电话、短信、微信以及因特网上即时通信等工具，能够体现社交网络关系的一手数据已经逐渐使得“六度空间”理论的验证成为可能。

假如给你一个社交网络图，请你对每个节点计算符合“六度空间”理论的结点占结点总数的百分比。

输入格式:
输入第1行给出两个正整数，分别表示社交网络图的结点数N（1<N≤10
​3
​​ ，表示人数）、边数M（≤33×N，表示社交关系数）。随后的M行对应M条边，每行给出一对正整数，分别是该条边直接连通的两个结点的编号（节点从1到N编号）。

输出格式:
对每个结点输出与该结点距离不超过6的结点数占结点总数的百分比，精确到小数点后2位。每个结节点输出一行，格式为“结点编号:（空格）百分比%”。

输入样例:
10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
输出样例:
1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%


## my sol 1     20/7/16     16 min

07/16/2020 11:11:32 AM	
Accepted
30	06-图3	C++ (g++)	186 ms	Ricky
Case	Hint	Result	Run Time	Memory
0	sample 简单一条链	
Accepted
6 ms	4464 KB
1	不连通	
Accepted
7 ms	4480 KB
2	一般图	
Accepted
7 ms	4252 KB
3	最小N和M	
Accepted
7 ms	4348 KB
4	最大N和M	
Accepted
186 ms	4224 KB

本来一直在担心会不会超时...毕竟1010的数量级再加上各种嵌套循环...没有想到居然没有超时，看来编译器优化的还可以。

本来还想写一个struct好节省空间和时间，现在看来是没必要了

``` C++
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int edges[1010][1010];
bool visited[1010];

int main() {
    scanf("%d %d", &n, &m);
    fill(edges[0], edges[0] + 1010*1010, 0);
    int a1, a2;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a1, &a2);
        edges[a1][a2] = 1, edges[a2][a1] = 1;
    }

    queue<pair<int, int>> q;
    int cnt;
    for (int cur = 1; cur <= n; cur++) {
        while (!q.empty()) q.pop();
        fill(visited, visited + 1010, false);
        cnt = 0;
        q.push(make_pair(cur, 0));
        visited[cur] = true;
        pair<int, int> node;
        while (!q.empty()) {
            node = q.front(), q.pop();
            if (node.second <= 6) cnt++;
            else break;
            for (int next = 1; next <= n; next++) {
                if (edges[node.first][next] && visited[next] == false) {
                    visited[next] = true;
                    q.push(make_pair(next, node.second+1));
                }
            }
        }
        printf("%d: %.2lf%\n", cur, (double)cnt / (double)n * 100);
    }
    return 0;
}
```
