/**
 * windows和customers都从1开始，其中windows <= 20, customers <= 1000
 * 用customer[1010]先存放每个customer的processing时间，然后存放从8:00开始累计时间
 * 用vector<queue<int>> queues 存放线内人员，其中queue<int> [12], vector<>[25]
 * 
 * 大体算法是从所有窗口中找出数据最小的cur，然后累加到总时间now_time上，然后cur变成总时间，
 * 同时所有队首的元素都减去customer[cur]（这个方法对同时完成应该没有影响，因为同时完成的其他
 * 顾客的时间会因此变成0，但是要注意**如果真的有同时的情况要保证数字小的窗口的人先出队（这样可以
 * 保证先进来的人会在左边））；同时让后一个人排到这个队的尾部，对黄线外的人可以用一个index:next
 * 跟踪
 * 
 * @attention: 1. 每次对队首元素操作的时候要注意队列是否为空
 */

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