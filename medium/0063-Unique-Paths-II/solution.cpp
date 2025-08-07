class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // If the starting point has obstacle, return 0
    if (obstacleGrid[0][0] == 1) return 0;

    dp[0][0] = 1;

    // initialize first column
    for (int i = 1; i < m; ++i) {
      if (obstacleGrid[i][0] == 0)
        dp[i][0] = dp[i - 1][0];
    }

    // initialize first row
    for (int j = 1; j < n; ++j) {
      if (obstacleGrid[0][j] == 0)
        dp[0][j] = dp[0][j - 1];
    }

    // fill rest of dp table
    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        // else dp[i][j] = 0, already defaulted in initialization
      }
    }

    return dp[m - 1][n - 1];
  }
};
