# 07-图4 哈利·波特的考试 (25point(s))

哈利·波特要考试了，他需要你的帮助。这门课学的是用魔咒将一种动物变成另一种动物的本事。例如将猫变成老鼠的魔咒是haha，将老鼠变成鱼的魔咒是hehe等等。反方向变化的魔咒就是简单地将原来的魔咒倒过来念，例如ahah可以将老鼠变成猫。另外，如果想把猫变成鱼，可以通过念一个直接魔咒lalala，也可以将猫变老鼠、老鼠变鱼的魔咒连起来念：hahahehe。

现在哈利·波特的手里有一本教材，里面列出了所有的变形魔咒和能变的动物。老师允许他自己带一只动物去考场，要考察他把这只动物变成任意一只指定动物的本事。于是他来问你：带什么动物去可以让最难变的那种动物（即该动物变为哈利·波特自己带去的动物所需要的魔咒最长）需要的魔咒最短？例如：如果只有猫、鼠、鱼，则显然哈利·波特应该带鼠去，因为鼠变成另外两种动物都只需要念4个字符；而如果带猫去，则至少需要念6个字符才能把猫变成鱼；同理，带鱼去也不是最好的选择。

输入格式:
输入说明：输入第1行给出两个正整数N (≤100)和M，其中N是考试涉及的动物总数，M是用于直接变形的魔咒条数。为简单起见，我们将动物按1~N编号。随后M行，每行给出了3个正整数，分别是两种动物的编号、以及它们之间变形需要的魔咒的长度(≤100)，数字之间用空格分隔。

输出格式:
输出哈利·波特应该带去考场的动物的编号、以及最长的变形魔咒的长度，中间以空格分隔。如果只带1只动物是不可能完成所有变形要求的，则输出0。如果有若干只动物都可以备选，则输出编号最小的那只。

输入样例:
6 11
3 4 70
1 2 1
5 4 50
2 6 50
5 6 60
1 3 70
4 6 60
3 6 80
5 1 100
2 4 60
5 2 80
输出样例:
4 70

## my sol 1     20/7/20     40 min

07/20/2020 11:14:38 AM	
Accepted
25	07-图4	C++ (g++)	12 ms	Ricky
Case	Hint	Result	Run Time	Memory
0	sample换数字，只有唯一解	
Accepted
2 ms	512 KB
1	无解	
Accepted
2 ms	516 KB
2	最大N的等边长环，解不唯一，输出最小编号	
Accepted
12 ms	384 KB
3	最大N，最大M，随机完全图	
Accepted
12 ms	500 KB

这题也太水了点...我还以为有某种图的中心点的类似的算法，结果就是暴力调用dijkstra？？

花了点时间在研究图的拓扑中心上，所以比较慢...当然这是我第二次尝试用make_heap来操作队列，比之前直接循环找最小值应该快了不少。

``` C++
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 2147483647

int edges[110][110];
bool visited[110];
int parent[110];
vector<pair<int, int>*> nodes, pq, ans;
int n, m;

int main() {
    fill(edges[0], edges[0] + 110*110, -1);
    scanf("%d %d", &n, &m);
    int v1, v2, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &v1, &v2, &w);
        edges[v1][v2] = w;
        edges[v2][v1] = w;
    }

    nodes.push_back(nullptr);
    for (int u = 1; u <= n; u++) {
        auto newP = new pair<int, int> (u, INF);
        nodes.push_back(newP);
    }

    auto cmp = [] (pair<int, int>* a1, pair<int, int>* a2) {
        return a1->second > a2->second;
    };

    bool connect = false;
    fill(parent, parent+110, 0);
    for (int v = 1; v <= n; v++) {
        fill(visited, visited + 110, false);
        for (int u = 1; u <= n; u++) {
            nodes[u]->second = INF;
        }
        nodes[v]->second = 0;
        if (!connect) parent[v] = v;
        pq = nodes;
        pair<int, int>* node;
        while (pq.size() > 1) {
            make_heap(pq.begin()+1, pq.end(), cmp);
            pop_heap(pq.begin()+1, pq.end(), cmp), 
            node = pq.back(), pq.pop_back();
            if (!connect && parent[node->first] == 0) {
                printf("0");
                return 0;
            }
            for (int u = 1; u <= n; u++) {
                if (edges[node->first][u] >= 0 && visited[u] == false) {
                    if (nodes[u]->second > nodes[node->first]->second + edges[node->first][u]) {
                        nodes[u]->second = nodes[node->first]->second + edges[node->first][u];
                        if (!connect) parent[u] = node->first;
                    }
                }
            }
        }
        connect = true;
        int max_dist = 0, idx;
        for (int i = 1; i <= n; i++) {
            if (max_dist < nodes[i]->second) {
                max_dist = nodes[i]->second, idx = i;
            }
        }
        auto newP = new pair<int, int> (idx, max_dist);
        ans.push_back(newP);
    }
    int min_dict = INF, idx;
    for (int i = 0; i < n; i++) {
        if (min_dict > ans[i]->second) {
            min_dict = ans[i]->second, idx = i;
        }
    }
    printf("%d %d", idx+1, min_dict);
    return 0;
}
```
