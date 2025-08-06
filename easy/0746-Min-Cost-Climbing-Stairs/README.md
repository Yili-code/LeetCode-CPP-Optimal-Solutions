## classification: dynamic programming 

## key insight
1. `dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);`
```cpp
dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]; // BUG: cost[i] may be out of bounds when i == n
```