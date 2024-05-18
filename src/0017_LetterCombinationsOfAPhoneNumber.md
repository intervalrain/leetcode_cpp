## 17. Letter Combinations of a Phone Number
<span style="color:orange">Medium</span>

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

![ex](https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png)

**Example 1:**
```
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```
**Example 2:**
```
Input: digits = ""
Output: []
```
**Example 3:**
```
Input: digits = "2"
Output: ["a","b","c"]
```
 
**Constraints:**

+ `0 <= digits.length <= 4`
+ `digits[i]` is a digit in the range `['2', '9']`.

**My solution:**
```cpp
class Solution {
public:
    vector<string> map = {
        "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
    };
    
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
        string curr;
        dfs(digits, curr);
        return res;
    }
    
    void dfs(string& digits, string& curr) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        int i = curr.size();
        for (const auto& c : map[digits[i]-'0']) {
            curr.push_back(c);
            dfs(digits, curr);
            curr.pop_back();
        }
    }
};
```