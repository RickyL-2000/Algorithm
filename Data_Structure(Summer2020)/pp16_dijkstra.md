# 06-图2 Saving James Bond - Easy Version (25point(s))

This time let us consider the situation in the movie "Live and Let Die" in which James Bond, the world's most famous spy, was captured by a group of drug dealers. He was sent to a small piece of land at the center of a lake filled with crocodiles. There he performed the most daring action to escape -- he jumped onto the head of the nearest crocodile! Before the animal realized what was happening, James jumped again onto the next big head... Finally he reached the bank before the last crocodile could bite him (actually the stunt man was caught by the big mouth and barely escaped with his extra thick boot).

Assume that the lake is a **100 by 100** square one. Assume that the center of the lake is at **(0,0)** and the northeast corner at (50,50). The central island is a disk centered at (0,0) with the **diameter of 15**. A number of crocodiles are in the lake at various positions. Given the coordinates of each crocodile and the distance that James could jump, you must tell him whether or not he can escape.

Input Specification:
Each input file contains one test case. Each case starts with a line containing two positive integers N (≤100), the number of crocodiles, and D, the maximum distance that James could jump. Then N lines follow, each containing the (x,y) location of a crocodile. Note that no two crocodiles are staying at the same position.

Output Specification:
For each test case, print in a line "Yes" if James can escape, or "No" if not.

Sample Input 1:
14 20
25 -15
-25 28
8 49
29 15
-35 -2
5 28
27 -29
-8 -28
-20 -35
-25 -20
-13 29
-30 15
-35 40
12 12
Sample Output 1:
Yes
Sample Input 2:
4 13
-12 12
12 12
-12 -12
12 -12
Sample Output 2:
No

## my sol 1     20/7/15     55 min

Submit Time	Status	Score	Problem	Compiler	Run Time	User
07/15/2020 11:57:26 AM	
Partially Accepted
19	06-图2	C++ (g++)	4 ms	Ricky
Case	Hint	Result	Run Time	Memory
0	sample 有不成功的分支，连续几次到岸；有可以到岸但跳不过去的，多连通	
Accepted
4 ms	352 KB
1	sample 都可以跳到，但不到岸	
Accepted
3 ms	384 KB
2	最小N	
Wrong Answer
4 ms	384 KB
3	最小跳，人工乱序	
Wrong Answer
4 ms	364 KB
4	最大N最小跳，4象限对称，人工乱序	
Accepted
4 ms	384 KB
5	都能到岸，但够不着	
Accepted
3 ms	396 KB

