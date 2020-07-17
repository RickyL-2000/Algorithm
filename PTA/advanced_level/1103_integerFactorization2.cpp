#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, p, maxFacSum = -1;
vector<int> v, ans, tempAns;
void init() {
    int temp = 0, index = 1;
    while (temp <= n) {
        v.push_back(temp);
        temp = pow(index, p);
        index++;
    }
}
/**
 * index -- the index towards v, the powers，相当于控制最大的循环，用于遍历所有的可能性，避免遇到一个就停止寻找
 * tempSum -- 当前的和
 * tempK -- 在while内使用，用于填满tempAns
 * facSum -- 用于计算和的最大值 
 */
void dfs(int index, int tempSum, int tempK, int facSum) {
    if (tempK == k) {
        if (tempSum == n && facSum > maxFacSum) {
                ans = tempAns;
                maxFacSum = facSum;
        }
        return;
    }
    while(index >= 1) {
        if (tempSum + v[index] <= n) {
            tempAns[tempK] = index;
            dfs(index, tempSum + v[index], tempK + 1, facSum + index);
        }
        if (index == 1) return;
        index--;
    }
}
int main() {
    scanf("%d%d%d", &n, &k, &p);
    init(); 
    tempAns.resize(k);
    dfs(v.size() - 1, 0, 0, 0);
    if (maxFacSum == -1) {
        printf("Impossible");
        return 0;
    }
    printf("%d = ", n);
    for (int i = 0; i < ans.size(); i++) {
        if (i != 0) printf(" + ");
        printf("%d^%d", ans[i], p);
    }
    return 0;
}