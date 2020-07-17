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