**50. Pow(x, n)**
<span style="color:orange">Medium</span>

Implement pow(x, n), which calculates `x` raised to the power `n` (i.e., `x^n`).

**Example 1:**
```
Input: x = 2.00000, n = 10
Output: 1024.00000
```

**Example 2:**
```
Input: x = 2.10000, n = 3
Output: 9.26100
```

**Example 3:**
```
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2^-2 = 1/2^2 = 1/4 = 0.25
```


**Constraints:**
+ `-100.0 < x < 100.0`
+ `-2^31 <= n <= 2^31-1`
+ `n` is an integer.
+ Either `x` is not zero or `n > 0`.
+ `-10^4 <= x^n <= 10^4`

**My solution:**
+ Time Cost: `04:49`
+ Time Complexity: `O(log n)`
+ Space Complexity: `O(1)`
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) 
            return myPow(1/x/x, -(n/2));
        if (x == 1) {
            return 1;
        } else if (n == 0) {
            return 1;
        } else if (n < 0) {
            return myPow(1/x, -n);
        }
        return (n & 1) ? x * myPow(x*x, n>>1) : myPow(x*x, n>>1);
    }
};
```