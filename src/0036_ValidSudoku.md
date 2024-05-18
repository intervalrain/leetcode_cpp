## 36. Valid Sudoku
<span style="color:orange">Medium</span>

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits 1-9 without repetition.
2. Each column must contain the digits 1-9 without repetition.
3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
**Note:**

+ A Sudoku board (partially filled) could be valid but is not necessarily solvable.
+ Only the filled cells need to be validated according to the mentioned rules.
 

**Example 1:**
![ex1](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)
```
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```
**Example 2:**
```
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```
 
**Constraints:**

+ `board.length == 9`
+ `board[i].length == 9`
+ `board[i][j]` is a digit `1-9` or `'.'`.

**My solution:**
```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> cells(9, vector<bool>(9, false));
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                char c = board[i][j];
                if (c == '.') continue;
                int v = c - '1';
                int cell = (i/3)*3+(j/3);
                if (rows[i][v] || cols[j][v] || cells[cell][v])
                    return false;
                rows[i][v] = true;
                cols[j][v] = true;
                cells[cell][v] = true;
            }
            cout << endl;
        }
        
        
        return true;
    }
};
```