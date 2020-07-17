#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 50;

int parent[MAXN];

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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n-1) return -1;

        for (int i = 0; i < n; i++) {
            parent[i] = -1;
        }
        int cnt = n;
        for (auto edge : connections) {
            if (merge(edge[0], edge[1])) cnt--;
        }

        return cnt-1;
    }

    void test() {
        int n = 12;
        vector<vector<int>> connections = {{1,5},{1,7},{1,2},{1,4},{3,7},{4,7},{3,5},{0,6},{0,1},{0,4},{2,6},{0,3},{0,2}};
        int ans = makeConnected(n, connections);
        cout << ans << endl;
    }
};

int main() {
    Solution s;
    s.test();
    return 0;
}