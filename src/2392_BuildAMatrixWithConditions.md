## 2392. Build a Matrix With Conditions
<span style="color:red">Hard</span>

You are given a **positive** integer `k`. You are also given:

- a 2D integer array `rowConditions` of size `n` where `rowConditions[i] = [above_i, below_i]`, and
- a 2D integer array `colConditions` of size `m` where `colConditions[i] = [left_i, right_i]`.

The two arrays contain integers from `1` to `k`.

You have to build a `k x k` matrix that contains each of the numbers from `1` to `k` **exactly once**. The remaining cells should have the value `0`.

The matrix should also satisfy the following conditions:

- The number `above_i` should appear in a **row** that is strictly **above** the row at which the number `below_i` appears for all `i` from `0` to `n - 1`.
- The number `left_i` should appear in a **column** that is strictly **left** of the column at which the number `right_i` appears for all `i` from `0` to `m - 1`.

Return *any matrix that satisfies the conditions*. If no answer exists, return an empty matrix.

**Example 1:**

![Example 1](https://assets.leetcode.com/uploads/2022/07/06/gridosdrawio.png)
```
Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.
```

**Example 2:**
```
Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.
```

**Constraints:**

+ `2 <= k <= 400`
+ `1 <= rowConditions.length, colConditions.length <= 10^4`
+ `rowConditions[i].length == colConditions[i].length == 2`
+ `1 <= abovei, belowi, lefti, righti <= k`
+ `abovei != belowi`
+ `lefti != righti`

**My solution:**
+ topological sort
```cpp
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> col_indegree(k+1, 0), row_indegree(k+1, 0);
        vector<vector<int>> col_graph(k+1), row_graph(k+1);
        
        add(rowConditions, row_indegree, row_graph);
        add(colConditions, col_indegree, col_graph);
        
        vector<int> order_row = topo_sort(row_indegree, row_graph);
        if (order_row.size() != k) return {};
        vector<int> order_col = topo_sort(col_indegree, col_graph);
        if (order_col.size() != k) return {};
        
        vector<vector<int>> res(k, vector<int>(k, 0));
        
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                res[i][j] = order_row[i] == order_col[j] ? order_row[i] : 0;
            }
        }
        
        return res;
    }

    
    void add(vector<vector<int>>& con, vector<int>& indegree, vector<vector<int>>& graph) {
        for (const auto& v : con) {
            indegree[v[1]]++;
            graph[v[0]].push_back(v[1]);
        }
    }
    
    vector<int> topo_sort(vector<int>& indegree, vector<vector<int>>& graph) {
        vector<int> order;
        
        queue<int> q;
        for (int i = 1; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int curr = q.front();
                q.pop();
                order.push_back(curr);
                for (const auto& neighbor : graph[curr]) {
                    if (--indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
        }
        
        return order;
    }
};
```