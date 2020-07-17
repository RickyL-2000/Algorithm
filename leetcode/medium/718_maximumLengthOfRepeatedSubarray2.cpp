#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    bool contain(vector<int>& A, vector<int>& B, int begin, int end) {
        if (end - begin > A.size()) return false;
        bool flag;
        for (int i = 0; i <= A.size() - (end - begin); i++) {
            flag = true;
            for (int j = 0; j < end - begin; j++) {
                if (A[i + j] != B[begin + j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) return true;
        }
        return false;
    }
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<int> &small = A, &large = B;
        if (A.size() > B.size()) vector<int> &small = B, &large = A;
        int ans = 0;
        int begin = 0, end;
        while (begin < small.size()) {
            end = begin + ans + 1;
            if (end > small.size()) break;
            while (end <= small.size()) {
                if (contain(large, small, begin, end)) {
                    ans = max(ans, end - begin);
                    end++;
                } else break;
            }
            begin++;
        }
        return ans;
    }
};

int main() {
    vector<int> A = {1,2,3,2,1}, B = {3,2,1,4,7};
    Solution s;
    cout << s.findLength(A, B) << endl;
    return 0;
}