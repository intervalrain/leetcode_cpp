## 11. Container With Most Water
<span style="color:orange">Medium</span>

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `ith` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return *the maximum amount of water a container can store*.

**Notice** that you may not slant the container.

 

**Example 1:**
![ex1](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg)
```
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
```
**Example 2:**
```
Input: height = [1,1]
Output: 1
```

**Constraints:**

+ n == height.length
+ 2 <= n <= 10^5
+ 0 <= height[i] <= 10^4

**My solution:**
+ greedy
```cpp
class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        int left = 0;
        int right = n-1;
        int res = 0;
        while (left < right) {
            int area;
            if (h[left] < h[right]) {
                area = h[left] * (right-left);
                left++;
            } else {
                area = h[right] * (right-left);
                right--;
            }
            res = max(res, area);
        }
        return res;
    }
};

```