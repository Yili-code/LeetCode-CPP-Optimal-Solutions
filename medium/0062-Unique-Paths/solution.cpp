class Solution {
public:
  int uniquePaths(int m, int n) {
    int dp[m][n] = {0};

    // initialize first row and first column
    for (int i = 0; i < m; ++i) dp[i][0] = 1;
    for (int i = 0; i < n; ++i) dp[0][i] = 1;

    // fill the rest of the table 
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }
};