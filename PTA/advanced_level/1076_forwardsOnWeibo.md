# 1076 Forwards on Weibo (30point(s))

Weibo is known as the Chinese version of Twitter. One user on Weibo may have many followers, and may follow many other users as well. Hence a social network is formed with followers relations. When a user makes a post on Weibo, all his/her followers can view and forward his/her post, which can then be forwarded again by their followers. Now given a social network, you are supposed to calculate the maximum potential amount of forwards for any specific user, assuming that only L levels of indirect followers are counted.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers: N (≤1000), the number of users; and L (≤6), the number of levels of indirect followers that are counted. Hence it is assumed that all the users are numbered from 1 to N. Then N lines follow, each in the format:

M[i] user_list[i]
where M[i] (≤100) is the total number of people that user[i] follows; and user_list[i] is a list of the M[i] users that followed by user[i]. It is guaranteed that no one can follow oneself. All the numbers are separated by a space.

Then finally a positive K is given, followed by K UserID's for query.

Output Specification:
For each UserID, you are supposed to print in one line the maximum potential amount of forwards this user can trigger, assuming that everyone who can view the initial post will forward it once, and that only L levels of indirect followers are counted.

Sample Input:
7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5
2 2 6
Sample Output:
4
5

## my sol 1     20/1/26     30 min

我真的是...

这个题目也太难读懂了好吧，花了三十分钟写完发现可能没有读懂题意，结果读了我快一个小时也没有看懂...

> forwardsOnWeibo.cpp

``` C++
/**
 * 看起来是一道经典的dfs题 
 */
#include <iostream>
#include <algorithm>
using namespace std;
/**
 * edge[][] - matrix
 */

int edge[1010][1010];
bool visited[1010];
int num, levels;

int dfs(int index, int level) {
    int sum = 1;
    visited[index] = true;
    for (int i = 1; i <= num; i++) {
        if (visited[i] == false && edge[i][index] == 1 && level <= levels + 1) {
            sum += dfs(i, level+1);
        }
    }
    return sum;
}

int main() {
    scanf("%d %d", &num, &levels);
    for (int i = 1; i <= num; i++) {
        int m, t;   // t - the person that user[i] follows
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &t);
            edge[i][t] = 1;
        }
    }
    int k, ans;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int query;
        scanf("%d", &query);
        fill(visited+1, visited + num+1, false);
        ans = dfs(query, 0);
        printf("%d\n", ans);
    }

    return 0;
}
```

## ref sol 1

https://blog.csdn.net/qq_42815188/article/details/100834988

> forwardsOnWeibo2.cpp

现在没有条件使用纸笔，过几天再好好看看这道题！


## my sol 2     20/7/16     20 min

07/16/2020 11:40:51 AM	
Accepted
30	1076	C++ (g++)	1315 ms	Ricky
Case	Result	Run Time	Memory
0	
Accepted
7 ms	4396 KB
1	
Accepted
7 ms	4324 KB
2	
Accepted
8 ms	4392 KB
3	
Accepted
7 ms	4352 KB
4	
Accepted
1315 ms	4480 KB

欸，不知道为什么，突然就觉得好简单，不就是一个记录层数的bfs嘛，不知道当时为什么没有做出来，可能确实是自己有长进了叭~

咳咳，好像是因为，最开始的时候我居然把它当成了dfs来做...这用bfs可能更方便吧...

姥姥居然说这玩意能在一个小时内做出来就有PAT甲级80分...

> 1076_forwardsOnWeibo3.cpp

``` C++
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, l;
int edges[1010][1010];
bool visited[1010];

int main() {
    scanf("%d %d", &n, &l);
    fill(edges[0], edges[0] + 1010*1010, 0);
    for (int i = 1; i <= n; i++) {
        int num, src;
        scanf("%d", &num);
        for (int j = 0; j < num; j++) {
            scanf("%d", &src);
            edges[src][i] = 1;
        }
    }

    queue<pair<int, int>> q;
    int k, cnt;
    scanf("%d", &k);
    vector<int> ans;
    for (int i = 0; i < k; i++) {
        int cur;
        scanf("%d", &cur);

        while (!q.empty()) q.pop();
        fill(visited, visited + 1010, false);
        q.push(make_pair(cur, 0));
        cnt = -1;
        visited[cur] = true;
        pair<int, int> node;
        while (!q.empty()) {
            node = q.front(), q.pop();
            if (node.second <= l) cnt++;
            else break;
            for (int next = 1; next <= n; next++) {
                if (edges[node.first][next] && visited[next] == false) {
                    visited[next] = true;
                    q.push(make_pair(next, node.second+1));
                }
            }
        }
        ans.push_back(cnt);
    }
    for (int e : ans) printf("%d\n", e);
    return 0;
}
```
