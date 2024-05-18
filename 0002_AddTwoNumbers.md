## 2. Add Two Numbers
<span style="color:orange">Medium</span>

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)
```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```
**Example 2:**
```
Input: l1 = [0], l2 = [0]
Output: [0]
```
**Example 3:**
```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
 ```

**Constraints:**

+ The number of nodes in each linked list is in the range [1, 100].
+ 0 <= Node.val <= 9
+ It is guaranteed that the list represents a number that does not have leading zeros.

**My solution:**
+ linked list
```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int carry = 0) {
        if (l1 && l2) {
            int val = l1->val + l2->val + carry;
            carry = val/10;
            val %= 10;
            return new ListNode(val, addTwoNumbers(l1->next, l2->next, carry));
        } else if (l1) {
            int val = l1->val + carry;
            carry = val/10;
            val %= 10;
            return carry == 0 
                ? new ListNode(val, l1->next)
                : new ListNode(val, addTwoNumbers(l1->next, new ListNode(0), carry));
        } else if (l2) {
            int val = l2->val + carry;
            carry = val/10;
            val %= 10;
            return carry == 0 
                ? new ListNode(val, l2->next)
                : new ListNode(val, addTwoNumbers(l2->next, new ListNode(0), carry));
        } else {
            return carry == 0
                ? nullptr
                : new ListNode(1);
        }
    }
};
```