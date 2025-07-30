class Solution {
public:
  vector<vector<int>> result;
  vector<int> path;

  void backtracing(vector<int> &nums, vector<bool> &used) {
    // termination condition
    if (path.size() == nums.size()) {
      result.push_back(path);
      return;
    }

    // recursion
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i]) continue;

      path.push_back(nums[i]);
      used[i] = true;
      backtracing(nums, used);
      used[i] = false;
      path.pop_back();
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    result.clear();
    path.clear();
    vector<bool> used(nums.size(), false);
    backtracing(nums, used);
    return result;
  }
};