## classification: greedy

## key insight
1. skip all initial equal numbers
```cpp
while (index + 1 < nums.size() && nums[index + 1] == nums[index]) {
      ++index;
    }
```

2. Edge case: all numbers are equal
```cpp
if (index + 1 == nums.size()) return 1;
```

3. 