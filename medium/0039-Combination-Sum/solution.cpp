class Solution {
public:
  vector<vector<int>> result;
  vector<int> temp;

  void backtracing(vector<int> &candidates, int target, int index) {
    if (target < 0) return;
    // termination condition
    if (target == 0) {
      result.push_back(temp);
      return;
    }

    // recursion
    for (int i = index; i < candidates.size(); ++i) {
      temp.push_back(candidates[i]);
      backtracing(candidates, target - candidates[i], i);
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    if (candidates.size() == 0) return {};

    backtracing(candidates, target, 0);
    return result;
  }
};