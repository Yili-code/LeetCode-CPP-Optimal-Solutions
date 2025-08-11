## classification: dynamic programming

## key insight
1. preCheck: `if(amount == 0) return 1` is redundant.

already have dp[0] = 1. Returning dp[0] would naturally give 1 without the pre-check.


2. Use `vector<uint64_t> dp(...)` to avoid overflow.