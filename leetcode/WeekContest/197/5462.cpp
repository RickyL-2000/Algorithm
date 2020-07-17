#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
    // struct cmp {
    //     bool operator (pair<int, double> a, pair<int, double> b) {
    //         return a.second < b.second;
    //     }
    // };
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        map<vector<int>, int> edge_list;
        for (int i = 0; i < edges.size(); i++) {
            edge_list[{edges[i][0], edges[i][1]}] = i;
            edge_list[{edges[i][1], edges[i][0]}] = i;
        }
        vector<bool> visited(n, false);
        vector<pair<int, double>> dist(n);
        for (int i = 0; i < n; i++) {
            dist[i] = make_pair(i, 0.0);
        }
        // priority_queue<pair<int, double>, vector<pair<int, double>>, cmp> pq;
        // for (auto e: dist) pq.push(e);
        dist[start].second = -1.0;
        for (int i = 0; i < n; i++) {

            int u = -1, minn = 10;
            for (int j = 0; j < n; j++) {
                if (dist[j].second < minn && visited[j] == false) {
                    u = j;
                    minn = dist[j].second;
                }
            }
            if (u == -1) break;
            visited[u] = true;

            for (int j = 0; j < n; j++) {
                if (edge_list.find({u, j}) != edge_list.end() && visited[j] == false) {
                    if (dist[j].second > -(abs(dist[u].second) * abs(succProb[edge_list[{u, j}]]))) {
                        dist[j].second = -(abs(dist[u].second) * abs(succProb[edge_list[{u, j}]]));
                    }
                }
            }
        }
        return -dist[end].second;
    }
};

int main() {
    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5, 0.5, 0.2};
    Solution s;
    cout << s.maxProbability(n,edges,succProb,start, end);
    return 0;
}