#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n, num;
    vector<int> nums;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        nums.push_back(num);
    }
    sort(nums.begin(), nums.end());
    int k = 0;  // height
    while ((1<<k) < n) k++;
    k = max(0, k-1);
    int root;
    if (n + 1 - (1<<k) <= (1<<(k-1))) {
        root = n - (1<<(k-1));
    } else {
        root = (1<<k) - 1;
    }
    queue<vector<int>> q;
    vector<int> node = {root, 0, (int)nums.size()};
    q.push(node);
    vector<int> ans;
    while (!q.empty()) {
        node = q.front(), q.pop();
        ans.push_back(node[0]);
        // left
        int n_ = node[0] - node[1];
        int k_ = 0;
        while ((1<<k_) < n_) k_++;
        k_ = max(0, k_-1);
        int root_;
        if (n_ + 1 - (1<<k_) <= (1<<(k_-1))) {
            root_ = n_ - (1<<(k_-1)) + node[1];
        } else {
            root_ = (1<<k_) - 1 + node[1];
        }
        vector<int> newNode = {root_, node[1], node[0]-1};
        q.push(newNode);

        // right
        n_ = node[2] - node[0] - 1;
        k_ = 0;
        while ((1<<k_) < n_) k_++;
        k_ = max(0, k_-1);
        if (n_ + 1 - (1<<k_) <= (1<<(k_-1))) {
            root_ = n_ - (1<<(k_-1)) + node[0] + 1;
        } else {
            root_ = (1<<k_) - 1 + node[0] + 1;
        }
        newNode = {root_, node[0]+1, node[2]};
        q.push(newNode);
    }
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}