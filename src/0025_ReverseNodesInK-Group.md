## 25. Reverse Nodes in k-Group
<span style="color:red">Hard</span>

Given the `head` of a linked list, reverse the nodes of the list `k` at a time, and return *the modified list*.

`k` is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of `k` then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex1.jpg)
```
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
```
**Example 2:**
![ex2](https://assets.leetcode.com/uploads/2020/10/03/reverse_ex2.jpg)
```
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]
```
 
**Constraints:**

+ The number of nodes in the list is `n`.
+ `1 <= k <= n <= 5000`
+ `0 <= Node.val <= 1000`

**My solution:**
+ recursion
```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = 0;
        ListNode* curr = head;
        for (; curr; curr = curr->next)
            n++;
        return reverse(head, k, n);
    }
    
    ListNode* reverse(ListNode* head, int k, int n) {
        if (n < k) 
            return head;
        int cnt = k;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        while (curr && cnt--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head->next = reverse(curr, k, n-k);
        return prev;
    }
};
```