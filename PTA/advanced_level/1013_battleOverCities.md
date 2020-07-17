# Battle over Cities

## my sol 1     20/1/23     20 min

21 points

有一个测试点没有过，说是运行超时了

```
/**
 * 思路：用邻接矩阵存储边， 
 *       然后循环所有concern的城市，用并查集算出森林中有cnt棵树，
 *      返回cnt-1
 * 
 * @attention city is numbered from 1, ignore 0
 */

#include <iostream>
#include <algorithm>
using namespace std;

int parent[1010];   // 全局变量默认初始化的初始值是0
int edge[1010][1010];
int book[1010];

int find(int x) {
    return parent[x] < 0 ? x : parent[x] = find(parent[x]);
}

bool merge(int x1, int x2) {
    if ((x1 = find(x1)) == (x2 = find(x2))) return false;
    if (parent[x1] < parent[x2]) {
        parent[x1] += parent[x2];
        parent[x2] = x1;
    } else {
        parent[x2] += parent[x1];
        parent[x1] = x2;
    }
    return true;
}

int main() {
    int num, m, k;
    cin >> num >> m >> k;
    int c1, c2;
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        edge[c1][c2] = edge[c2][c1] = 1;
    }
    int target, cnt;
    for (int i = 0; i < k; i++) {
        fill(parent, parent + num + 1, -1);

        cin >> target;
        int t = 0;
        for (int j = 1; j <= num; j++) {
            if (edge[target][j] == 1) {
                edge[target][j] = edge[j][target] = 0;  // destroy the highway to target city
                book[t] = j;    // 备忘录
                t++;
            }
        }
        cnt = num;
        for (int c1 = 1; c1 <= num; c1++) {
            for (int c2 = 1; c2 < c1; c2++) {
                if (edge[c1][c2]) {
                    if (merge(c1, c2)) cnt--;
                }
            }
        }
        cout << cnt-2 << endl;

        for (int b = 0; b < t; b++) {
            edge[target][book[b]] = edge[book[b]][target] = 1;
        }
    }
    return 0;
}
```

## ref sol 1

研究一下liu的算法...

```
#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node) {
    visit[node] = true;
    for(int i = 1; i <= n; i++) {
        if(visit[i] == false && v[node][i] == 1)
            dfs(i);
    }
}
int main() {
    int m, k, a, b;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 0; i < k; i++) {
        fill(visit, visit + 1010, false);
        scanf("%d", &a);
        int cnt = 0;
        visit[a] = true;
        for(int j = 1; j <= n; j++) {
            if(visit[j] == false) {
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt - 1);
    }
    return 0;
}
```

没有想到用深搜更简单！上次学并查集的时候好像就有人说那道题一般是用深搜做的...

**NOTE**: 好像用邻接矩阵这种方式存储边的话，当数据大起来后并查集就没有什么优势了。而如果用单独的2元tuple来存储每一条边的话，对于本题这种需要删除很多点的操作就非常麻烦，因为需要遍历每一个tuple来查找是否连接到了该点。所以这应该就是为什么我的算法会超时。

而且！！用深搜这种方法对于要删除(destroy)某个点的操作貌似更加简便！只需要把那个点设置为visited就可以了！妙啊！

为了巩固，自己还是要再写一遍才行！

## my sol 2     20/1/23     20 min

21 points

？？？

我照着样子写了一遍dfs，但是还是那个点会超时？？？

```
#include <iostream>
#include <algorithm>
using namespace std;

int edge[1010][1010];
bool visited[1010];

void dfs(int c, int num) {
    visited[c] = true;
    for (int i = 1; i <= num; i++) {
        if (edge[c][i] && visited[i] != true) {
            dfs(i, num);
        }
    }
}

int main() {
    int num, m, k, c1, c2;
    cin >> num >> m >> k;
    for (int i = 0; i < m; i++) {
        cin >> c1 >> c2;
        edge[c1][c2] = edge[c2][c1] = 1;
    }

    int target, cnt;
    for (int i = 0; i < k; i++) {
        fill(visited, visited+1010, false);
        scanf("%d", &target);
        cnt = 0;
        visited[target] = true;     // wow!
        for (int j = 1; j <= num; j++) {
            if (visited[j] != true) {
                dfs(j, num);
                cnt++;
            }
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}
```

经过我改了很多很多很多遍之后......

**发现！！**只要我把num这个变量声明为全局变量，然后dfs少传一个参数，然后...就过了？？！！

**THE MORAL OF THE STORY**: dfs的时候千万不要传太多参数！一定需要的参数都设置为全局变量!