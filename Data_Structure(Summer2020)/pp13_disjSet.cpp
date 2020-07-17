#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int parent[10010];

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
    fill(parent, parent + 10010, -1);
    int n;
    scanf("%d", &n);
    char status;
    int x1, x2;
    vector<string> ans;
    while (true) {
        cin >> status;
        if (status == 'S') break;
        cin >> x1 >> x2;
        if (status == 'I') {
            merge(x1, x2);
        } else if (status == 'C') {
            if (find(x1) == find(x2)) ans.push_back("yes");
            else ans.push_back("no");
        }
    }
    for (string str : ans) {
        cout << str << endl;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] < 0) cnt++;
    }
    if (cnt == 1) cout << "The network is connected." << endl;
    else if (cnt > 1) cout << "There are " << cnt << " components." << endl;
    return 0;
}