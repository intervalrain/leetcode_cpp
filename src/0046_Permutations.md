**46. Permutations**
<span style="color:orange">Medium</span>

Given an array `nums` of distinct integers, return *all the possible permutations*. You can return the answer in **any order**.
 
**Example 1:**
```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**
```
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

**Example 3:**
```
Input: nums = [1]
Output: [[1]]
```
 
**Constraints:**
+ `1 <= nums.length <= 6`
+ `-10 <= nums[i] <= 10`
+ All the integers of `nums` are **unique**.

**My solution:**
+ Time Cost: `01:58`
+ Algorithm: `backtracking`
+ Time Complexity: `O(n)`
+ Space Complexity: `O(n)`
```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> arr;
        backtrack(nums, arr);
        return res;
    }
    void backtrack(vector<int>& nums, vector<int>& arr) {
        if (arr.size() == nums.size()) {
            res.push_back(arr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == INT_MIN) continue;
            
            int num = nums[i];
            nums[i] = INT_MIN;
            arr.push_back(num);
            backtrack(nums, arr);
            arr.pop_back();
            nums[i] = num;
        }
    }
};
```