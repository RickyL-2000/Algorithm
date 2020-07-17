#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/**
 * one time AC 
 */

int convert(const string s) {
    stringstream stream;
    int result;
    stream << s;
    stream >> result;
    return result;
}

int toSeconds(string s) {
    string hour = s.substr(0, 2);
    string min = s.substr(3, 2);
    string sec = s.substr(6, 2);
    int result = convert(hour)*3600 + convert(min)*60 + convert(sec);
    return result;
}

struct Person {
    string ID;
    string in_time;
    string out_time;

    bool in_earlier_than(const Person& another) {
        if (toSeconds(in_time) < toSeconds(another.in_time)) return true;
        return false;
    }
    bool out_earlier_than(const Person& another) {
        if (toSeconds(out_time) < toSeconds(another.out_time)) return true;
        return false;
    }
};

int main() {
    vector<Person*> table;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        Person* person = new Person;
        cin >> person->ID >> person->in_time >> person->out_time;
        table.push_back(person);
    }

    Person* unlock = table[0], *lock = table[0];
    for (int i = 1; i < m; i++) {
        if (table[i]->in_earlier_than(*unlock)) {
            unlock = table[i];
        }
        if (lock->out_earlier_than(*table[i])) {
            lock = table[i];
        }
    }

    cout << unlock->ID << ' ' << lock->ID << endl;
    return 0;
}