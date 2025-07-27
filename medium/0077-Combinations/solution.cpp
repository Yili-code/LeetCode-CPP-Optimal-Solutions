class Solution {
public:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(int n, int k, int startIdex) {
    if (path.size() == k) { 
      result.push_back(path);
      return;
    }

    for (int i = startIdex; i <= n; ++i) {
      path.push_back(i);
      backtracking(n, k, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return result;
  }
};
