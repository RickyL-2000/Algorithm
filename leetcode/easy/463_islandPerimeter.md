# Island Perimeter

## my solution 1    20/1/14 10 min

初步思路：从左到右、从上到下依次扫过整个海域，遇到陆海交接处+1。这样cost可能会很大

time:   68 ms   91.79%

memory: 16.3 mb 72.85%

一次过！

```
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(),
            n = grid[0].size();
        int i, j;
        int sum = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n-1; j++) {
                if (grid[i][j] != grid[i][j+1]) {
                    sum++;
                }
            }
            if (grid[i][0] == 1) sum++;
            if (grid[i][n-1] == 1) sum++;
        }
        for (j = 0; j < n; j++) {
            for (i = 0; i < m-1; i++) {
                if (grid[i][j] != grid[i+1][j]) {
                    sum++;
                }
            }
            if (grid[0][j] == 1) sum++;
            if (grid[m-1][j] == 1) sum++;
        }
        return sum;
    }
};
```

不过这种方法太暴力了

## reference solution 2

解题思路：统计数组中1的个数count，返回2*count+2。若四个一组成方块--count。

```
int islandPerimeter(vector<vector<int>>& grid) {
    int count = 0;
    for(int i = 0;i<grid.size();++i)
    for( int j =0;j<grid[0].size();++j) 
        if(grid[i][j] == 1) ++count;
    for(int i = 0;i<grid.size()-1;++i)
    for( int j =0;j<grid[0].size()-1;++j)
    if(grid[i][j] == 1 && grid[i][j+1] == 1 &&grid[i+1][j] == 1 && grid[i+1][j+1] == 1)
    --count;
    return 2*count+2;
}
```