#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        set<vector<int>> MSTs;
        vector<vector<int>> ret = {{}, {}};
        for (int i = 0; i < n; i++) {
            vector<int> MST = prim(n, i, edges);
            sort(MST.begin(), MST.end());
            MSTs.insert(MST);
        }
        set<int> critical;
        auto m_iter = MSTs.begin();
        for (int e : *m_iter) {
            critical.insert(e);
        }
        m_iter++;
        while (m_iter != MSTs.end()) {
            vector<int> temp = {};
            for (int e : *m_iter) {
                if (critical.find(e) != critical.end()) {
                    temp.push_back(e);
                }
            }
            if (temp.size() > 0) {
                critical.clear();
                for (int e : temp) critical.insert(e);
            } else {
                for (int i = 0; i < edges.size(); i++) {
                    ret[1].push_back(i);
                }
                return ret;
            }
            m_iter++; 
        }
        auto c_iter = critical.begin();
        while (c_iter != critical.end()) {
            ret[0].push_back(*c_iter);
            c_iter++;
        }
        for (int i = 0; i < edges.size(); i++) {
            if (critical.find(i) == critical.end()) {
                ret[1].push_back(i);
            }
        }
        return ret;
    }
    vector<int> prim(int n, int src, vector<vector<int>>& edges) {
        map<int, int> candidates;
        vector<int> selected = {src};
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (i != src) candidates[i]++;
        }
        while (candidates.size() > 0) {
            int mincost = INT_MAX, minedge = -1;
            for (int v : selected) {
                for (int i = 0; i < edges.size(); i++) {
                    if ((edges[i][0] == v && candidates.find(edges[i][1]) != candidates.end()) ||
                        (edges[i][1] == v && candidates.find(edges[i][0]) != candidates.end())) {
                        if (edges[i][2] < mincost) {
                            minedge = i;
                            mincost = edges[i][2];
                        }
                    }
                }
            }
            ret.push_back(minedge);
            if (candidates.find(edges[minedge][0]) != candidates.end()) {
                selected.push_back(edges[minedge][0]);
                if (candidates[edges[minedge][0]] > 1) candidates[edges[minedge][0]]--;
                else candidates.erase(edges[minedge][0]);
            }
        }
        return ret;
    }
};