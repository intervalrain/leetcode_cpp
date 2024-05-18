## 24. Swap Nodes in Pairs
<span style="color:orange">Medium</span>

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2020/10/03/swap_ex1.jpg)
```
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```
**Example 2:**
```
Input: head = []
Output: []
```
**Example 3:**
```
Input: head = [1]
Output: [1]
```

**My solution:**
+ recursion
```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* next = swapPairs(head->next->next);
        ListNode* last = head->next;
        last->next = head;
        head->next = next;
        return last;
    }
};
```