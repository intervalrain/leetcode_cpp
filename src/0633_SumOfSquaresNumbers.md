## 633. Sum of Square Numbers
<span style="color:orange">Medium</span>

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.


**Example 1:**

```Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
```
**Example 2:**
```
Input: c = 3
Output: false
```
 

**Constraints:**

+ `0 <= c <= 2^31 - 1`

**My solution:**
+ hash table
```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<long long> set;
        for (long long i = 0; i*i <= c; i++) {
            set.insert(i*i);
            if (set.count(c - i*i))
                return true;
        }
        return false;
    }
};
```
+ two pointers
```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 1, j = sqrt(c);
        if (j*j == c) return true;
        while (i <= j) {
            long long sum = (i*i)+(j*j);
            if (sum == c) {
                return true;
            } else if (sum < c) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};
```