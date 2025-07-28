class Solution {
public:
  vector<vector<int>> result;
  vector<int> path;

  void backtracing(vector<int> &candidates, int target, int startIndex) {
    

    // termination condition
    if (target == 0) {
      result.push_back(path);
      return;
    }

    // recursion
    for (int i = startIndex; i < candidates.size(); ++i) {
      // skip duplicates
      if (i > startIndex && candidates[i] == candidates[i - 1]) continue;
      
      if (target - candidates[i] < 0) return;
      
      path.push_back(candidates[i]);
      backtracing(candidates, target - candidates[i], i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    backtracing(candidates, target, 0);
    return result;
  }
};