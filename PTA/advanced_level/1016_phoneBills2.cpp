#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    string name;
    int status, month, time, day, hour, minute;
};
bool cmp(node a, node b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;        // 原来还能这样！字符串直接比较就是字典顺序
}
double billFromZero(node call, int *rate) {                             // 这个真心妙极！cost也可以用累计的方法计算
    double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
    for (int i = 0; i < call.hour; i++)
        total += rate[i] * 60;
    return total / 100.0;
}
int main() {
    int rate[25] = {0}, n;
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    scanf("%d", &n);
    vector<node> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);     // 还能这样!!
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line") ? 1 : 0;
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;      // emmmm 确实是个好办法...我之前也用过，算累计时间
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node> > custom;      // 感觉这里没有我写的好 :)
    for (int i = 1; i < n; i++) {
        if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {
            custom[data[i - 1].name].push_back(data[i - 1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
    for (auto it : custom) {
        vector<node> temp = it.second;
        cout << it.first;
        printf(" %02d\n", temp[0].month);
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}