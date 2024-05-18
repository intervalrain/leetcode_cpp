## 3. Longest Substring Without Repeating Characters
<span style="color:orange">Medium</span>

Given a string `s`, find the length of the **longest substring** without repeating characters.

**Example 1:**
```
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
```
**Example 2:**
```
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```
**Example 3:**
```
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Constraints:**

+ 0 <= s.length <= 5 * 104
+ s consists of English letters, digits, symbols and spaces.

**My solution:**
+ hash table
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int pos[128];
        memset(pos, -1, sizeof(pos));
        int left = -1;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            left = max(left, pos[s[i]]);
            pos[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
```

+ sliding window
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int res = 0;
        bool used[128];
        memset(used, false, sizeof(used));
        while (right < s.size()) {
            char c = s[right++];
            while (used[c]) {
                char d = s[left++];
                used[d] = false;
            }
            used[c] = true;
            res = max(res, right-left);
        }
        return res;
    }
};
```