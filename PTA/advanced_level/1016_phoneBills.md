# Phone Bills 

## my sol 1     20/1/25     150 min

我佛了...

这道题也太恶心了...做了我2个半小时...代码写了150行，写得又臭又长......

已经不想贴代码了...

> phoneBills.cpp

```
/**
 * @vars:
 *      vector<vector<Record*>> records, records[i] -- every customer; 
 *                                       records[i][j] -- every records
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

double toll[24];

struct Record {
    string id;
    string T;
    string status;
};

int lastingT(string time1, string time2) {
    int d1, d2, h1, h2, m1, m2;
    d1 = atoi(time1.substr(3, 2).c_str());
    h1 = atoi(time1.substr(6, 2).c_str());
    m1 = atoi(time1.substr(9, 2).c_str());
    d2 = atoi(time2.substr(3, 2).c_str());
    h2 = atoi(time2.substr(6, 2).c_str());
    m2 = atoi(time2.substr(9, 2).c_str());
    return (d2-d1)*24*60 + (h2-h1)*60 + (m2-m1);
}

double cost(string time1, string time2) {
    double result = 0.0;
    int d1, d2, h1, h2, m1, m2;
    d1 = atoi(time1.substr(3, 2).c_str());
    h1 = atoi(time1.substr(6, 2).c_str());
    m1 = atoi(time1.substr(9, 2).c_str());
    d2 = atoi(time2.substr(3, 2).c_str());
    h2 = atoi(time2.substr(6, 2).c_str());
    m2 = atoi(time2.substr(9, 2).c_str());
    if (d1 < d2) {
        for (int i = 0; i < 24; i++) {
            result += (double)toll[i] * (d2 - d1 - 1) * 60;
        }
        result += (60 - m1) * toll[h1] + m2 * toll[h2];     // min
        for (int t1 = h1+1; t1 < 24; t1++) {                // pre day hour
            result += 60 * toll[t1];
        }
        for (int t2 = 0; t2 < h2; t2++) {                   // after day hour
            result += 60 * toll[t2];
        }
    } else if (h1 < h2) {
        result += (60 - m1) * toll[h1] + m2 * toll[h2];     // min
        for (int t = h1+1; t < h2; t++) {
            result += 60 * toll[t];
        }
    } else {
        result = (m2 - m1) * toll[h1];
    }
    return result;
}

bool compName(vector<Record*> v1, vector<Record*> v2) {
    string name1 = v1[0]->id, name2 = v2[0]->id;
    int len = name1.length() > name2.length() ? name2.length() : name1.length();
    int i;
    for (i = 0; i < len; i++) {
        if (name1[i] < name2[i]) return true;
        else if (name1[i] > name2[i]) return false;
    }
    if (i < name1.length()) return false;
    return true;
}

bool compTime(Record* r1, Record* r2) {
    string time1 = r1->T, time2 = r2->T;
    if (time1.substr(3, 2) < time2.substr(3, 2)) return true;
    else if (time1.substr(3, 2) > time2.substr(3, 2)) return false;

    if (time1.substr(6, 2) < time2.substr(6, 2)) return true;
    else if (time1.substr(6, 2) > time2.substr(6, 2)) return false;

    if (time1.substr(9, 2) < time2.substr(9, 2)) return true;
    else if (time1.substr(9, 2) > time2.substr(9, 2)) return false;

    return true;
}

int main() {
    double t;
    for (int i = 0; i < 24; i++) {
        scanf("%lf", &t);
        toll[i] = t * 0.01;
    }
    int num;
    scanf("%d", &num);
    vector<vector<Record*>> records;     // distinguish from p to p

    // input
    string id, T, status;
    bool done;
    for (int i = 0; i < num; i++) {
        done = false;
        cin >> id >> T >> status;
        Record* r = new Record;
        r->id = id;
        r->T = T;
        r->status = status;
        for (int j = 0; j < records.size(); j++) {
            if (records[j][0]->id == id) {
                records[j].push_back(r);
                done = true;
                break;
            }
        }
        if (!done) records.push_back({r});
    }

    // sort
    sort(records.begin(), records.end(), compName);
    for (int i = 0; i < records.size(); i++) {
        sort(records[i].begin(), records[i].end(), compTime);
    }

    // output
    double total, cur;
    for (int i = 0; i < records.size(); i++) {
        printf("%s %s\n", records[i][0]->id.c_str(), records[i][0]->T.substr(0, 2).c_str());
        total = 0.0;
        for (int j = 0; j < records[i].size() - 1; j++) {
            if (records[i][j]->status == "on-line" &&
                        records[i][j+1]->status == "off-line") {
                printf("%s %s ", records[i][j]->T.substr(3, 8).c_str(), 
                        records[i][j+1]->T.substr(3, 8).c_str());
                printf("%d $%.02f\n", lastingT(records[i][j]->T, records[i][j+1]->T), 
                        cur = cost(records[i][j]->T, records[i][j+1]->T));
                total += cur;
            }
        }
        printf("Total amount: $%.02f\n", total);
    }
    return 0;
}
```

## ref sol 1

很好，liu又只花了50行就写完了...

来我们看看她的高见：

> phoneBills2.cpp

