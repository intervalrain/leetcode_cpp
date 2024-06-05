## 42. Trapping Rain Water
<span style="color:red">Hard</span>

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.



**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
```
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
```
**Example 2:**
```
Input: height = [4,2,0,3,2,5]
Output: 9
```
 
**Constraints:**

+ `n == height.length`
+ `1 <= n <= 2 * 10^4`
+ `0 <= height[i] <= 10^5`

**My solution:**
```cpp
class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        left[0] = h[0];
        right[n-1] = h[n-1];
        for (int i = 1; i < n; i++) {
            left[i] = max(left[i-1], h[i]);
            right[n-1-i] = max(right[n-i], h[n-1-i]);
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            res += (min(left[i], right[i]) - h[i]);
        }
        return res;
    }
};
```