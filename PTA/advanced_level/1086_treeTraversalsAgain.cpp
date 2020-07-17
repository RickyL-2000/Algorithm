#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
vector<int> pre, in, post,value;
void postorder(int root, int start, int end) {
    if (start > end) return;
    int i = start;      
    // i 是在in中的索引，pre中的每一个都是下一阶级的根，所以要在in中找出root的i，然后左右两边就是两个子树
    while (i < end && in[i] != pre[root]) i++;
    postorder(root + 1, start, i - 1);
    postorder(root + 1 + i - start, i + 1, end);    // i-start 就是左子树的结点数量，加上i-start就是右子树的根
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    char str[5];
    stack<int> s;
    int key=0;
    while (~scanf("%s", str)) {
        if (strlen(str) == 4) {
            int num;
            scanf("%d", &num);
            value.push_back(num);
            pre.push_back(key);
            s.push(key++);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    postorder(0, 0, n - 1);
    printf("%d", value[post[0]]);
    for (int i = 1; i < n; i++)
        printf(" %d",value[post[i]]);
    return 0;
}