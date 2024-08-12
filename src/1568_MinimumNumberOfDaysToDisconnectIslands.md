**1568. Minimum Number of Days to Disconnect Island**
<span style="color:red">Hard</span>

You are given an `m x n` binary grid `grid` where `1` represents land and `0` represents water. An **island** is a maximal **4-directionally** (horizontal or vertical) connected group of `1`'s.

The grid is said to be **connected** if we have **exactly one island**, otherwise is said **disconnected**.

In one day, we are allowed to change **any** single land cell `(1)` into a water cell `(0)`.

Return *the minimum number of days to disconnect the grid*.

**Example 1:**
```
Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
Output: 2
Explanation: We need at least 2 days to get a disconnected grid.
Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.
```

**Example 2:**
```Input: grid = [[1,1]]
Output: 2
Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
```


**Constraints:**
+ `m == grid.length`
+ `n == grid[i].length`
+ `1 <= m, n <= 30`
+ `grid[i][j]` is either `0` or `1`.

**My solution:**
```cpp
class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        int cnt = countIslands(grid);
        if (cnt >= 2 || cnt == 0) return 0;
        
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    cnt = countIslands(grid);
                    if (cnt >= 2 || cnt == 0) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
    
    int countIslands(vector<vector<int>>& grid) {
        int cnt = 0;
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    
    
    vector<vector<bool>> visited;
    const vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    
    void dfs(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) return;
        visited[i][j] = true;
        for (const auto& d : dir) {
            dfs(grid, i+d[0], j+d[1]);
        }
    }
};
```