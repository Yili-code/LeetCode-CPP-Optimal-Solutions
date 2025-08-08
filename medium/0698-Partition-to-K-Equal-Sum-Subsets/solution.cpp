class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    // preCheck
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;
    
    int target = sum / k;
    sort(nums.rbegin(), nums.rend()); // descending for pruning
    if (nums[0] > target) return false;

    vector<bool> visited(nums.size(), false);
    return backtrack(nums, visited, k, 0, 0, target);
  }

private:
  bool backtrack(vector<int> &nums, vector<bool> &visited, int k, int start, int currSum, int target) {
    // only one subset left, must be true
    if (k == 1) return true; 

    // one subset done, recurse for next subset
    if (currSum == target) return backtrack(nums, visited, k - 1, 0, 0, target);

    for (int i = start; i < nums.size(); ++i) {
      if (!visited[i] && currSum + nums[i] <= target) {
        visited[i] = true;
        if (backtrack(nums, visited, k, i + 1, currSum + nums[i], target)) return true;
        visited[i] = false;
      }
    }

    return false;
  }
};