# 32. Longest Valid Parentheses
<span style="color:red">Hard</span>

Given a string containing just the characters `'('` and `')'`, return *the length of the longest valid (well-formed) parentheses substring*.

 
**Example 1:**
```
Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
```
**Example 2:**
```
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
```
**Example 3:**
```
Input: s = ""
Output: 0
```
 

**Constraints:**

+ `0 <= s.length <= 3 * 10^4`
+ `s[i]` is `'('`, or `')'`.
**My solution:**
+ stack
```cpp
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int res = 0;
        stack<int> st;
        st.push(0);
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() < 0 && s[i] == ')') {
                st.pop();
                res = max(res, i - abs(st.top())+1);
            } else {
                st.push(s[i] == ')' ? (i+1): -(i+1));
            }
        }
        return res;
    }
};
```