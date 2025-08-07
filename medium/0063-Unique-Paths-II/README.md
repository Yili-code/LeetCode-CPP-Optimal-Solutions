## dynamic programming

## key insight
1. Correctly declare the number of columns (`s`):

```cpp
int n = obstacleGrid[0].size();
```

2. Proper initialization of the fisrt row and column

When initializing, if you encounter an obstacle (`1`), all subsequent cells in that row or column should be set to `0` and the loop should break immediately.

```cpp
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
```

3. Handling obstacles during state transition:
if `obstacleGrid[i][j] == 1`, it means the cell is blocked, so must set `dp[i][j] = 0;`

```cpp
if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
// else dp[i][j] = 0, already defaulted in initialization
```