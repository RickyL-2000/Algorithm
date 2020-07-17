# A+B_for_polynomials

## my sol 1     20/1/19     30 min

佛了，想了好半天如何不浪费空间，结果别人直接一个1001数组了事...

```
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct term {
    double a;
    int N;
};

int main() {
    int len1, len2;
    vector<term*> pol1, pol2;
    cin >> len1;
    int N;
    double a;
    for (int i = 0; i < len1; i++) {
        cin >> N >> a;
        term* new_term = new term;
        new_term->a = a;
        new_term->N = N;
        pol1.push_back(new_term);
    }
    cin >> len2;
    for (int i = 0; i < len2; i++) {
        cin >> N >> a;
        term* new_term = new term;
        new_term->a = a;
        new_term->N = N;
        pol2.push_back(new_term);
    }

    size_t i = 0, j = 0;
    vector<term*> ans;
    while (i < pol1.size() && j < pol2.size()) {
        if (pol1[i]->N > pol2[j]->N) {
            ans.push_back(pol1[i]);
            i++;
        } else if (pol1[i]->N < pol2[j]->N) {
            ans.push_back(pol2[j]);
            j++;
        } else {
            pol1[i]->a += pol2[j]->a;
            ans.push_back(pol1[i]);
            i++;
            j++;
        }
    }
    while (i < pol1.size()) {
        ans.push_back(pol1[i]);
        i++;
    }
    while (j < pol2.size()) {
        ans.push_back(pol2[j]);
        j++;
    }
    
    printf("%lu ", ans.size());

    for (i = 0; i < ans.size(); i++) {
        printf("%d %.1f", ans[i]->N, ans[i]->a);
        if (i != ans.size()-1) printf(" ");
    }

    return 0;
}
```

## ref sol 1

一个大数组了事...

看来不能总是苛求性能，能做题才是王道！

```
#include <iostream>
using namespace std;
int main() {
    float c[1001] = {0};
    int m, n, t;
    float num;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (c[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
```

## my sol 2

主要是用于复习一下四个月前的东西...

> 1002_A+B_for_polynomials2.cpp