## 23. Merge k Sorted Lists
<span style="color:red">Hard</span>
You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

**Example 1:**
```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```
**Example 2:**
```
Input: lists = []
Output: []
```
**Example 3:**
```
Input: lists = [[]]
Output: []
```
 
**Constraints:**

+ `k == lists.length`
+ `0 <= k <= 10^4`
+ `0 <= lists[i].length <= 500`
+ `-10^4 <= lists[i][j] <= 10^4`
+ `lists[i]` is sorted in **ascending order**.
+ The sum of `lists[i].length` will not exceed `10^4`.

**My solution:**
```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for (const auto& list : lists) {
            if (list) pq.push(list);
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while (!pq.empty()) {
            auto top = pq.top();
            curr->next = top;
            curr = curr->next;
            pq.pop();
            top = top->next;
            if (top) pq.push(top);
        }
        return dummy->next;
    }
};
```