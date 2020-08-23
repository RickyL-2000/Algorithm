/**
 * 初步想法：排序后，从两头向中间选第一堆，剩下的为第二堆，直到找到两堆数量差异最小为止，此为划分结束。
 **/

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int ret = 0;
        int len = stoneValue.size();
        if (len == 1) return ret;
        if (len == 2) return min(stoneValue[0], stoneValue[1]);
        sort(stoneValue.begin(), stoneValue.end());
        vector<int> arr = stoneValue;
        while (arr.size() > 2) {
            len = arr.size()
            int sum = 0;
            for (int i = 0; i < len; i++) sum += arr[i];
            int left = -1, right = len;
            int sum1 = 0, sum2 = sum;
            diff = 2000000;
            while (abs(sum1 - sum2) < diff) {
                
            }
        }
    }
};