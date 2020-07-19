# 单调队列

顾名思义，单调队列的重点分为 "单调" 和 "队列"

"单调" 指的是元素的的 "规律"——递增（或递减）

"队列" 指的是元素只能从队头和队尾进行操作

Ps. 单调队列中的 "队列" 与正常的队列有一定的区别，稍后会提到

Ps. 此处的 "队列" 跟普通队列的一大不同就在于可以从队尾进行操作，STL 中有类似的数据结构 deque。

## Example

sliding window

ref code
``` C++
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define maxn 1000100
using namespace std;
int q[maxn],    // 存的是index
    a[maxn];
int n, k;
void getmin() {
  int head = 0, tail = 0;
  for (int i = 1; i < k; i++) {
    while (head <= tail && a[q[tail]] >= a[i]) tail--;
    q[++tail] = i;
  }
  for (int i = k; i <= n; i++) {
    while (head <= tail && a[q[tail]] >= a[i]) tail--;
    q[++tail] = i;
    while (q[head] <= i - k) head++;
    printf("%d ", a[q[head]]);
  }
}

void getmax() {
  int head = 0, tail = 0;
  for (int i = 1; i < k; i++) {
    while (head <= tail && a[q[tail]] <= a[i]) tail--;
    q[++tail] = i;
  }
  for (int i = k; i <= n; i++) {
    while (head <= tail && a[q[tail]] <= a[i]) tail--;
    q[++tail] = i;
    while (q[head] <= i - k) head++;
    printf("%d ", a[q[head]]);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  getmin();
  printf("\n");
  getmax();
  printf("\n");
  return 0;
}
```
