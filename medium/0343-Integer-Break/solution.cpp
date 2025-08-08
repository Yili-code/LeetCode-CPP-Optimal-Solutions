class Solution {
public:
  int integerBreak(int n) {
    // Dp state definition: dp[i]: max product for integer i
    vector<int> dp(n + 1, 0);

    // Base cases
    dp[1] = 1;

    // Bottom-up Approach
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        // recurrence relation: dp[i] = max over j = 1 ~ (i - 1) , max( (j * (i - j), j * dp[i - j] )
        dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
      }
    }

    return dp[n];
  }
};