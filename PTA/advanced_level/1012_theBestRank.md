# The Best Rank

## my sol 1     20/1/22     30 min

半途而废了...感觉这样写写不出来

```
/**
 * 思路: 先写一个类用于存放全部成绩信息 
 * 然后建四个指针数组，分别用于对四个成绩的排序
 * 再写一个用于类的特定property排序的方法
 */

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Student {
    int id;
    int C, M, E, A;
};

Student students[2050];
Student* C_order[2050], *M_order[2050], *E_order[2050], *A_order[2050];

bool compare_C(Student* a, Student* b) {
    return a->C < b->C;     // < 为升序排列
}
bool compare_M(Student* a, Student* b) {
    return a->M < b->M;     // < 为升序排列
}
bool compare_E(Student* a, Student* b) {
    return a->E < b->E;     // < 为升序排列
}
bool compare_A(Student* a, Student* b) {
    return a->A < b->A;     // < 为升序排列
}

int main() {
    int num, query;
    cin >> num >> query;
    for (int i = 0; i < num; i++) {
        cin >> students[i].C >> students[i].M >> students[i].E;
        students[i].A = (students[i].C + students[i].M + students[i].E) / 3;
        C_order[i] = M_order[i] = E_order[i] = A_order[i] = &students[i];
    }

    sort(C_order, C_order + num, compare_C);
    sort(M_order, M_order + num, compare_M);
    sort(E_order, E_order + num, compare_E);
    sort(A_order, A_order + num, compare_A);

    // map<int, char[2]> namemap;
    // for (int i = 0; i < num; i++) {
    //     namemap[A_order[i]->id] = {i + '1', 'C'};
    // }
    // for (int i = 0; i < num; i++) {
    //     if (i + '1' < namemap[M_order])
    // }

    return 0;
}
```

## my sol 2     20/1/22     20 min

太难了吧......

我真的感觉不会做了......

分情况太多了......

```
/**
 * 思路: 先写一个类用于存放全部成绩信息 
 * 然后建四个指针数组，分别用于对四个成绩的排序
 * 再写一个用于类的特定property排序的方法
 */

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct Student {
    int id;
    int C, M, E, A;     // grade
    int C_rank, M_rank, E_rank, A_rank;
};

Student students[2050];
Student* order[2050];

bool compare_C(Student* a, Student* b) {
    return a->C < b->C;     // < 为升序排列
}
bool compare_M(Student* a, Student* b) {
    return a->M < b->M;     // < 为升序排列
}
bool compare_E(Student* a, Student* b) {
    return a->E < b->E;     // < 为升序排列
}
bool compare_A(Student* a, Student* b) {
    return a->A < b->A;     // < 为升序排列
}

int main() {
    int num, query;
    cin >> num >> query;
    map<int, Student*> namemap;
    for (int i = 0; i < num; i++) {
        Student* student = new Student;
        cin >> student->id >> student->C >> student->M >> student->E;
        student->A = (student->C + student->M + student->E) / 3;
        namemap[student->id] = student;

        order[i] = student;
    }

    int delay;
    sort(order, order + num, compare_A);
    order[0]->A_rank = 1;
    delay = 1;
    for (int i = 1; i < num; i++) {
        if (order[i]->A == order[i-1]->A) {
            order[i]->A_rank = order[i-1]->A_rank = -1;     // -1 means undecided
            delay++;
        } else {
            order[i]->A_rank = order[i-1]->A_rank + delay;
            delay = 1;
        }
    }
    sort(order, order + num, compare_C);
    order[0]->C_rank = 1;
    delay = 1;
    for (int i = 1; i < num; i++) {
        if (order[i]->C == order[i-1]->C) {
            order[i]->C_rank = order[i-1]->C_rank = -1;
            delay++;
        } else {
            order[i]->C_rank = order[i-1]->C_rank + delay;
            delay = 1;
        }   
    }
    sort(order, order + num, compare_M);
    order[0]->M_rank = 1;
    delay = 1;
    for (int i = 1; i < num; i++) {
        if (order[i]->M == order[i-1]->M) {
            order[i]->M_rank = order[i-1]->M_rank = -1;
            delay++;
        } else {
            order[i]->M_rank = order[i-1]->M_rank + delay;
            delay = 1;
        }   
    }
    sort(order, order + num, compare_E);
    order[0]->E_rank = 1;
    delay = 1;
    for (int i = 1; i < num; i++) {
        if (order[i]->E == order[i-1]->E) {
            order[i]->E_rank = order[i-1]->E_rank = -1;
            delay++;
        } else {
            order[i]->E_rank = order[i-1]->E_rank + delay;
            delay = 1;
        }   
    }

    // emmmmmmmmmmmm

    return 0;
}
```

## ref sol 1

```
#include <cstdio>
#include <algorithm>
using namespace std;
struct node {
    int id, best;
    int score[4], rank[4];
}stu[2005];
int exist[1000000], flag = -1;
bool cmp1(node a, node b) {return a.score[flag] > b.score[flag];}
int main() {
    int n, m, id;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
        stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;
    }
    for(flag = 0; flag <= 3; flag++) {
        sort(stu, stu + n, cmp1);
        stu[0].rank[flag] = 1;
        for(int i = 1; i < n; i++) {
            stu[i].rank[flag] = i + 1;
            if(stu[i].score[flag] == stu[i-1].score[flag])
                stu[i].rank[flag] = stu[i-1].rank[flag];
        }
    }
    for(int i = 0; i < n; i++) {
        exist[stu[i].id] = i + 1;
        stu[i].best = 0;
        int minn = stu[i].rank[0];
        for(int j = 1; j <= 3; j++) {
            if(stu[i].rank[j] < minn) {
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    char c[5] = {'A', 'C', 'M', 'E'};
    for(int i = 0; i < m; i++) {
        scanf("%d", &id);
        int temp = exist[id];
        if(temp) {
            int best = stu[temp-1].best;
            printf("%d %c\n", stu[temp-1].rank[best], c[best]);
        } else {
            printf("N/A\n");
        }
    }
    return 0;
}
```

emmmmmmmm