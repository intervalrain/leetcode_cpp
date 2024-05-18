## 16. 3Sum Closest
<span style="color:orange">Medium</span>

Given an integer array `nums` of length n and an integer `target`, find three integers in `nums` such that the sum is closest to `target`.

Return *the sum of the three integers.*

You may assume that each input would have exactly one solution.

 

**Example 1:**
```
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```
**Example 2:**
```
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
```
 

**Constraints:**

+ 3 <= nums.length <= 500
+ -1000 <= nums[i] <= 1000
+ -10^4 <= target <= 10^4

**My solution:**
```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minv = nums[0] + nums[1] + nums[2];
        int maxv = nums[n-1] + nums[n-2] + nums[n-3];
        if (target > maxv) return maxv;
        else if (target < minv) return minv;
        
        int res = minv;
        for (int i = 0; i < n; i++) {
            int left = i+1;
            int right = n-1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                } else {
                    return target;
                }
                
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }
            }
        }
        return res;
    }
};
```