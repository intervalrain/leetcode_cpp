## 1002. Find Common Characters
<span style="color:green">Easy</span>

Given a string array `words`, return *an array of all characters that show up in all strings within the* `words` (*including duplicates*). You may return the answer in **any order**.

**Example 1:**
```
Input: words = ["bella","label","roller"]
Output: ["e","l","l"]
```
**Example 2:**
```
Input: words = ["cool","lock","cook"]
Output: ["c","o"]
```
 
**Constraints:**

+ `1 <= words.length <= 100`
+ `1 <= words[i].length <= 100`
+ `words[i]` consists of lowercase English letters.

**My solution:**
```cpp
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int dp[26];
        memset(dp, 100, sizeof(dp));
        for (const auto& word : words) {
            int cnt[26] = {0};
            for (const auto& c : word) {
                cnt[c-'a']++;
            }
            for (int i = 0; i < 26; i++) {
                dp[i] = min(dp[i], cnt[i]);
            }
        }
        vector<string> res;
        for (int i = 0; i < 26; i++) {
            while (dp[i]--) {
                char c = i+'a';
                string s(1, c);
                res.push_back(s); 
            }
        }
        return res;
    }
};
```