#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> coors;
        pair<int, int> coor(0, 0);
        coors.insert(coor);
        for (char ch : path) {
            switch (ch) {
                case 'N': 
                    coor.second++;
                    break;
                case 'S':
                    coor.second--;
                    break;
                case 'E':
                    coor.first++;
                    break;
                case 'W':
                    coor.first--;
            }
            if (coors.find(coor) != coors.end()) {
                return false;
            }
            coors.insert(coor);
        }
    }
};

int main () {
    string path = "NESWW";
    Solution s;
    cout << s.isPathCrossing(path);
    return 0;
}