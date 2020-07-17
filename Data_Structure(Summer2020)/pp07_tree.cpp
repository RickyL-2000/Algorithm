#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int left[12],
        right[12];
    bool visited[12];
    fill(left, left+12, -1);
    fill(right, right+12, -1);
    fill(visited, visited+12, false);

    int n, root;
    char temp1, temp2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // scanf("%c %c", &temp1, &temp2);
        cin >> temp1 >> temp2;
        if (temp1 != '-') {
            left[i] = temp1 - '0';
            visited[left[i]] = true;
        }
        if (temp2 != '-') {
            right[i] = temp2 - '0';
            visited[right[i]] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            root = i;
            break;
        }
    }

    vector<int> ans;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (left[node] == -1 && right[node] == -1) {
            ans.push_back(node);
            continue;
        }
        if (left[node] != -1) {
            q.push(left[node]);
        }
        if (right[node] != -1) {
            q.push(right[node]);
        }
    }
    printf("%d", ans[0]);
    for (int i = 1; i < ans.size(); i++) {
        printf(" %d", ans[i]);
    }
    return 0;
}