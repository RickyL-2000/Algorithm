#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

const int maxN = 210;
const int INF = 99999999;
int n, k;
int edge[maxN][maxN];
vector<int> pre[maxN];
bool visited[maxN];
map<string, int> city_m;
vector<string> city_v;

int main() {
    fill(edge[0], edge[0] + maxN * maxN, INF);
    cin >> n >> k;
    string c1, c2;
    cin >> c1;
    city_v.push_back(c1);
}