## 979. Distribute Coins in Binary Tree
<span style="color:orange">Medium</span>

You are given the `root` of a binary tree with `n` nodes where each `node` in the tree has `node.val` coins. There are n coins in total throughout the whole tree.

In one move, we may choose two adjacent nodes and move one coin from one node to another. A move may be from parent to child, or from child to parent.

Return *the **minimum** number of moves required to make every node have **exactly** one coin.*

 

**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2019/01/18/tree1.png)
```
Input: root = [3,0,0]
Output: 2
Explanation: From the root of the tree, we move one coin to its left child, and one coin to its right child.
```
**Example 2:**
![ex2](https://assets.leetcode.com/uploads/2019/01/18/tree2.png)
```
Input: root = [0,3,0]
Output: 3
Explanation: From the left child of the root, we move two coins to the root [taking two moves]. Then, we move one coin from the root of the tree to the right child.
```

**Constraints:**

+ The number of nodes in the tree is `n`.
+ `1 <= n <= 100`
+ `0 <= Node.val <= n`
+ The sum of all `Node.val` is `n`.

**My solution:**
```cpp
public:
    int res = 0;
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        res += (abs(left) + abs(right));
        return left + right - 1 + root->val;
    }
};

```