部分通过:(

仔细想了一下，重新读了一遍题，发现....我貌似没有把中央的小岛考虑进去！

``` C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define INF = __DBL_MAX__

struct Node {
    int id;
    int x, y;
    double dist = __DBL_MAX__;
    Node* parent = nullptr;
    Node (int id, int x, int y): id(id), x(x), y(y) {}
    Node () = default;
};

double distance(Node* a, Node* b) {
    return sqrt((double)(a->x - b->x) * (a->x - b->x) + 
                (double)(a->y - b->y) * (a->y - b->y));
}

int lake[110][110];
vector<Node*> pq;
bool visited[110];
int n, d;

int main() {
    scanf("%d %d", &n, &d);
    fill(lake[0], lake[0] + 110 * 110, -1);
    int x, y;
    auto cmp = [] (Node* a, Node* b) {return a->dist > b->dist;};
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        Node* newNode = new Node(i, x, y);
        lake[x+50][y+50] = i;
        pq.push_back(newNode);
    }
    Node* root = new Node(0, 0, 0);
    root->dist = 0.0;
    root->parent = root;
    lake[50][50] = 0;
    pq.push_back(root);
    // make_heap(pq.begin(), pq.end(), cmp);
    visited[0] = true;
    Node* cur = nullptr;
    while (!pq.empty()) {
        make_heap(pq.begin(), pq.end(), cmp);
        pop_heap(pq.begin(), pq.end(), cmp);
        cur = pq.back();
        pq.pop_back();
        visited[cur->id] = true;
        // 判断是否已经穷尽所有能到的地方
        if (cur->parent == nullptr) {
            printf("No");
            return 0;
        }
        // 判断是否可以到边界
        if (abs(abs(cur->x) - 50) <= d || abs(abs(cur->y) - 50) <= d) {
            printf("Yes");
            return 0;
        }
        for (int i = 0; i < pq.size(); i++) {
            // 判断是否为邻居
            double dist = distance(pq[i], cur);
            if (dist <= (double) d && visited[i+1] == false) {
                // 判断是否需要松弛
                if (pq[i]->dist > cur->dist + dist) {
                    pq[i]->dist = cur->dist + dist;
                    pq[i]->parent = cur;
                }
            }
        }
    }
    printf("No");
    return 0;
}
```

## my sol 2     20/7/15     20 min

07/15/2020 2:05:45 PM	
Accepted
25	06-图2	C++ (g++)	5 ms	Ricky
Case	Hint	Result	Run Time	Memory
0	sample 有不成功的分支，连续几次到岸；有可以到岸但跳不过去的，多连通	
Accepted
4 ms	424 KB
1	sample 都可以跳到，但不到岸	
Accepted
5 ms	364 KB
2	最小N	
Accepted
4 ms	360 KB
3	最小跳，人工乱序	
Accepted
4 ms	352 KB
4	最大N最小跳，4象限对称，人工乱序	
Accepted
4 ms	512 KB
5	都能到岸，但够不着	
Accepted
4 ms	384 KB

用的dijkstra，或者说是用优先队列优化的bfs也可以。

这次做题其实并没有很熟练，更多的是在学习。特别是发现可以用algorithm标准库里的```make_heap```等函数把vector变成优先队列，这样就可以在利用堆的特性的同时访问vector中的元素了！

同时又巩固了一下匿名函数的使用，匿名函数的类型一定是auto

小顶堆是>，大顶堆是<

``` C++
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define INF = __DBL_MAX__

struct Node {
    int id;
    int x, y;
    double dist = __DBL_MAX__;
    Node* parent = nullptr;
    Node (int id, int x, int y): id(id), x(x), y(y) {}
    Node () = default;
};

double distance(Node* a, Node* b) {
    return sqrt((double)((a->x - b->x) * (a->x - b->x)) + 
                (double)((a->y - b->y) * (a->y - b->y)));
}

int lake[110][110];
vector<Node*> pq;
bool visited[110];
int n, d;

int main() {
    scanf("%d %d", &n, &d);
    fill(lake[0], lake[0] + 110 * 110, -1);
    int x, y;
    auto cmp = [] (Node* a, Node* b) {return a->dist > b->dist;};
    Node* root = new Node(0, 0, 0);
    root->dist = 0.0;
    root->parent = root;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        Node* newNode = new Node(i, x, y);
        lake[x+50][y+50] = i;
        // if (distance(newNode, root) <= 7.5) newNode->dist = 0;  // 中央小岛
        pq.push_back(newNode);
    }
    lake[50][50] = 0;
    pq.push_back(root);
    // make_heap(pq.begin(), pq.end(), cmp);
    visited[0] = true;
    Node* cur = nullptr;
    while (!pq.empty()) {
        make_heap(pq.begin(), pq.end(), cmp);
        pop_heap(pq.begin(), pq.end(), cmp);
        cur = pq.back();
        pq.pop_back();
        visited[cur->id] = true;
        // 判断是否已经穷尽所有能到的地方
        if (cur->parent == nullptr) {
            printf("No");
            return 0;
        }
        // 判断是否可以到边界
        if (abs(abs(cur->x) - 50) <= d || abs(abs(cur->y) - 50) <= d) {
            printf("Yes");
            return 0;
        }
        int len = pq.size();
        for (int i = 0; i < len; i++) {
            // 判断当前点是否在岛上
            if (cur == root) {
                // 判断是否为邻居
                double dist = distance(pq[i], cur);
                if (dist - 7.5 <= (double) d && visited[pq[i]->id] == false) {
                    // 判断是否需要松弛
                    if (pq[i]->dist > cur->dist + dist - 7.5) {
                        pq[i]->dist = cur->dist + dist - 7.5;
                        pq[i]->parent = cur;
                    }
                }  
            } else {
                // 判断是否为邻居
                double dist = distance(pq[i], cur);
                if (dist <= (double) d && visited[pq[i]->id] == false) {
                    // 判断是否需要松弛
                    if (pq[i]->dist > cur->dist + dist) {
                        pq[i]->dist = cur->dist + dist;
                        pq[i]->parent = cur;
                    }
                }
            }
        }
    }
    printf("No");
    return 0;
}
```
