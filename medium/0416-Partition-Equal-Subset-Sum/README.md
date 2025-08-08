## classification: dynamic programming

## key insight
1. Sum must be even
  - if the total sum of all elements is odd, it's impossible to split into two equal parts.
  - use `int sum = accumulate(nums.begin(), nums.end(), 0);`

2. Subset sum problem
  - The problem reduces to: Can we find a subset of numbers whose sum is exactly `total_sum/2`

3. Dynamic Programming
  - Similar to 0/1 Knapsack, where: 
    - Capacity = target sum (`total_sum/2`)
    - Items = numbers in `nums`

4. Optimization
  - Use 1D DP array and iterate backward for capacity to avoid overwriting states in the same iteration.
  - This guarantees each `num` is used only once per state update.


## syntax
```cpp
accumulate(first, last, init);
// init -> initial value for the sum (start with total = init).

```