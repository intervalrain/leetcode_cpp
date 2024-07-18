#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;


class MaxWeightExcludeAt {
  public:
  int nodeA;
  int nodeB;
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

int main() {
    vector<vector<int>> edges = {
        {0, 1, 60},
        {0, 2, 80},
        {0, 3, 90},
        {1, 2, 30},
        {1, 3, 50}
    };

    MaxWeightExcludeAt sol(edges);
    cout << sol.query(0) << endl; // 應返回 50
    cout << sol.query(1) << endl; // 應返回 90
    cout << sol.query(2) << endl; // 應返回 90
    cout << sol.query(3) << endl; // 應返回 80

    return 0;
}

