**47. Permutations II**
<span style="color:orange">Medium</span>

Given a collection of numbers, `nums`, that might contain duplicates, return *all possible unique permutations **in any order**.*
 
**Example 1:**
```
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
```

**Example 2:**
```
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```
 
**Constraints:**
+ `1 <= nums.length <= 8`
+ `-10 <= nums[i] <= 10`

**My solution:**
+ Time Cost: `03:25`
+ Algorithm: `backtracking`
+ Time Complexity: `O(n)`
+ Space Complexity: `O(n)`
```cpp
class Solution {
public:
    set<vector<int>> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> arr;
        backtrack(nums, arr);
        return vector<vector<int>>(used.begin(), used.end());
    }
    void backtrack(vector<int>& nums, vector<int>& arr) {
        if (arr.size() == nums.size()) {
            used.insert(arr);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == INT_MIN) continue;
            int num = nums[i];
            nums[i] = INT_MIN;
            arr.push_back(num);
            backtrack(nums, arr);
            nums[i] = num;
            arr.pop_back();
        }
    }
};
```