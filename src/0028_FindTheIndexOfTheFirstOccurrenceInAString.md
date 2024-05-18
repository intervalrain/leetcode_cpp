## 28. Find the Index of the First Occurrence in a String
<span style="color:green">Easy</span>

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

**Example 1:**
```
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```
**Example 2:**
```
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
```
 
**Constraints:**

+ `1 <= haystack.length, needle.length <= 10^4`
+ `haystack` and `needle` consist of only lowercase English characters.

**My solution:**
+ kmp
```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> kmp = build(needle);
        int m = haystack.size();
        int n = needle.size();
        
        int i = 0;
        int j = 0;
        while (i < m) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == n) {
                return i-j;
            }
            if (i < m && haystack[i] != needle[j]) {
                if (j > 0) {
                    j = kmp[j-1];
                } else {
                    i++;
                }
            }
        }
        return -1;
    }
    
    vector<int> build(string& p) {
        int n = p.size();
        int i = 1;
        int len = 0;
        vector<int> dp(n, 0);
        while (i < n) {
            if (p[i] == p[len]) {
                dp[i++] = ++len;
            } else if (len) {
                len = dp[len-1];
            } else {
                i++;
            }
        }
        return dp;
    }
};
```

+ build kmp
```cpp
ABABC
ji      i != j && j == 0(i++)
00000

ABABC
j i     i == j (kmp[i++] = ++len)
00100

ABABC
00100 
 j i    i == j (kmp[i++] = ++len)

ABABC
00120
  j i   i != j && j > 0(j = kmp[j-1])

ABABC
00120
j   i   i != j && j == 0(i++)
```

+ compare kmp 
```cpp
ABAABABABCA
ABABC
   ^
00120

ABAABABABCA
   ^
__ABABC
  00120

ABAABABABCA
       ^
   ABABC
   00120

ABAABABABCA
       ^
   __ABABC     
```