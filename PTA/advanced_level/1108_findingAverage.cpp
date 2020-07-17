#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    int n, cnt = 0;
    cin >> n;
    vector<double> nums;
    vector<string> errors;
    string temp;
    double num;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (sscanf(temp.c_str(), "%lf", &num) == 1 && 
            num <= 1000.0 && num >= -1000.0 && num*100 - double((int)num*100) == 0.0) {
                nums.push_back(num);
                cnt++;
        } else {
            errors.push_back(temp);
        }
    }
    for (size_t i = 0; i < errors.size(); i++) {
        printf("ERROR: %s is not a legal number\n", errors[i].c_str());
    }
    double avg = 0;
    for (size_t i = 0; i < cnt; i++) {
        avg += nums[i];
    }
    avg /= (double)cnt;
    printf("The average of %d numbers is %.2lf", cnt, avg);
    return 0;
}