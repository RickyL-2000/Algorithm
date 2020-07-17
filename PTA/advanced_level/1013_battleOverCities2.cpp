#include <iostream>
#include <algorithm>
using namespace std;

int edge[1010][1010];
bool visited[1010];
int num;

void dfs(int c) {
    visited[c] = true;
    for (int i = 1; i <= num; i++) {
        if (edge[c][i] && visited[i] != true) {
            dfs(i);
        }
    }
}

int main() {
    int m, k, c1, c2;
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
                dfs(j);
                cnt++;
            }
        }
        printf("%d\n", cnt-1);
    }
    return 0;
}