#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
vector<int> people[MAXN];
vector<int> hobby[MAXN];
map<int, int> hob_m;
bool visited[MAXN];
vector<int> parts;

void dfs(int node, int part) {
    visited[node] = true;
    parts[part]++;
    for (size_t i = 0; i < people[node].size(); i++) {
        for (size_t j = 0; j < hobby[people[node][i]].size(); j++) {
            int p = hobby[people[node][i]][j];
            if (visited[p] == false) {
                dfs(p, part);
            }
        }
    }
}

int main() {
    int n, cnt;
    cin >> n;
    int k, h;
    for (int i = 1; i <= n; i++) {
        scanf("%d:", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &h);
            people[i].push_back(h);
            hobby[h].push_back(i);
            hob_m[h] = 1;
        }
    }
    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == false) {
            parts.push_back(0);
            dfs(i, cnt);
            cnt++;
        }
    }
    sort(parts.begin(), parts.end(), [](int a, int b){return a >= b;});

    printf("%d\n", cnt);
    for (size_t i = 0;  i < parts.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", parts[i]);
    }
    return 0;
}