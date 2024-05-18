## 14. Longest Common Prefix
<span style="color:green">Easy</span>


Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**
```
Input: strs = ["flower","flow","flight"]
Output: "fl"
```
**Example 2:**
```
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
```
 
**Constraints:**

+ 1 <= strs.length <= 200
+ 0 <= strs[i].length <= 200
+ strs[i] consists of only lowercase English letters.

**My solution:**
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            res = common(res, strs[i]);
        }
        return res;
    }
    
    string common(string s, string t) {
        int i = 0;
        for (; i < min(s.size(), t.size()); i++) {
            if (s[i] != t[i]) {
                break;
            }
        }
        return s.substr(0, i);
    }
};
```