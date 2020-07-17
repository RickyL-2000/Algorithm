/*
 * 02 - 线性结构4 Pop Sequence
 * */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int m, n, k, num, cnt;
    scanf("%d %d %d", &m, &n, &k);
    stack<int> stk;
    vector<bool> ans;
    vector<int> input;
    for (int i = 0; i < k; i++) {
        bool cont_flag = false;
        cnt = 0;
        while (!stk.empty()) stk.pop();
        input.clear();
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            input.push_back(num);
        }
        for (int num : input) {
            // scanf("%d", &num);
            while (stk.empty() || stk.top() < num) {
                cnt++;
                stk.push(cnt);
            }
            if (stk.size() > m) {
                ans.push_back(false);
                cont_flag = true;
                break;
            }
            if (stk.top() > num) {
                ans.push_back(false);
                cont_flag = true;
                break;
            }
            stk.pop();
        }
        if (cont_flag) continue;
        else ans.push_back(true);
    }
    for (bool yes : ans) {
        if (yes) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}