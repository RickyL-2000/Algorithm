#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

const int MAXN = 1e4 + 50;
int n;
int nums[MAXN];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    if (n == 1) { printf("%d", nums[0]); return 0; }
    sort(nums, nums + n, [](int a, int b) {return a > b;});

    int cols = (int) sqrt((double)n);
    while (cols >= 1 && n % cols != 0) {
        cols--;
    } 
    int rows = n / cols;
    vector<vector<int> > mat(rows, vector<int>(cols));

    int index = 0; 
    int width = cols-1, height = rows-1, layer = 0;
    while (index < n && width > 0 && height > 0) {
        for (int i = 0; i < width; i++) {
            mat[layer][layer+i] = nums[index];
            index++;
        }
        for (int i = 0; i < height; i++) {
            mat[layer+i][cols-1-layer] = nums[index];
            index++;
        }
        for (int i = 0; i < width; i++) {
            mat[rows-1-layer][cols-1-layer-i] = nums[index];
            index++;
        }
        for (int i = 0; i < height; i++) {
            mat[rows-1-layer-i][layer] = nums[index];
            index++;
        }
        width -= 2;
        height -= 2;
        layer++;
    }
    if (index < n && width > 0) {
        for (int i = 0; i < width+1; i++) {
            mat[layer][layer+i] = nums[index];
            index++;
        }
    }
    if (index < n && height > 0) {
        for (int i = 0; i < height+1; i++) {
            mat[layer+i][layer] = nums[index];
            index++;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0;  j < cols; j++) {
            printf("%d", mat[i][j]);
            if (j != cols-1) printf(" ");
        }
        if (i != rows-1) printf("\n");
    }

    return 0;
}