#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minInteger(string num, int k) {
        int len = num.length();
        string sorted = num;
        sort(sorted.begin(), sorted.end());
        if (sorted == num) return num;
        string ret = num;
        string pre = "";
        while (k > 0) {
            int minval = 10, minpos = -1;
            int start = 1;
            int xpos = 0;
            if (ret == pre) start++;
            for (int i = start; i < min(start + k, len); i++) {
                if (ret[i] > ret[i-1]) continue;
                if (ret[i] < minval) {  // 先交换近的？(否则<=)
                    minval = ret[i];
                    minpos = i;
                }
            }
            while (ret[xpos] <= minval) xpos++;
            pre = ret;
            char temp = ret[xpos];
            ret[xpos] = ret[minpos];
            ret[minpos] = temp;
            k -= minpos;
            if (ret == sorted) return ret;
        }
        return ret;
    }
};