# Waiting in Line

## my sol 1     20/1/24     60 min

19/30

不知道为啥这次做了这么久，关键是自己还感觉不到。

关键是没有全对...又不告诉我哪里错了...

> waitingInLine.cpp
```
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int customer[1010];
int now_time;

bool allEmpty(vector<queue<int>>& queues) {
    for (size_t i = 0; i < queues.size(); i++) {
        if (!queues[i].empty()) return false;
    }
    return true;
}

/**
 * @details n -- windows
 *          m -- capacity
 *          k -- customers
 *          q -- queries 
 */

int main() {
    int n, m, k, q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    int cost;
    for (int i = 1; i <= k; i++) {      // customers count from 1
        scanf("%d", &cost);
        customer[i] = cost;
    }

    // init
    int next = 1;
    vector<queue<int>> queues;
    for (int i = 0; i < n; i++) {      // windows count from 0
        queue<int> qu;
        for (int j = 1 + i; j <= n*m; j += n) {
            qu.push(j);
            next++;
        }
        queues.push_back(qu);
    }
    
    // process
    int minT, minIdx;
    while (!allEmpty(queues)) {
        minT = 99999999;
        for (int i = 0; i < n; i++) {
            if (!queues[i].empty() && customer[queues[i].front()] < minT) {
                minT = customer[queues[i].front()];
                minIdx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!queues[i].empty()) {
                customer[queues[i].front()] -= minT;
            }
        }
        now_time += minT;
        customer[queues[minIdx].front()] = now_time;
        queues[minIdx].pop();
        if (next <= k) {
            queues[minIdx].push(next);
            next++;
        }
    }
    int query, hour, min;
    for (int i = 0; i < q; i++) {
        scanf("%d", &query);
        if (customer[query] > 540) {
            printf("Sorry\n");
            continue;
        }
        hour = customer[query] / 60 + 8;
        min = customer[query] % 60;
        printf("%02d:%02d\n", hour, min);
    }
    
    return 0;
}
```

还是趁此机会学一学人家的代码吧！

## ref sol 1

> waitingInLine2.cpp

讲道理...感觉她写的这个没有我的好...

不过看了一下并且查了一下后发现，我的代码出错的问题是题目理解错了...

before 17: 00 的意思是只要是17点之前开始的业务都可以完成，所以是有可能超时间的。所以依据这个我稍微改了一下我的代码：

## my sol 2     20/1/24     20 min

30/30

NICAAAAAA!

果然是因为把题目理解错了。这样加入一个costs[]数组来记录原来的时间，减一减再查看是否超时即可

> waitingInLine.cpp

```
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int customer[1010];
int costs[1010];
int now_time;

bool allEmpty(vector<queue<int>>& queues) {
    for (size_t i = 0; i < queues.size(); i++) {
        if (!queues[i].empty()) return false;
    }
    return true;
}

/**
 * @details n -- windows
 *          m -- capacity
 *          k -- customers
 *          q -- queries 
 */

int main() {
    int n, m, k, q;
    scanf("%d %d %d %d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {      // customers count from 1
        scanf("%d", &customer[i]);
        costs[i] = customer[i];
    }

    // init
    int next = 1;
    vector<queue<int>> queues;
    for (int i = 0; i < n; i++) {      // windows count from 0
        queue<int> qu;
        for (int j = 1 + i; j <= n*m; j += n) {
            qu.push(j);
            next++;
        }
        queues.push_back(qu);
    }
    
    // process
    int minT, minIdx;
    while (!allEmpty(queues)) {
        minT = 99999999;
        for (int i = 0; i < n; i++) {
            if (!queues[i].empty() && customer[queues[i].front()] < minT) {
                minT = customer[queues[i].front()];
                minIdx = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!queues[i].empty()) {
                customer[queues[i].front()] -= minT;
            }
        }
        now_time += minT;
        customer[queues[minIdx].front()] = now_time;
        queues[minIdx].pop();
        if (next <= k) {
            queues[minIdx].push(next);
            next++;
        }
    }
    int query, hour, min;
    for (int i = 0; i < q; i++) {
        scanf("%d", &query);
        if (customer[query] - costs[query] >= 540) {
            printf("Sorry\n");
            continue;
        }
        hour = customer[query] / 60 + 8;
        min = customer[query] % 60;
        printf("%02d:%02d\n", hour, min);
    }
    
    return 0;
}
```