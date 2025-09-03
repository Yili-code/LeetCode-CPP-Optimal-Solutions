#include <vector>
using namespace std;

class Solution {
public:
  int findJudge(int n, vector<vector<int>> &trust) {
    vector<int> outDegree(n + 1, 0);
    vector<int> inDegree(n + 1, 0);
    
    for (auto &pair : trust) {
      int a = pair[0], b = pair[1];
      ++outDegree[a];
      ++inDegree[b];
    }

    for (int i = 1; i <= n; ++i) {
      if (outDegree[i] == 0 && inDegree[i] == n - 1) return i;
    }

    return -1;
  }
};