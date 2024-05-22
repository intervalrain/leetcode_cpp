## 131. Palindrome Partitioning
<span style="color:orange">Medium</span>

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. *Return all possible palindrome partitioning of `s`.*

**Example 1:**
```
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
```
**Example 2:**
```
Input: s = "a"
Output: [["a"]]
```
 
**Constraints:**

+ `1 <= s.length <= 16`
+ `s` contains only lowercase English letters.

**My solution:**
```cpp
class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
        for (int len = 1; len <= n; len++) {
            for (int i = 0; len + i <= n; i++) {
                if (len == 1) {
                    dp[i][len] = true;
                } else if (len == 2) {
                    dp[i][len] = s[i] == s[i+1];
                } else {
                    dp[i][len] = dp[i+1][len-2] && s[i] == s[i+len-1];
                }
            }
        }
        vector<string> arr;
        dfs(s, dp, 0, arr);
        return res;
    }
    
    void dfs(string s, vector<vector<bool>>& dp, int i, vector<string>& arr) {
        if (i == dp.size()-1) {
            res.push_back(arr);
            return;
        }
        for (int len = 1; i+len < dp.size(); len++) {
            if (!dp[i][len]) continue;
            arr.push_back(s.substr(i, len));
            dfs(s, dp, i+len, arr);
            arr.pop_back();
        }
    }
};
```