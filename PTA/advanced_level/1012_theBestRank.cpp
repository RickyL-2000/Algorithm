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