## classification: dynamic programming

## key insight
1. Optimal Substructure:

Suppose we split `n` into `n` and `i - n`.
The maximum product can come from:
  - 01. Not further splitting: `i * (n - i)`
  - 02. Further splitting `n - i`: `i * dp[n - i]` 

since `(n - i)` can also be broken down, then the recurrence relation is 

```cpp 
dp[n] = max over i = 1 ~ (n-1) { max( i * (n - i), i * dp[n - i]) }
```

2. DP State Definition: 

`dp[k]` represents the maximum product obtainable by splitting the integer `k` into at least two positive integers.


3. Initialization (Base cases) : `dp[2] = 1`


4. Bottom-up Approach:
  - Build from smaller integers to larger ones
  - For each `n`, check both `i * (n - i)` and `i * dp[n - i]` to determine the larger product.


5. Avoid Over-reliance on the Pure Math Greedy Method
  - While it’s mathematically proven that repeatedly breaking into `3`s yields the optimal product, this problem is intended as a dynamic programming exercise. The key is to think in terms of breaking the big problem into smaller subproblems.