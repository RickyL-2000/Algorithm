#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int _x, _y, _z;
};

int m, n, l, t;
int arr[1300][130][70];
bool visited[1300][130][70];
int X[6] = {1, 0, 0, -1, 0, 0},
    Y[6] = {0, 1, 0, 0, -1, 0},
    Z[6] = {0, 0, 1, 0, 0, -1};

bool check(int x, int y, int z) {
    if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if (arr[x][y][z] == 0 || visited[x][y][z] == true) return false;
    return true;
}

int bfs(int x, int y, int z) {
    visited[x][y][z] = true;
    queue<Node> q;
    int sum = 0;
    Node node;
    node._x = x, node._y = y, node._z = z;
    q.push(node);
    while (!q.empty()) {
        Node front = q.front();
        q.pop();
        sum++;
        for (int u = 0; u < 6; u++) {
            if (check(front._x + X[u], front._y + Y[u], front._z + Z[u])) {
                node._x = front._x + X[u], node._y = front._y + Y[u], node._z = front._z + Z[u];
                visited[node._x][node._y][node._z] = true;
                q.push(node);
            }
        }
    }
    if (sum >= t) return sum;
    else return 0;
}

int main() {
    scanf("%d %d %d %d", &m, &n, &l, &t);
    for (int i = 0; i < l; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                scanf("%d", &arr[j][k][i]);
    
    int ans = 0;
    for (int i = 0; i < l; i++) 
        for (int j = 0; j < m; j++)
            for (int k = 0; k < n; k++)
                if (visited[j][k][i] == false && arr[j][k][i] == 1)
                    ans += bfs(j, k, i);

    cout << ans;

    return 0;
}