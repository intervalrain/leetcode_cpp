## 21. Merge Two Sorted Lists
<span style="color:green">Easy</span>

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

 

**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)
```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```
**Example 2:**
```
Input: list1 = [], list2 = []
Output: []
```
**Example 3:**
```
Input: list1 = [], list2 = [0]
Output: [0]
```
 
**Constraints:**

+ The number of nodes in both lists is in the range `[0, 50]`.
+ `-100 <= Node.val <= 100`
+ Both `list1` and `list2` are sorted in non-decreasing order.

**My solution:**
```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        
        if (list1) curr->next = list1;
        if (list2) curr->next = list2;
        
        return dummy->next;    
    }
};
```