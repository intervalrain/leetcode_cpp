## 43. Multiply Strings
<span style="color:orange">Medium</span>

Given two non-negative integers `num1` and `num2` represented as strings, return the product of `num1` and `num2`, also represented as a string.

**Note**: You must not use any built-in BigInteger library or convert the inputs to integer directly.

**Example 1:**
```
Input: num1 = "2", num2 = "3"
Output: "6"```
**Example 2:**
```
Input: num1 = "123", num2 = "456"
Output: "56088"```

**Constraints:**

+ `1 <= num1.length`, `num2.length <= 200`
+ `num1` and `num2` consist of digits only.
+ Both `num1` and `num2` do not contain any leading zero, except the number `0` itself.

**My solution:**
```cpp
class Solution {
public:
    vector<int> arr;
    
    void print(vector<int>& arr) {
        for (auto it = arr.rbegin(); it != arr.rend(); it++) {
            cout << *it;
        }
        cout << endl;
    }
    
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        arr.assign(m+n, 0);
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                int num = (num1[i]-'0') * (num2[j]-'0');
                int shift = (m-i-1)+(n-j-1);
                add(num, shift);
            }
        }
        while (arr.size() > 1 && arr.back() == 0) arr.pop_back();
        string res;
        for (int i = arr.size()-1; i >= 0; i--) {
            res.push_back(arr[i] + '0');
        }
        return res;
    }
    
    void add(int num, int shift) {
        int i = shift;
        while (num) {
            int curr = arr[i] + num % 10;
            int cin = curr / 10;
            arr[i] = curr % 10;
            num = (num/10 + cin);
            i++;
        }
    }
};
```