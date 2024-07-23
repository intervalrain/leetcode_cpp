# 1636. Sort Array by Increasing Frequency
<span style="color:green">Easy</span>

Given an array of integers `nums`, sort the array in **increasing** order based on the frequency of the values. If multiple values have the same frequency, sort them in **decreasing** order.

Return the *sorted array*.

**Example 1:**
```
Input: nums = [1,1,2,2,2,3]
Output: [3,1,1,2,2,2]
Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
```

**Example 2:**
```
Input: nums = [2,3,1,3,2]
Output: [1,3,3,2,2]
Explanation: '2' and '3' both have a frequency of 2, so they are sorted in decreasing order.
```

**Example 3:**
```
Input: nums = [-1,1,-6,4,5,-6,1,4,1]
Output: [5,-1,4,4,-6,-6,1,1,1]
```

**Constraints:**
+ `1 <= nums.length <= 100`
+ `-100 <= nums[i] <= 100`

**My solution:**
```cpp
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> umap;
        for (const auto& num : nums) 
            umap[num]++;
        vector<pair<int,int>> v;
        for (const auto& [key, cnt] : umap) {
            v.push_back({cnt, -key});
        }
        sort(v.begin(), v.end());
        vector<int> res;
        for (const auto& u : v) {
            for (int i = 0; i < u.first; i++) {
                res.push_back(-u.second);
            }
        }
        return res;
    }
};
```