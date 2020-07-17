#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int MAXN = 100010;
vector<int> nodes[MAXN];
int n, root, maxDepth = 0, paths = 0;
double p, r;

void dfs(int node, int depth) {
    if (!nodes[node].empty()) {
        for (size_t i = 0; i < nodes[node].size(); i++) {
            dfs(nodes[node][i], depth+1);
        }
    } else {
        if (depth > maxDepth) {
            maxDepth = depth;
            paths = 1;
        } else if (depth == maxDepth) {
            paths++;
        }
    }
}

int main() {
    scanf("%d %lf %lf", &n, &p, &r);
    r /= 100;
    int temp;
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp == -1) {
            root = i;
        } else {
            nodes[temp].push_back(i);
        }
    }

    dfs(root, 0);

    printf("%.2lf %d", p * pow(1 + r, maxDepth), paths);

    return 0;
}