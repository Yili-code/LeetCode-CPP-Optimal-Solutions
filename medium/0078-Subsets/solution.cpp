class Solution {
public:
  vector<vector<int>> result;
  vector<int> path;

  void backtracing(vector<int> &nums, int startIndex) {
    // termination condition 
    result.push_back(path);
    if (startIndex == nums.size()) return;
  
    // for loop
    for (int i = startIndex; i < nums.size(); ++i) {
      path.push_back(nums[i]);
      backtracing(nums, i + 1);
      path.pop_back();
    }
  }

  vector<vector<int>> subsets(vector<int> &nums) {
    result.clear();
    backtracing(nums, 0);
    return result;
  }
};