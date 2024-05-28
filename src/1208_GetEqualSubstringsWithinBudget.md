## 1208. Get Equal Substrings Within Budget
<span style="color:orange">Medium</span>

You are given two strings `s` and `t` of the same length and an integer `maxCost`.

You want to change `s` to `t`. Changing the `ith` character of `s` to `ith` character of `t` costs `|s[i] - t[i]|` (i.e., the absolute difference between the ASCII values of the characters).

Return *the maximum length of a substring of `s` that can be changed to be the same as the corresponding substring of `t` with a cost less than or equal to `maxCost`*. If there is no substring from `s` that can be changed to its corresponding substring from `t`, return 0.

**Example 1:**
```
Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.
```
**Example 2:**
```
Input: s = "abcd", t = "cdef", maxCost = 3
Output: 1
Explanation: Each character in s costs 2 to change to character in t,  so the maximum length is 1.
```
**Example 3:**
```
Input: s = "abcd", t = "acde", maxCost = 0
Output: 1
Explanation: You cannot make any change, so the maximum length is 1.
```
 
**Constraints:**

+ `1 <= s.length <= 10^5`
+ `t.length == s.length`
+ `0 <= maxCost <= 10^6`
+ `s` and `t` consist of only lowercase English letters.

**My solution:**
+ Binary Search, Sliding Window, Prefix Sum
```cpp
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int left = 0, right = len;
        vector<int> presum = {0};
        for (int i = 0; i < len; i++) {
            presum.push_back(presum.back() + abs(s[i]-t[i]));
        }
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (isValid(presum, maxCost, mid)) {
                left = mid+1;
            } else {
                right = mid-1;
            }
        }
        return right;
    }

    bool isValid(vector<int>& presum, int token, int len) {
        for (int i = len; i < presum.size(); i++) {
            if (presum[i] - presum[i-len] <= token)
                return true;
        }
        return false;
    }
};
```