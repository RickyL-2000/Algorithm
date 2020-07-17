#include <iostream>
#include <algorithm>
using namespace std;

// int next_[100010];
// int val[100010];
int node[100010][2];    // val, next
int stk[100010];

int main() {
    // fill(next_, next_+100010, -1);
    // fill(val, val+100010, 0);
    fill(node[0], node[0] + 2 * 100010, -1);
    fill(stk, stk + 100010, -1);
    int addr, n, k;
    int head, nxt, vl;
    scanf("%d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &addr, &vl, &nxt);
        // next_[addr] = nxt;
        // val[addr] = vl;
        node[addr][0] = vl;
        node[addr][1] = nxt;
    }

    int ptr = head, idx = 0;
    while (idx <= n) {
        if (idx % k == 0 && idx != 0) {
            int ptr_ = stk[idx-1];
            if (idx == k) head = ptr_;
            for (int i = 1; i < k; i++) {
                node[ptr_][1] = stk[idx - 1 - i];
                ptr_ = stk[idx - 1 - i];
            }
            node[ptr_][1] = ptr;
        }
        if (idx == n) break;
        stk[idx] = ptr;
        ptr = node[ptr][1];
        idx++;
    }

    ptr = head;
    while (ptr != -1) {
        if (node[ptr][1] == -1) 
            printf("%05d %d %d\n", ptr, node[ptr][0], node[ptr][1]);
        else
            printf("%05d %d %05d\n", ptr, node[ptr][0], node[ptr][1]);
        ptr = node[ptr][1];
    }
    return 0;
}