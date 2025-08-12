## classification: dynamic programming

## key insight
1. Find the minimum count: `dp[i] = min(dp[i], dp[i - j*j] + 1);`