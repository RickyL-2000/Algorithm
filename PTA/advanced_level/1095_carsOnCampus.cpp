#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k;
map<string, int> record_index;
struct Record {
    string _id;
    int _time;
    string _status;
    bool _valid;
};
struct Car {
    string _id;
    vector<int> _in_time;
    vector<int> _out_time;
};

int main() {
    cin >> n >> k;

}