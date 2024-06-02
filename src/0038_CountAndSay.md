## 38. Count and Say
<span style="color:orange">Medium</span>

The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:

+ `countAndSay(1) = "1"`
+ `countAndSay(n)` is the run-length encoding of `countAndSay(n - 1)`.
`Run-length encoding` (RLE) is a string compression method that works by replacing consecutive identical characters (repeated 2 or more times) with the concatenation of the character and the number marking the count of the characters (length of the run). For example, to compress the string `"3322251"` we replace `"33"` with `"23"`, replace `"222"` with `"32"`, replace `"5"` with `"15"` and replace `"1"` with `"11"`. Thus the compressed string becomes `"23321511"`.

Given a positive integer `n`, return *the `nth` element of the **count-and-say** sequence*.

 
**Example 1:**
```
Input: n = 4

Output: "1211"

Explanation:

countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"
```
**Example 2:**
```
Input: n = 1

Output: "1"

Explanation:

This is the base case.
```


**Constraints:**

+ `1 <= n <= 30`

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        while (--n) {
            res = rle(res);
        }
        return res;
    }
    
    string rle(string s) {
        int curr = -1;
        int cnt = 0;
        vector<pair<int,int>> v;
        for (const auto& c : s) {
            int num = c - '0';
            if (curr == num) {
                cnt++;
            } else {
                if (curr != -1) {
                    v.push_back({curr, cnt});
                }
                cnt = 1;
                curr = num;
            }
        }
        v.push_back({curr, cnt});
        
        string res;
        for (const auto&[num, times] : v) {
            res += to_string(times);
            res += to_string(num);
        }
        
        return res;
    }
};
```