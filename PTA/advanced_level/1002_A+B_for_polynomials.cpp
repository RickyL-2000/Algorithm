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