**49. Group Anagrams**
<span style="color:orange">Medium</span>

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**
```
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**
```
Input: strs = [""]
Output: [[""]]
```

**Example 3:**
```
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**
+ `1 <= strs.length <= 104`
+ `0 <= strs[i].length <= 100`
+ `strs[i]` consists of lowercase English letters.

**My solution:**
+ Time Cost: `03:20`
+ Algorithm: `hash table`
+ Time Complexity: `O(n^2)`
+ Space Complexity: `O(1)`
```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;
        for (const auto& s : strs) {
            string tmp(26, '0');
            for (const char& c : s) {
                tmp[c-'a']++;
            }
            map[tmp].push_back(s);
        }
        vector<vector<string>> res;
        for (const auto [key, val] : map) {
            res.push_back(val);
        }
        return res;
    }
};
```