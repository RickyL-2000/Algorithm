#include <iostream>
using namespace std;
struct node{
    int l, r;
}a[100];
int maxn = -1, ans;
void dfs(int root, int index) {
    if(index > maxn) {  // 在所有可能遇到的index中找到最大值，因为如果是完全二叉树这个最大值就是树的结点个数！
        maxn = index;
        ans = root;
    }
    if(a[root].l != -1) dfs(a[root].l, index * 2);  // 这里相当于把二叉树flatten
    if(a[root].r != -1) dfs(a[root].r, index * 2 + 1);
}
int main() {
    int n, root = 0, have[100] = {0};   // have 用于查找root
    cin >> n;
    for (int i = 0; i < n; i++) {
        string l, r;
        cin >> l >> r;
        if (l == "-") {
            a[i].l = -1;
        } else {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        }
        if (r == "-") {
            a[i].r = -1;
        } else {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        }
    }
    while (have[root] != 0) root++;
    dfs(root, 1);
    if (maxn == n)
        cout << "YES " << ans;
    else
        cout << "NO " << root;
    return 0;
}