class Solution {
public:
  vector<vector<int>> result;
  vector<int> path;

  void backtracing(vector<int> &nums, int startIndex) {
    // termination condition  
    if (path.size() >= 2) {
      result.push_back(path);
    }

    unordered_set<int> used; // remove duplicate in same loop
    for (int i = startIndex; i < nums.size(); ++i) {
      // ensure path is increasing subsequence, and avoid out-of-bounds crash
      if (!path.empty() && path.back() > nums[i]) continue;

      // remove duplicate in same recursion level
      if (used.count(nums[i])) continue;

      used.insert(nums[i]);
      path.push_back(nums[i]);
      backtracing(nums, i + 1);
      path.pop_back();
      
    }
  }

  vector<vector<int>> findSubsequences(vector<int> &nums) {
    result.clear();
    path.clear();
    backtracing(nums, 0);
    return result;
  }
};