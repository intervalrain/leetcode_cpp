## 5. Longest Palindromic Substring
<span style="color:orange">Medium</span>

Given a string `s`, return the *longest palindromic substring* in `s`.

**Example 1:**
```
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```
**Example 2:**
```
Input: s = "cbbd"
Output: "bb"
```

**Constraints:**

+ 1 <= s.length <= 1000
+ s consist of only digits and English letters.

**My solution:**
+ dynamic programming
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        bool dp[n+1][n+1];
        memset(dp, false, sizeof(dp));
        string res;
        
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i < n; i++) {
                if (len == 1) {
                    dp[i][len] = true;
                } else if (len == 2) {
                    dp[i][len] = s[i] == s[i+len-1];
                } else {
                    dp[i][len] = dp[i+1][len-2] && s[i] == s[i+len-1];
                }
                
                if (dp[i][len] && len > res.size()) {
                    res = s.substr(i, len);
                }
            }
        }
        return res;
    }
};
```

+ two pointers
```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            string s1 = helper(s, i, i);
            string s2 = helper(s, i, i+1);
            
            if (s1.size() > res.size()) res = s1;
            if (s2.size() > res.size()) res = s2;
        }
        return res;
    }
    
    string helper(string& s, int left, int right) {
        while (left >= 0 && right < s.size()) {
            if (s[left] != s[right]) {
                break;
            }
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
};
```