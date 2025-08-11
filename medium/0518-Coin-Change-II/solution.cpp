class Solution {
public:
  int change(int amount, vector<int> &coins) {
    // DP Definition: dp[k]: the number of ways to sum k
    vector<uint_64> dp(amount + 1, 0);

    // Initialization (base case)
    dp[0] = 1;

    // traverse forwards
    for (int coin : coins) {
      for (int j = coin; j <= amount; ++j) {
        dp[j] += dp[j - coin];
      }
    }
    return dp[amount];
  }
};