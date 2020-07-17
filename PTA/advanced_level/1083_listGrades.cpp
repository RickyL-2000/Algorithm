#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string name;
    string id;
    int grade;
};

int main() {
    int n;
    cin >> n;
    vector<Student*> students;
    for (int i = 0; i < n; i++) {
        Student* student = new Student;
        cin >> student->name >> student->id >> student->grade;
        students.push_back(student);
    }
    int grade1, grade2;
    cin >> grade1 >> grade2;
    if (grade2 < grade1) swap(grade1, grade2);
    sort(students.begin(), students.end(), [](Student* s1, Student* s2) {
        return s1->grade > s2->grade;
    });
    bool none = true;
    bool check = false;
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->grade >= grade1 && students[i]->grade <= grade2) {
            // 这里的这个if语句是为了控制结尾的多余换行符，但是经过测试貌似没有这个控制也没有关系
            if (!check) {
                cout << students[i]->name << ' ' << students[i]->id;
                check = true;
            } else cout << '\n' << students[i]->name << ' ' << students[i]->id;
            none = false;
        }
    }
    if (none) cout << "NONE";

    return 0;
}