#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int maxN = 210;
const int INF = 99999999;
int n, k;
int edge[maxN][maxN];
map<string, int> city_m;
vector<string> city_v;
vector<int> happiness;
bool visited[maxN];
int sum_cost[maxN];
int sum_path[maxN];
int sum_hap[maxN];
int pre[maxN];       // the pre step，用于定位最佳的路线
double ave_hap[maxN];

int main() {
    cin >> n >> k;
    fill(edge[0], edge[0] + n*n, INF);
    string c1, c2;
    int h, cost;
    cin >> c1;
    city_m[c1] = 0;
    city_v.push_back(c1);
    happiness.push_back(0);
    for (int i = 1; i < n; i++) {
        cin >> c1 >> h;
        city_m[c1] = i;
        city_v.push_back(c1);
        happiness.push_back(h);
    }
    for (int i = 0; i < k; i++) {
        cin >> c1 >> c2 >> cost;
        edge[city_m[c1]][city_m[c2]] = edge[city_m[c2]][city_m[c1]] = cost;
    }

    fill(sum_cost, sum_cost + n, INF);
    sum_cost[0] = 0;
    sum_path[0] = 1;
    sum_hap[0] = 0;
    ave_hap[0] = 0;
    pre[0] = -1;
    for (int i = 0; i < n; i++) {
        // find the min ele
        int index, min = INF;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && sum_cost[j] < min) {
                min = sum_cost[j];
                index = j;
            }
        }

        visited[index] = true;
        for (int j = 0; j < n; j++) {
            if (visited[j] == false && edge[index][j] != INF) {
                // 如果新的点的累计cost更多
                if (sum_cost[j] > sum_cost[index] + edge[index][j]) {
                    sum_cost[j] = sum_cost[index] + edge[index][j];
                    sum_path[j] = sum_path[index];
                    // double temp_num = ((double)sum_hap[index] + (double)happiness[j]);
                    // double temp_dem = ((double)sum_hap[index]/ave_hap[index] + 1);
                    // ave_hap[j] = temp_num / temp_dem;
                    if (index == 0) ave_hap[j] = (double)sum_hap[index] + (double)happiness[j];
                    else ave_hap[j] = ((double)sum_hap[index] + (double)happiness[j]) / ((double)sum_hap[index]/ave_hap[index] + 1);
                    sum_hap[j] = sum_hap[index] + happiness[j];
                    pre[j] = index;
                // 如果新的点和当前点的累计cost一样多
                } else if (sum_cost[j] == sum_cost[index] + edge[index][j]) {
                    sum_path[j] = sum_path[j] + sum_path[index];    // 增加path的数量
                    // 如果新的点的累计happiness比较少
                    if (sum_hap[index] + happiness[j] > sum_hap[j]) {
                        ave_hap[j] = ((double)sum_hap[index] + (double)happiness[j]) / ((double)sum_hap[index]/ave_hap[index] + 1);
                        sum_hap[j] = sum_hap[index] + happiness[j];
                        pre[j] = index;
                    // 如果两个点的happiness一样多
                    } else if (sum_hap[index] + happiness[j] == sum_hap[j]) {
                        // 如果新的点的累计ave_hap比较少
                        if (ave_hap[j] < ((double)sum_hap[index] + (double)happiness[j]) / ((double)sum_hap[index]/ave_hap[index] + 1)) {
                            ave_hap[j] = ((double)sum_hap[index] + (double)happiness[j]) / ((double)sum_hap[index]/ave_hap[index] + 1);
                            sum_hap[j] = sum_hap[index] + happiness[j];
                            pre[j] = index;
                        }
                    }
                }
            }
        }
    }

    int r = city_m["ROM"];
    cout << sum_path[r] << ' ' << sum_cost[r] << ' ' << sum_hap[r] << ' ' << (int)ave_hap[r] << endl;

    vector<string> stk;
    while (pre[r] != -1) {
        stk.push_back(city_v[pre[r]]);
        r = pre[r];
    }
    for (auto it = stk.rbegin(); it != stk.rend(); it++) {
        cout << *it << "->";
    }
    cout << "ROM";

    return 0;
}