
#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const double D = 15.0;
double jump, cr[101][2];
int n;
bool cmp(int i, int j);
int bfs(int &v, vector<int>& path);
 
int main() {
	int i, v = 0, flag = 0;
	scanf("%d%lf", &n, &jump);
	vector<int> path(n + 1, -1), spath;
	cr[0][0] = 0;cr[0][1] = 0;
	for (i = 1;i <= n;i++)
		scanf("%lf%lf", &cr[i][0], &cr[i][1]);
	if (jump + D / 2 >= 50) //从岛上可以直接到岸
		flag = 1;
	else flag = bfs(v, path);
	if (!flag) printf("0");
	else {
		while (v) {
			spath.push_back(v);
			v = path[v];
		}
		printf("%d\n", spath.size() + 1);
		for (i = spath.size() - 1; i >= 0; i--)
			printf("%.0f %.0f\n", cr[spath[i]][0], cr[spath[i]][1]);
	}
	return 0;
}
 
 
int bfs(int &v, vector<int>& path) {
	vector<int> dist(n + 1, -1),  first(n + 1);
	queue<int> q;
	double firstdis;
	int flag = 0, i;
	dist[v] = 0;
	for (i = 0;i < n + 1;i++)
		first[i] = i;
	//多条路径相同时输出第一跳距离最小,则第一跳的节点入队列之前先从小到大排队
	sort(first.begin(), first.end(), cmp);
	for (i = 1;i < n + 1;i++) {
		v = first[i];
		firstdis = sqrt(pow(cr[v][0], 2) + pow(cr[v][1], 2));
		if (firstdis > D / 2 && firstdis <= jump + D / 2) {
			q.push(v);
			dist[v] = 1;
			path[v] = 0;
		}
	}
	while (!q.empty()) {
		v = q.front();
		q.pop();
		if ((fabs(cr[v][0]) + jump >= 50 || fabs(cr[v][1]) + jump >= 50)) {
			flag = 1;
			break;
		}
		else {
			for (i = 1;i < n + 1;i++) {
				if (dist[i] == -1 &&
					(sqrt(pow(cr[v][0] - cr[i][0], 2) + pow(cr[v][1] - cr[i][1], 2)) <= jump)) {
					dist[i] = dist[v] + 1;
					path[i] = v;
					q.push(i);
				}
			}
		}
	}
	return flag;
}
 
bool cmp(int i, int j) {
	return pow(cr[i][0], 2) + pow(cr[i][1], 2) < pow(cr[j][0], 2) + pow(cr[j][1], 2);
}