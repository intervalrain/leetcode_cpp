## 34. Find First and Last Position of Element in Sorted Array
<span style="color:orange">Medium</span>

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return [`-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**
```
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```
**Example 2:**
```
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```
**Example 3:**
```
Input: nums = [], target = 0
Output: [-1,-1]
```
 

**Constraints:**

+ `0 <= nums.length <= 10^5`
+ `-10^9 <= nums[i] <= 10^9`
+ `nums` is a non-decreasing array.
+ `-10^9 <= target <= 10^9`

**My solution:**
```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {        
        auto itl = lower_bound(nums.begin(), nums.end(), target);
        if (itl == nums.end() || *itl != target) return {-1,-1};
        auto itr = upper_bound(itl, nums.end(), target);
        return { (int)distance(nums.begin(), itl), (int)distance(nums.begin(), itr)-1 };
    }
};
```