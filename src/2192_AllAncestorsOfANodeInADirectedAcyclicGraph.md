## 2192. All Ancestors of a Node in a Directed Acyclic Graph
<span style="color:orange">Medium</span>

You are given a positive integer `n` representing the number of nodes of a **Directed Acyclic Graph** (DAG). The nodes are numbered from `0` to `n - 1` (**inclusive**).

You are also given a 2D integer array `edges`, where `edges[i] = [fromi, toi]` denotes that there is a **unidirectional** edge from `fromi` to `toi` in the graph.

Return *a list `answer`, where `answer[i]` is the **list of ancestors** of the `ith` node, sorted in **ascending order**.*

A node `u` is an **ancestor** of another node `v` if `u` can reach `v` via a set of edges.


**Example 1:**
![ex1](https://assets.leetcode.com/uploads/2019/12/12/e1.png)
```
Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
```
**Example 2:**
![ex2](https://assets.leetcode.com/uploads/2019/12/12/e2.png)
```
Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
```

**Constraints:**

+ `1 <= n <= 1000`
+ `0 <= edges.length <= min(2000, n * (n - 1) / 2)`
+ `edges[i].length == 2`
+ `0 <= fromi, toi <= n - 1`
+ `fromi != toi`
+ There are no duplicate edges.
+ The graph is **directed** and **acyclic**.

**My solution:**
+ topological sort
```cpp
class Solution {
public:    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>> sets(n);
        
        vector<vector<int>> graph(n);
        vector<int> indegree(n);
        queue<int> q;
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int from = q.front(); q.pop();
                for (const auto& to : graph[from]) {
                    sets[to].insert(from);
                    for (const auto& other : sets[from]) {
                        sets[to].insert(other);
                    }
                    if (--indegree[to] == 0) {
                        q.push(to);
                    }
                }
            }
        }
        
        vector<vector<int>> res;
        for (const auto& s : sets) {
            res.push_back(vector<int>(s.begin(), s.end()));
        }
        return res;
    }
};
```
+ dfs
```cpp
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n), res(n);
        for (const auto& e : edges) {
            graph[e[0]].push_back(e[1]);
        }
        for (int i = 0; i < n; i++) {
            dfs(graph, res, i, i);
        }
        return res;
    }
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, int& parent, int& curr) {
        for (auto& child : graph[curr]) {
            if (res[child].size() == 0 || res[child].back() != parent) {
                res[child].push_back(parent);
                dfs(graph, res, parent, child);
            }
        }
    }
};
```