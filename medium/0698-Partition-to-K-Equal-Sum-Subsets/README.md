## dynamic programming

## key insight
1. Descending for pruning and pre-checking: `sort(nums.rbegin(), nums.rend());`

2. Use `currSum == target` to check whether the subset is done.
```cpp
if (currSum == target) return backtrack(nums, visited, k - 1, 0, 0, target);
```

3.