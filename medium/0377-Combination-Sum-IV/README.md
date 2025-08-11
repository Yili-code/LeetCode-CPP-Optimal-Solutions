## classification: dynamic programming

## insight
1. Order-sensitive permutations

```cpp 
for (int i = 0; i <= target; ++i) {
  for (int num : nums) {
    if (i - num >= 0) {
      dp[i] += dp[i - num];
    }
  }
}
```

2. Avoid overflow -> `vector<uint64_t> dp(...)`

