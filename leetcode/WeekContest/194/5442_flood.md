# Avoid Flood in The City

Your country has an infinite number of lakes. Initially, all the lakes are empty, but when it rains over the nth lake, the nth lake becomes full of water. If it rains over a lake which is full of water, there will be a flood. Your goal is to avoid the flood in any lake.

Given an integer array rains where:

rains[i] > 0 means there will be rains over the rains[i] lake.
rains[i] == 0 means there are no rains this day and you can choose one lake this day and dry it.
Return an array ans where:

ans.length == rains.length
ans[i] == -1 if rains[i] > 0.
ans[i] is the lake you choose to dry in the ith day if rains[i] == 0.
If there are multiple valid answers return any of them. If it is impossible to avoid flood return an empty array.

Notice that if you chose to dry a full lake, it becomes empty, but if you chose to dry an empty lake, nothing changes. (see example 4)

## my sol 1     20/6/21

这道题当时看了一会写了一点点就跳过去了...当时想不到有什么非常好的办法...

## ref sol 1    Java

``` Java
import java.util.*;

class Solution {
    public int[] avoidFlood(int[] rains) {
        int n = rains.length;
        int[] ans = new int[n];
        //存储可以进行排水工作的日子
        TreeSet<Integer> work = new TreeSet<>();
        //存储"湖->该湖最后一次下雨的日子"的映射
        Map<Integer, Integer> water = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                //当天不下雨，可以进行排水工作，但具体要进行哪一个湖的排水只能等后面需要的时候才知道，所以先存起来
                work.add(i);
            } else {
                Integer last = water.get(rains[i]);
                if (last != null) { //这个湖之前下过雨
                    //用treeset的higher方法找到该湖最后一次下雨后最早可以进行排水工作的日子
                    //之所以要最早的，是因为越靠后的可用工作日越能进行潜在的别的湖的排水
                    Integer toWork = work.higher(last);
                    //如果这样的日子不存在，说明无法避免洪水
                    if (toWork == null) return new int[0];
                    //确定toWork那天进行rains[i]这个湖的排水工作，并将其移出可用工作日的集合
                    ans[toWork] = rains[i];
                    work.remove(toWork);
                }
                //将rains[i]这个湖最后一次下雨的日期更新为i
                water.put(rains[i], i);
                // i这天下了雨不能进行排水
                ans[i] = -1;
            }
        }
        // 某些工作日可能不需要进行排水(对应的ans[i]保留为初始的0)，但按照题意还是要填上某个正数
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) ans[i] = 1;
        }
        return ans;
    }
}
```

## my sol 2     20/6/21

1076 ms

103.1 mb


学习了ref1的方法后，用C++重写了。唉，感觉这个方法我当时也想了，可能太紧张了啥缘故导致没有想清楚。

> 5442_flood2.cpp

``` C++
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans(rains.size(), 0);
        priority_queue<int, vector<int>, greater<int>> work;
        map<int, int> water;
        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                work.push(i);
            } else {
                if (water.find(rains[i]) != water.end()) {
                    // this lake has been rain over before
                    vector<int> temp;   // 用于存放work.pop出来的东西
                    while (!work.empty() && work.top() < water[rains[i]]) {
                        // 需要找到该湖最后一次下雨之后最早可以进行排水的日子
                        temp.push_back(work.top());
                        work.pop();
                    }
                    if (work.empty()) return {};
                    int toWork = work.top();
                    ans[toWork] = rains[i];
                    work.pop();
                    for (int e : temp) work.push(e);    // 将缓存push回
                }
                water[rains[i]] = i;
                ans[i] = -1;
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 0) ans[i] = 1;
        }
        return ans;
    }
};

int main() {
    vector<int> rains = {1,0,2,0,2,1};
    Solution s;
    auto ans = s.avoidFlood(rains);
    return 0;
}
```

大概有一个特别需要注意的地方，就是ref1里面的higher()方法，貌似C++没有类似方法，就是在set或者pqueue中找到第一个大于某个数的数，即该湖下雨后第一次不下雨的日子。要实现这个，也就是代码中加了注释的位置。这里我错了两次。
