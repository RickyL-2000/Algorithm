#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN = 100010;
const int INF = 999999999;
int n;
int nums[MAXN];
int left_max[MAXN], right_min[MAXN];
vector<int> pivots;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int largest = nums[0], smallest = nums[n-1];
    left_max[0] = -1, right_min[n-1] = INF;
    left_max[1] = largest, right_min[n-2] = smallest;
    for (int i = 2; i < n; i++) {
        if (largest < nums[i-1]) largest = nums[i-1];
            left_max[i] = largest;
    }
    for (int i = n-3; i >= 0; i--) {
        if (smallest > nums[i+1]) smallest = nums[i+1];
            right_min[i] = smallest;
    }
    for (int i = 0; i < n; i++) {
        if (left_max[i] < nums[i] && right_min[i] > nums[i]) {
            pivots.push_back(nums[i]);
        }
    }
    sort(pivots.begin(), pivots.end());
    cout << pivots.size() << endl;
    for (int i = 0; i < pivots.size(); i++) {
        if (i != 0) printf(" ");
        printf("%d", pivots[i]);
    }
    printf("\n");
    return 0;
}