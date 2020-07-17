
#include <vector>
using namespace std;

class DisjSet {
private:
    vector<int> parent;
public:
    DisjSet(int maxsize) : parent(vector<int>(maxsize)) {
        for (int i = 0; i < maxsize; ++i) {
            parent[i] = i;
        }
    }
    int find(int x) {
        return x == parent[x] ? x : find(parent[x]);
    }
    void merge(int x1, int x2) {
        parent[find(x1)] = find(x2);
    }
    bool is_same(int x1, int x2) {
        return find(x1) == find(x2);
    }
};