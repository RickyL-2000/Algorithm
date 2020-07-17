/**
 * 看起来是一道经典的dfs题  ......wrong!
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