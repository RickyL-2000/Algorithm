#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

const int MAXN = 1e5 + 50;
int n, depth[MAXN], minDepth, cnt[MAXN];
double p, r;
vector<int> nodes[MAXN];

int main() {
    cin >> n >> p >> r;
    r /= 100.0;
    int k, node;
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &node);
            nodes[i].push_back(node);
        }
    }

    queue<int> q;
    q.push(0);
    depth[0] = 0;
    while (!q.empty()) {
        node = q.front(); q.pop();
        minDepth = depth[node];
        if (!nodes[node].empty()) {
            for (size_t i = 0; i < nodes[node].size(); i++) {
                q.push(nodes[node][i]);
                depth[nodes[node][i]] = minDepth + 1;
            }
        } else {
            cnt[minDepth]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] != 0) {
            minDepth = i;
            break;
        }
    }
    printf("%.4lf %d", p * pow((double)1 + r, (double)minDepth), cnt[minDepth]);
    return 0;
}