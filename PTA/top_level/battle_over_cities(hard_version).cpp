#include <iostream>
#include <vector>
using namespace std;

class DisjSet {
private:
    /**
     * @attention the index of city i here is i-1
     */
    vector<vector<int>> highways;
    vector<int> parents;
    vector<int> costs;
public:

    size_t num_of_cities() { return parents.size(); }

    void read() {
        size_t N, M;
        cin >> N >> M;

        parents = vector<int>(N, -1); // notice: i is the city i+1

        int c1, c2, cost, status;
        for (size_t i = 0; i < M; i++) {
           cin >> c1 >> c2 >> cost >> status;
           highways.push_back({c1-1, c2-1, cost, status}); 
        }
    }
    
    int find(int x) {   // find the parent of city x 
        return parents[x] < 0 ? x : parents[x] = find(parents[x]);
    }

    bool merge(int x1, int x2) {
        if ((x1 = find(x1)) == (x2 = find(x2))) return false;
        if (parents[x1] < parents[x2]) {
            parents[x1] += parents[x2];
            parents[x2] = x1;
        } else {
            parents[x2] += parents[x1];
            parents[x1] = x2;
        }
        return true;
    }

    /* destroy city x */
    vector<vector<int>> destroy(int x) {
        if (x == -1) return highways;
        vector<vector<int>> result;
        for (auto highway : highways) {
            if (highway[0] != x && highway[1] != x) {
                result.push_back(highway);
            }
        }
        return result;
    }

    int buildDisjSet(const vector<vector<int>> trial) {
        int cnt = parents.size();
        for (auto highway : trial) {
            if (merge(highway[0], highway[1])) cnt--;
        }
        return cnt;     // return the number of parts left
    }

    /**
     * @brief build the xth highway
     * @return true if success, false if the highway was intact
     */
    bool buildHighway(vector<vector<int>>& trial, int x) {
        if (trial[x][3]) return false;
        trial[x][3] = 1;
        return true;
    }

    bool destroyHighway(vector<vector<int>>& trial, int x) {
        if (!trial[x][3]) return false;
        trial[x][3] = 0;
        return true;
    }
};

int main() {
    DisjSet dS;
    dS.read();
    int parts;
    for (size_t city; city < dS.num_of_cities; city++) {
        vector<vector<int>> trial;
        if ((parts = dS.buildDisjSet(trial = dS.destroy(city))) == 1) {
            cout << 0 << endl;
            return 0;
        }

        // @bug THIS IS SO COMPLICATED!!!!!!

    }
}