##
**My solution:**
+ two pointers
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != i+1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) 
                return i+1;
        }
        return nums.size()+1;
    }
};
```
+ bit masking
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int> masks(n/32+1, 0);
        masks[0] |= 1;
        
        for (const auto& num : nums) {
            if (num < 0 || num > n) 
                continue;
            int bundle = (num) / 32;
            int index = (num) % 32;
            int bit = 1 << index;
            masks[bundle] |= bit;
        }
        
        for (int i = 0; i < masks.size(); i++) {
            if (masks[i] == -1) 
                continue;
            int bit = lsb(++masks[i]);
            int index = 0;
            while (bit > 1) {
                index++;
                bit >>= 1;
            }
            return 32*i+index;
        }
        return n+1;
    }
    int lsb(int mask) {
        return mask & (~mask+1);
    }
};

```