## 19. Remove Nth Node From End of List
<span style="color:orange">Medium</span>

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)
```Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```
**Example 2:**
```
Input: head = [1], n = 1
Output: []
```
**Example 3:**
```
Input: head = [1,2], n = 1
Output: [1]
```
 
**Constraints:**

+ The number of nodes in the list is `sz`.
+ `1 <= sz <= 30`
+ `0 <= Node.val <= 100`
+ `1 <= n <= sz`
 
**My solution:**
```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* curr = dummy;
        unordered_map<int, ListNode*> map;
        int cnt = 0;
        for (; curr; curr = curr->next) {
            map[cnt++] = curr;
        }
        curr = map[cnt-n-1];
        curr->next = curr->next->next;
        return dummy->next;
    }
};
```