## 7. Reverse Integer
<span style="color:orange">Medium</span>

Given a signed 32-bit integer `x`, return `x` *with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

 

**Example 1:**
```
Input: x = 123
Output: 321
```
**Example 2:**
```
Input: x = -123
Output: -321
```
**Example 3:**
```
Input: x = 120
Output: 21
```

**Constraints:**

+ -2^31 <= x <= 2^31 - 1

**My solution:**
```cpp
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        if (x < 0) 
            return -1*reverse(-x);
        int curr = 0;
        while (x > 0) {
            if (curr > INT_MAX/10 || (curr == INT_MAX/10 && x >= 8))
                return 0;
            curr = curr * 10 + (x % 10);
            x /= 10;
        }
        return curr;
    }
};
```