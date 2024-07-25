## 912. Sort an Array
<span style="color:orange">Medium</span>

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem **without using any built-in** functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

 

**Example 1:**
```
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
```
**Example 2:**
```
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
```
 

**Constraints:**
+ `1 <= nums.length <= 5 * 10^4`
+ `-5 * 10^4 <= nums[i] <= 5 * 10^4`

**My solution:**
```cpp
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums, 0, nums.size()-1);
        return nums;
    }
    
    void sort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int mid = left + (right-left)/2;
        sort(nums, left, mid);
        sort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
    
    void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left;
        int j = mid+1;
        vector<int> arr;
        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) {
                arr.push_back(nums[i++]);
            } else {
                arr.push_back(nums[j++]);
            }
        }
        while (i <= mid) arr.push_back(nums[i++]);
        while (j <= right) arr.push_back(nums[j++]);
        
        for (int i = left; i <= right; i++) {
            nums[i] = arr[i-left];
        }
    }
};
```