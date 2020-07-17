#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define MAXN 20010

int heap[MAXN];
int len = 0;
// map<int, int> mp;

void sift_up(int idx) {
    if (idx > 0 && heap[(idx - 1) / 2] > heap[idx]) {
        int temp = heap[idx];
        heap[idx] = heap[(idx - 1) / 2];
        heap[(idx - 1) / 2] = temp;
        // mp[heap[idx]] = idx;
        // mp[heap[(idx - 1) / 2]] = (idx - 1) / 2;
        sift_up((idx - 1) / 2);
    }
}

void insert(int num) {
    heap[len] = num;
    // mp[num] = len;
    len++;
    sift_up(len-1);
}


int main() {
    fill(heap, heap + MAXN, 10001);
    int n, m, num;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(num);
    }
    vector<vector<int>> ans;
    vector<int> path;
    int idx;
    for (int i = 0; i < m; i++) {
        scanf("%d", &idx);
        idx--;
        path.clear();
        while (idx >= 0) {
            path.push_back(heap[idx]);
            if (idx == (idx - 1) / 2) break;
            idx = (idx - 1) / 2;
        }
        ans.push_back(path);
    }
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}