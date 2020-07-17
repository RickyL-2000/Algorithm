#include <iostream>
#include <algorithm>
using namespace std;

int next_[100010];
int val[100010];
int stk[100010];

int main() {
    fill(next_, next_+100010, -1);
    fill(val, val+100010, 0);
    int addr, n, k;
    int head, nxt, vl;
    scanf("%d %d %d", &head, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &addr, &vl, &nxt);
        next_[addr] = nxt;
        val[addr] = vl;
    }

    int ptr = head, cnt = 0;
    int up = (n / k) * k;
    while (cnt <= up) {
        if (cnt % k != 0 || cnt == 0) {
            stk[cnt] = ptr;
            cnt++;
            ptr = next_[ptr];
        } else {
            int ptr_ = stk[cnt-1];
            if (cnt == k) head = ptr_;
            for (int i = 1; i < k; i++) {
                next_[ptr_] = stk[cnt - 1 - i];
                ptr_ = stk[cnt - 1 - i];
            }
            next_[ptr_] = ptr;

            stk[cnt] = ptr;
            cnt++;
            ptr = next_[ptr];
        }
    }

    ptr = head;
    while (ptr != -1) {
        if (next_[ptr] == -1) 
            printf("%05d %d %d\n", ptr, val[ptr], next_[ptr]);
        else
            printf("%05d %d %05d\n", ptr, val[ptr], next_[ptr]);
        ptr = next_[ptr];
    }
    return 0;
}