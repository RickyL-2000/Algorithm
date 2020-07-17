# 04-树4 是否同一棵二叉搜索树 (25分)

给定一个插入序列就可以唯一确定一棵二叉搜索树。然而，一棵给定的二叉搜索树却可以由多种不同的插入序列得到。例如分别按照序列{2, 1, 3}和{2, 3, 1}插入初始为空的二叉搜索树，都得到一样的结果。于是对于输入的各种插入序列，你需要判断它们是否能生成一样的二叉搜索树。

输入格式:
输入包含若干组测试数据。每组数据的第1行给出两个正整数N (≤10)和L，分别是每个序列插入元素的个数和需要检查的序列个数。第2行给出N个以空格分隔的正整数，作为初始插入序列。最后L行，每行给出N个插入的元素，属于L个需要检查的序列。

简单起见，我们保证每个插入序列都是1到N的一个排列。当读到N为0时，标志输入结束，这组数据不要处理。

输出格式:
对每一组需要检查的序列，如果其生成的二叉搜索树跟对应的初始序列生成的一样，输出“Yes”，否则输出“No”。

输入样例:
4 2
3 1 4 2
3 4 1 2
3 2 4 1
2 1
2 1
1 2
0
输出样例:
Yes
No
No

## my sol 1     20/6/30     21 min

``` C++
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
```
