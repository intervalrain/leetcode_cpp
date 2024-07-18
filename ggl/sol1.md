/*
Given an undirected graph with weighted edges, please implement a query
function that satisfies the following spec:

*   *Input*: A node in the graph.
*   *Output*: The maximum edge weight value of the sub-graph *without both the
    input node and all the edges connected to the input node*.  In other words,
    the sub-graph is deduced by the following rules:
    *   The sub-graph contains all nodes in the original graph but the
        query input node.
    *   The sub-graph contains an edge in the original graph if and only if
        that edge *is not* connect to the query input node.

Given a graph:
  Nodes = {A, B, C, D}
  Edges = {
      (AB, w=60),
      (AC, w=80),
      (AD, w=90),
      (BC, w=30),
      (BD, w=50),
  }

        C
       / \
     80   30
    /       \
  A ---60--- B
    \       /
     90   50
       \ /
        D


Then,
  Query(A) should return 50  # BD, sub-graph:   D ---50--- B ---30--- C
  Query(B) should return 90  # AD, sub-graph:   D ---90--- A ---80--- C
  Query(C)               90
  Query(D)               80

The graph might contain multiple disconnected components.
We can assume that all weight values are positive integers.

N := number of nodes
M := number of edges
K := number of queries
Total time complexity for K queries?  O(M) for one single query, O(K*M) for K queries.

*/
/*
hello

int res = 0;
max(res, weight);

        C
       / \
     80   30
    /       \
  A ---60--- B
    \       /
     90   50
       \ /
        D
        
        
        E--100--F--40--G
        
        //      A   B    C  D   E  F  G
// vector<int>[100,100,100,100,90,90,100]
// O(m* (n))

// 


        C
       / \
    100   30
    /       \
  A ---60--- B
    \       /
    100   50
       \ /
        D
//100, A,D   
//100  A,C   
// 60  A,B   
// 50  B,D   
// 30  B,C

O(M) * 2


A---100---B---30---C---50---D
*/  


// [[0,1,100],
// [1,2,30],
// [2,3,50]]

// MaxWeightExcludeAt* sol = new MaxWeightExcludeAt();
// cout << sol->query(0) << endl;;

class MaxWeightExcludeAt {
  int query(int q);
  
  MaxWeightExcludeAt(vector<vector<int>>& graph);
};

class MaxWeightExcludeAt {
  int nodeA;
  int nodeB
  int nodeA_res;
  int nodeB_res;
  int other_res;
  
  int query(int q) {
     if (q == nodeA) return nodeA_res;
     else if (q == nodeB) return nodeB_res;
     return other_res;
  }
  
  // [nodea, nodeb, weight]
  MaxWeightExcludeAt(vector<vector<int>>& graph) {
    // [[0,1,100],  curr = 100,  nodeA = 0, nodeB = 1
    // [1,2,30],    other_res = 100
    //              nodeA_res = 50
    // [2,3,50]]    nodeB_res = 50
    //   

      nodeA_res = 0;
      nodeB_res = 0;
      other_res = 0;
      nodeA = -1;
      nodeB = -1;
      
      int curr = 0; 
      for (const auto& e : graph) {
          if (e[2] > curr) {
              curr = e[2];
              nodeA = e[0];
              nodeB = e[1];
          }
      }
      other_res = curr;
    
      
      for (const auto& e : graph) {
          if (nodeA != e[0] && nodeA != e[1]) {
               nodeA_res = max(nodeA_res, e[2]);
          }
          if (nodeB != e[0] && nodeB != e[1]) {
               nodeB_res = max(nodeB_res, e[2]);
          }
      }
  }
};
