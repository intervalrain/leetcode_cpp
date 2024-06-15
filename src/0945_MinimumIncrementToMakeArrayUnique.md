## 945. Minimum Increment to Make Array Unique
<span style="color:orange">Medium</span>

You are given an integer array `nums`. In one move, you can pick an index `i` where `0 <= i < nums.length` and increment `nums[i]` by `1`.

Return *the minimum number of moves to make every value in `nums` **unique***.

The test cases are generated so that the answer fits in a 32-bit integer.

 
**Example 1:**
```
Input: nums = [1,2,2]
Output: 1
Explanation: After 1 move, the array could be [1, 2, 3].
```
**Example 2:**
```
Input: nums = [3,2,1,2,1,7]
Output: 6
Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
```
 

**Constraints:**

+ `1 <= nums.length <= 10^5`
+ `0 <= nums[i] <= 10^5`

**My solution:**
```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int curr = nums[0];
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= curr) {
                res += (curr+1-nums[i]);
            }
            curr = max(nums[i], curr+1);
        }
        return res;
    }
};
```