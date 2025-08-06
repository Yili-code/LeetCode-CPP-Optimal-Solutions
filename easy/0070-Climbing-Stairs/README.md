## classification: dynamic programming

## key insight
1. Top-Down (Memoization)
  -> use recursion + cache

```cpp
unordered_map<int, int> memo;

ind climbTree(int n) {
  if (n <= 2) return n;
  if (memo.count(n)) return memo[n];
  return memo[n] = dp(n - 1) + dp(n - 2);
}
```

2. Bottom_Up (Tabulation)
  -> Solve from base case up.

```cpp
int climbTree(int n) {
  if (n <= 2) return n;
  vector<int> dp(n + 1);

  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; ++i) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  
  return dp[n];
}
```


3. Space Optimized DP
  -> only store necessary previous results.

```cpp
int climbTree(int n) {
  if (n <= 2) return n;
  int first = 1, second = 2;

  for (int i = 3; i <= n; ++i) {
    int current = first + second;
    first = second;
    second = current;
  }
  return second;
}