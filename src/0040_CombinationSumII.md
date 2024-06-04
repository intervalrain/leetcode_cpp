## 40. Combination Sum II
<span style="color:orange">Medium</span>

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note**: The solution set must not contain duplicate combinations.

**Example 1:**
```
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```
**Example 2:**
```
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
```

Constraints:

+ `1 <= candidates.length <= 100`
+ `1 <= candidates[i] <= 50`
+ `1 <= target <= 30`

**My solution:**
```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& can, int target) {
        sort(can.begin(), can.end());
        vector<int> u;
        dfs(can, 0, target, u);
        return res;
    }
    
    void dfs(vector<int>& can, int i, int t, vector<int>& u) {
        if (t == 0) {
            res.push_back(u);
            return;
        }
        int n = can.size();
        for (int j = i; j < n; j++) {
            if (can[j] > t) continue;
            if (j > i && can[j] == can[j-1]) continue;
            u.push_back(can[j]);
            dfs(can, j+1, t-can[j], u);
            u.pop_back();
        }
    }
};
```