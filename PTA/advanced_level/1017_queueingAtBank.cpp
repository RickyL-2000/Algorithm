#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Customer {
    int arrT;
    int costT;
    int servT;
    int remT;
};

int now_time = 8*3600;
Customer* customers[10010];

bool cmp1(Customer* c1, Customer* c2) {
    if (c1->arrT < c2->arrT) return true;
    return false;
}

size_t minServT(vector<Customer*> windows) {
    int minT = windows[0]->servT;
    size_t ans = 0;
    for (size_t i = 1; i < windows.size(); i++) {
        if (windows[i] != nullptr && windows[i]->costT < minT) {
            minT = windows[i]->costT;
            ans = i;
        }
    }
    return ans;
}

int main() {
    int num, k;
    scanf("%d %d", &num, &k);
    vector<Customer*> windows(k);
    fill(windows.begin(), windows.end(), nullptr);
    for (int i = 0; i < num; i++) {
        int hh, mm, ss, c;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &c);
        Customer* customer = new Customer;
        customer->arrT = hh * 3600 + mm * 60 + ss;
        customer->costT = c;
        if (c > 60) customer->remT = 60;
        else customer->remT = c;
        customers[i] = customer;
    }
    sort(customers, customers + num, cmp1);

    int servingN = 0;       // the number of working windows
    int index;
    for (size_t i = 0; i < num; i++) {
        if (i < k && customers[i]->arrT < now_time) {
            windows[i] = customers[i];
            customers[i]->servT = now_time;
            servingN++;
        } else {
            index = i;
            break;
        }
    }

    // TODO 有可能8点前到的人比k多
    while (servingN != 0) {
        int minTCust = minServT(windows);
        if (servingN == k) {            // full
            for (size_t i = 0; i < windows.size(); i++) {
                if (windows[i] != nullptr) {
                    windows[i]->remT -= windows[minTCust]->remT;
                }
            }
            now_time += windows[minTCust]->remT;
            windows[minTCust] = nullptr;
            servingN--;
        } else if (servingN < k) {      // not full
            if (index < num && windows[minTCust]->remT + now_time > customers[index]->arrT) {       // new arrers first
                for (size_t i = 0; i < windows.size(); i++) {
                    if (windows[i] != nullptr) {
                        windows[i]->remT -= customers[index]->arrT - now_time;
                    }
                }
                for (size_t i = 0; i < windows.size(); i++) {   // find an empty seat
                    if (windows[i] == nullptr) {
                        windows[i] = customers[index];
                        break;
                    }
                }
                customers[index]->servT = now_time;
                now_time = customers[index]->arrT;
                servingN++;
                index++;
            } else if ((index < num && windows[minTCust]->remT + now_time < customers[index]->arrT) ||
                        index >= num) {    // minTCust finishes first
                for (size_t i = 0; i < windows.size(); i++) {
                    if (windows[i] != nullptr) {
                        windows[i]->remT -= windows[minTCust]->remT;
                    }
                }
                now_time += windows[minTCust]->remT;
                windows[minTCust] = nullptr;
                servingN--;
            } else if (index < num && windows[minTCust]->remT + now_time == customers[index]->arrT) {   // they done syncly
                for (size_t i = 0; i < windows.size(); i++) {
                    if (windows[i] != nullptr) {
                        windows[i]->remT -= windows[minTCust]->remT;
                    }
                }
                windows[minTCust] = customers[index];
                customers[index]->servT = now_time;
                now_time = customers[index]->arrT;
                index++;
            }
        }
    }

    // 到这里就排完所有人了...然后就是输出了...但是实在是不想写了...逻辑写得又臭又长......

}