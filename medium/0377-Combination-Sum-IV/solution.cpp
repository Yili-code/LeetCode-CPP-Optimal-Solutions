class Solution {
public:
  int combinationSum4(vector<int> &nums, int target) {
    // dp definition: dp[k] -> the number of ways to reach sum k
    vector<uint64_t> dp(target + 1, 0);
    dp[0] = 1; // base case

    for (int i = 0; i <= target; ++i) {
      for (int num : nums) {
        if (i - num >= 0) {
          dp[i] += dp[i - num];
        }
      }
    }

    return dp[target];
  }
};