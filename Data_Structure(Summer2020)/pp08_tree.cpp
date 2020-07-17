#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

void posttraversal(int idx, int left, int right, vector<int>& pre, vector<int>& in, vector<int>& post) {
    if (left > right) return;
    int mid = left;
    while (in[mid] != pre[idx]) mid++;
    posttraversal(idx+1, left, mid-1, pre, in, post);
    posttraversal(idx+1+mid-left, mid+1, right, pre, in, post);
    post.push_back(in[mid]);
    return;
}

int main() {
    int n;
    scanf("%d", &n);
    string op;
    int num;
    stack<int> stk;
    vector<int> preorder, inorder, postorder;
    for (int i = 0; i < 2 * n; i++) {
        cin >> op;
        if (op == "Push") {
            scanf("%d", &num);
            stk.push(num);
            preorder.push_back(num);
        } else {
            num = stk.top();
            stk.pop();
            inorder.push_back(num);
        }
    }
    posttraversal(0, 0, n-1, preorder, inorder, postorder);
    printf("%d", postorder[0]);
    for (int i = 1; i < postorder.size(); i++) {
        printf(" %d", postorder[i]);
    }
    return 0;
}
