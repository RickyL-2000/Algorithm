#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 6

int parent[MAXN];

int find(int x) {
    if (parent[x] == 0) parent[x] = -1;
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
    int findLatestStep(vector<int>& arr, int m) {
        for (int i = 0; i < MAXN; i++) parent[i] = 0;
        int len = arr.size();
        vector<int> roots;
        int cnt = 0;
        int laststep = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (parent[max(1, arr[i]-1)] == 0 && parent[min(len, arr[i]+1)] == 0) {
                parent[arr[i]] = -1;
                roots.push_back(arr[i]);
                if (-parent[arr[i]] == m) cnt++;
            } else if ((parent[arr[i]-1] < 0 || parent[arr[i]-1] > 0) && parent[arr[i]+1] == 0) {
                bool flag = false;
                if (-parent[find(arr[i]-1)] == m) flag = true;
                merge(arr[i], arr[i]-1);
                if (-parent[find(arr[i])] == m) cnt++;
                else if (-parent[find(arr[i])] != m && flag) cnt--;
            } else if ((parent[arr[i]+1] < 0 || parent[arr[i]+1] > 0) && parent[arr[i]-1] == 0) {
                bool flag = false;
                if (-parent[find(arr[i]+1)] == m) flag = true;
                merge(arr[i], arr[i]+1);
                if (-parent[find(arr[i])] == m) cnt++;
                else if (-parent[find(arr[i])] != m && flag) cnt--;
            } else if ((parent[arr[i]-1] < 0 || parent[arr[i]-1] > 0) && (parent[arr[i]+1] < 0 || parent[arr[i]+1] > 0)) {
                bool flag1 = false, flag2 = false;
                if (-parent[find(arr[i]-1)] == m) flag1 = true;
                if (-parent[find(arr[i]+1)] == m) flag2 = true;
                merge(arr[i], arr[i]-1);
                merge(arr[i], arr[i]+1);
                if (-parent[find(arr[i])] == m) cnt++;
                else if (-parent[find(arr[i])] != m) {
                    if (flag1) cnt--;
                    if (flag2) cnt--;
                }
            }
            if (cnt > 0) laststep = i+1;
        }
        return laststep;
    }
};

int main() {
    vector<int> arr = {3,1,5,4,2};
    int m = 2;
    Solution s;
    cout << s.findLatestStep(arr, m);
    return 0;
}