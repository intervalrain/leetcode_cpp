## 1248. Count Number of Nice Subarrays
<span style="color:orange">Medium</span>

Given an array of integers `nums` and an integer `k`. A continuous subarray is called **nice** if there are `k` odd numbers on it.

Return *the number of **nice** sub-arrays*.

**Example 1:**
```
Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
```
**Example 2:**
```
Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
```
**Example 3:**
```
Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
```
 

**Constraints:**

+ `1 <= nums.length <= 50000`
+ `1 <= nums[i] <= 10^5`
+ `1 <= k <= nums.length`

**My solution:**
```cpp
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        int curr = 0;
        int res = 0;
        for (const auto& num : nums) {
            if (num & 1) curr++;
            if (curr - k >= 0) {
                res += dp[curr-k];
            }
            dp[curr]++;
        }
        return res;
    }
};
```