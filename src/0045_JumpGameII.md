**45. Jump Game II**
<span style="color:orange">Medium</span>

You are given a **0-indexed** array of integers `nums` of length `n`. You are initially positioned at `nums[0]`.
Each element `nums[i]` represents the maximum length of a forward jump from index `i`. In other words, if you are at `nums[i]`, you can jump to any `nums[i + j]` where:
+ `0 <= j <= nums[i]` and
+ `i + j < n`
Return *the minimum number of jumps to reach* `nums[n - 1]`. The test cases are generated such that you can reach `nums[n - 1]`.
 
**Example 1:**
```
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
```
**Example 2:**
```
Input: nums = [2,3,0,1,4]
Output: 2
```
 
**Constraints:**
+ `1 <= nums.length <= 104`
+ `0 <= nums[i] <= 1000`
+ It's guaranteed that you can reach `nums[n - 1]`.

**My solution:**
+ Time Cost: `06:19`
+ Algorithm: `bfs`
+ Time Complexity: `O(n)`
+ Space Complexity: `O(1)`
```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        if (n == 1) return 0;
        int stop = 0;
        int res = 0;
        while (i < n) {
            int curr = i;
            while (i <= stop && i < n) {
                if (i == n-1) return res;
                curr = max(curr, nums[i] + i);
                if (curr >= n-1) return res+1;
                i++;
            }
            stop = curr;
            res++;
        }
        return -1;
    }
};
```