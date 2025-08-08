class Solution {
public:
  int numTrees(int n) {
    // dp state definition: dp[k] represents the number of BSTs which have n nodes
    vector<int> dp(n + 1, 0);

    // initialization (base cases)
    dp[0] = 1;
    dp[1] = 1;

    // recurrence relation: dp[i] = sum over j = 1 ~ i , dp[j - 1] * dp[i - j]
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i; ++j) {
        dp[i] += dp[j - 1] * dp[i - j];
      }
    }   

    return dp[n];
  }
};