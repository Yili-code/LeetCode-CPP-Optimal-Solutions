class Solution {
public:
  bool satisfiesConditions(vector<vector<int>> &grid) {
    if (grid.empty() || grid[0].empty()) return true;

    for (int i = 0; i < grid[0].size(); ++i) {
      if (i + 1 < grid[0].size() && grid[0][i] == grid[0][i+1]) return false;

      for (int j = 1; j < grid.size(); ++j) {
        if (grid[j][i] != grid[j-1][i]) return false;
      }
    }

    return true;
  }
};