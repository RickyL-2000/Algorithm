# PAT judge

## my sol 1     20/1/26     90 min

19/25

有两个测试点没有过...肯定还是想漏了几个可能性

> patJudge.cpp

```
#include <iostream>
#include <algorithm>
using namespace std;

struct User {
    int id;
    int score[6];     // start from 1
    int total = 0;
    int perN = 0;     // # of perfect answered problems
    User(int i) : id(i) {fill(score, score+6, -1);}
};

User* users[10010];     // index: first id, then rank
int problems[6];
int num, k, m;

bool cantPass(User* u) {
    for (int i = 1; i <= k; i++) {
        if (u->score[i] != -1 && u->score[i] != 0) return false;
    }
    return true;
}

int main() {
    scanf("%d %d %d", &num, &k, &m);
    for (int i = 1; i <= k; i++) {
        scanf("%d", &problems[i]);
    }
    int u_id, p_id, sco;
    fill(users+1, users + num+1, nullptr);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u_id, &p_id, &sco);
        if (u_id < 1 || u_id > num) continue;
        if (users[u_id] == nullptr) {       // build a new one
            User* user = new User(u_id);
            if (sco == -1) user->score[p_id] = 0;
            else {
                user->score[p_id] = sco;
                user->total = sco;
            }
            if (sco == problems[p_id]) user->perN++;
            users[u_id] = user;
        } else {
            if (users[u_id]->score[p_id] < sco) {
                users[u_id]->total += users[u_id]->score[p_id] == -1 ? sco : sco - users[u_id]->score[p_id];
                users[u_id]->score[p_id] = sco;
                if (sco == problems[p_id]) users[u_id]->perN++;
            } else if (sco == -1 && users[u_id]->score[p_id] == -1) {
                users[u_id]->score[p_id] = 0;
            }
        }
    }
    sort(users+1, users+num+1, [](User* u1, User* u2) {
                                    if (u1 == nullptr) return false;
                                    else if (u2 == nullptr) return true;
                                    return (u1->total > u2->total) ||
                                           (u1->total == u2->total && u1->perN > u2->perN) ||
                                           (u1->total == u2->total && u1->perN == u2->perN && u1->id < u2->id);
                                });
    int preRank = 1, preScore = -1;
    for (int i = 1; i <= num; i++) {
        if (users[i] == nullptr || cantPass(users[i])) continue;
        if (users[i]->total == preScore) printf("%d %05d %d", preRank, users[i]->id, preScore);
        else printf("%d %05d %d", preRank = i, users[i]->id, preScore = users[i]->total);
        for (int j = 1; j <= k; j++) {
            if (users[i]->score[j] >= 0) printf(" %d", users[i]->score[j]);
            else printf(" -");
        }
        printf("\n");
    }
    return 0;
}
```

## ref sol 1

