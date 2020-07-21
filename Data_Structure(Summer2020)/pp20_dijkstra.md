# 07-图6 旅游规划 (25point(s))

有了一张自驾旅游路线图，你会知道城市间的高速公路长度、以及该公路要收取的过路费。现在需要你写一个程序，帮助前来咨询的游客找一条出发地和目的地之间的最短路径。如果有若干条路径都是最短的，那么需要输出最便宜的一条路径。

输入格式:
输入说明：输入数据的第1行给出4个正整数N、M、S、D，其中N（2≤N≤500）是城市的个数，顺便假设城市的编号为0~(N−1)；M是高速公路的条数；S是出发地的城市编号；D是目的地的城市编号。随后的M行中，每行给出一条高速公路的信息，分别是：城市1、城市2、高速公路长度、收费额，中间用空格分开，数字均为整数且不超过500。输入保证解的存在。

输出格式:
在一行里输出路径的长度和收费总额，数字间以空格分隔，输出结尾不能有多余空格。

输入样例:
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
输出样例:
3 40

## my sol 1     20/7/21     30 min

07/21/2020 11:45:26 AM	
Accepted
25	07-图6	C++ (g++)	80 ms	Ricky
Case	Hint	Result	Run Time	Memory
0	sample 最便宜的路不是最短路；输出2条最短路中最便宜的	
Accepted
6 ms	2560 KB
1	最小N和M	
Accepted
6 ms	2472 KB
2	最大N，有多条等长等价的道路	
Accepted
7 ms	2304 KB
3	最大N和M, 随机完全图	
Accepted
80 ms	2412 KB

其实20分钟就写完了...de了一个fill三维数组的bug搞了十分钟...三维数组的fill是二维指针，我给搞成三维了

暴力dijkstra写起来可真是方便，复杂度也是上天，不过还好时间卡的不紧

``` C++
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 2147483647
#define MAXN 510

int n, m, s, d;
int edges[MAXN][MAXN][2];
int dist[MAXN];
int price[MAXN];
bool visited[MAXN];

int main() {
    fill(edges[0][0], edges[0][0] + MAXN*MAXN*2, INF);
    // for (int i = 0; i < MAXN; i++) fill(edges[i][0][0], edges[i][0][0] + MAXN * 2, INF);
    fill(visited, visited + MAXN, false);
    fill(dist, dist + MAXN, INF);
    fill(price, price + MAXN, INF);
    scanf("%d%d%d%d", &n, &m, &s, &d);
    int c1, c2, l, p;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &c1, &c2, &l, &p);
        edges[c1][c2][0] = l, edges[c1][c2][1] = p,
        edges[c2][c1][0] = l, edges[c2][c1][1] = p;
    }

    dist[s] = 0, price[s] = 0;
    for (int i = 0; i < n; i++) {

        int cur, minD = INF;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && dist[j] < minD) {
                minD = dist[j], cur = j;
            }
        }

        visited[cur] = true;
        for (int v = 0; v < n; v++) {
            if (visited[v] == false && edges[cur][v][0] != INF) {
                if (dist[v] > dist[cur] + edges[cur][v][0]) {
                    dist[v] = dist[cur] + edges[cur][v][0];
                    price[v] = price[cur] + edges[cur][v][1];
                } else if (dist[v] == dist[cur] + edges[cur][v][0] &&
                           price[v] > price[cur] + edges[cur][v][1]) {
                    price[v] = price[cur] + edges[cur][v][1];
                }
            }
        }
    }

    printf("%d %d", dist[d], price[d]);
    return 0;
}
```
