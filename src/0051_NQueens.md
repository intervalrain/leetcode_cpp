## 51. N-Queens
<span styel="color:red">Hard</span>

The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return *all distinct solutions to the **n-queens puzzle***. You may return the answer in **any order**.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

 

**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)
```
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
```
**Example 2:**
```
Input: n = 1
Output: [["Q"]]
```
 

**Constraints:**
+ 1 <= n <= 9

**My solution:**
+ Time Cost: `08:04`
+ Algorithm: `backtracking`
+ Time Complexity: `O(n^3)`
+ Space Complexity: `O(n)`
```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        int row = 0, col = 0;
        vector<vector<string>> res;
        vector<string> arr(n, string(n, '.'));
        dfs(n, 0, res, arr);
        return res;
    }
    void dfs(int n, int row, vector<vector<string>>& res, vector<string>& arr) {
        if (row == n) {
            res.push_back(arr);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(n, row, col, arr)) {
                arr[row][col] = 'Q';
                dfs(n, row+1, res, arr);
                arr[row][col] = '.';
            }
        }
    }
    bool isValid(int n, int row, int col, vector<string>& arr) {
        int left = col;
        int right = col;
        while (row >= 0) {
            if (left >= 0 && arr[row][left--] == 'Q') return false;
            if (right < n && arr[row][right++] == 'Q') return false;
            if (arr[row--][col] == 'Q') return false;
        }
        return true;
    }
};
```