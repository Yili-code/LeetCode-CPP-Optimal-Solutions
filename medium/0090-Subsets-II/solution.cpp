class Solution {
public:
  vector<vector<int>> result;
  vector<int> path;

  void backtracking(vector<int> &nums, int startIndex) {
    result.push_back(path); 

    for (int i = startIndex; i < nums.size(); ++i) {
      // Pruning：同一層不能用相同元素（避免重複）
      if (i > startIndex && nums[i] == nums[i - 1])
        continue;

      path.push_back(nums[i]);
      backtracking(nums, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    result.clear();
    path.clear();
    sort(nums.begin(), nums.end()); // sorting is a prerequisite for pruning duplicate branches 
    backtracking(nums, 0);
    return result;
  }
};
