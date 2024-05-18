## 22. Generate Parentheses
<span style="color:orange">Medium</span>

Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses.*

**Example 1:**
```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```
**Example 2:**
```
Input: n = 1
Output: ["()"]
```
 
**Constraints:**

+ `1 <= n <= 8`

**My solution:**
+ back tracking
```cpp
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        string curr;
        dfs(n, n, curr);
        return res;
    }
    
    void dfs(int left, int right, string& curr) {
        if (left == 0 && right == 0) {
            res.push_back(curr);
            return;
        }
        
        if (left == right) {
            curr.push_back('(');
            dfs(left-1, right, curr);
            curr.pop_back();
        } else if (left == 0) {
            curr.push_back(')');
            dfs(left, right-1, curr);
            curr.pop_back();
        } else {
            curr.push_back('(');
            dfs(left-1, right, curr);
            curr.pop_back();
            curr.push_back(')');
            dfs(left, right-1, curr);
            curr.pop_back();
        }
    }
};
```