## clssification: backtracing

## key insight
1. Solve the duplicate subset: trim
```cpp
if (i > startIndex && nums[i] == nums[i - 1]) continue;
```

2. Sorting is a prerequisite for pruning duplicate branches