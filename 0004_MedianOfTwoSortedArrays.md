## 4. Median of Two Sorted Arrays
<span style="color:red">Hard</span>

Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return **the median** of the two sorted arrays.

The overall run time complexity should be `O(log (m+n))`.

**Example 1:**
```
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.
```
**Example 2:**
```
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
```
 

**Constraints:**

+ nums1.length == m
+ nums2.length == n
+ 0 <= m <= 1000
+ 0 <= n <= 1000
+ 1 <= m + n <= 2000
+ -10^6 <= nums1[i], nums2[i] <= 10^6

**My solution:**
+ binary search
```cpp
class Solution {
public:
    int m;
    int n;
    vector<int> nums1;
    vector<int> nums2;
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        this->nums1 = nums1;
        this->nums2 = nums2;
        
        if ((m + n) % 2 == 0) {
            return (kth(0, 0, (m+n)/2) + kth(0, 0, (m+n)/2+1))/2.0;
        } else {
            return kth(0, 0, (m+n)/2+1);
        }
    }
    double kth(int i, int j, int k) {
        if (i == m) return nums2[k+j-1];
        if (j == n) return nums1[k+i-1];
        if (k == 1) return min(nums1[i], nums2[j]);
        
        int d = min({k>>1, m-i, n-j});
        
        if (nums1[i+d-1] <= nums2[j+d-1]) {
            return kth(i+d, j, k-d);
        } else {
            return kth(i, j+d, k-d);
        }
    }
};
```