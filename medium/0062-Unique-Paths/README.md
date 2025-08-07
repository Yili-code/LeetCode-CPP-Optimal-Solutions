## classification: dynamic programming

## key insight

1. Understand the dynamic programming `dp` means.

2. Initialize the first row and first column.

```cpp
for (int i = 0; i < m; ++i) dp[i][0] = 1;
for (int i = 0; i < n; ++i) dp[0][i] = 1;
```

3. Fill the table

```cpp
for (int i = 1; i < m; ++i) {
  for (int j = 1; j < n; ++j) {
    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
  }
}
```
