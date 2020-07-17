#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


void t_insert(int tree[], int num, int idx) {
    if (tree[idx] == 0) {
        tree[idx] = num;
        return;
    }
    if (num < tree[idx]) {
        t_insert(tree, num, 2 * idx + 1);
    } else {
        t_insert(tree, num, 2 * idx + 2);
    }
}

int main() {
    int tree[1024];
    int check[1024];
    int n, l, num;
    vector<string> ans;
    bool flag;
    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        scanf("%d", &l);
        
        fill(tree, tree + 1024, 0);
        for (int j = 0; j < n; j++) {
            scanf("%d", &num);
            t_insert(tree, num, 0);
        }
        for (int i = 0;  i < l; i++) {
            flag = true;
            fill(check, check + 1024, 0);
            for (int j = 0; j < n; j++) {
                scanf("%d", &num);
                t_insert(check, num, 0);
            }
            for (int k = 0; k < 1024; k++) {
                if (tree[k] != check[k]) {
                    ans.push_back("No");
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back("Yes");
        }
    }
    for (string str : ans) {
        cout << str << endl;
    }
    return 0;
}