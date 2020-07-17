#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        int n = candies.size();
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(candies[i]);
        }
        int cnt = s.size();
        if (cnt >= n/2) return n/2;
        return cnt;
    }
};