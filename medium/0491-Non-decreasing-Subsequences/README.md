## Classification: Backtracking

## Key Insight

1. Use `unordered_set<int> used` to remove duplicates in the same recursion level:
   - Insert element into set:  
     ```cpp
     used.insert(x);
     ```
   - Check if element exists:  
     ```cpp
     if (used.count(x)) { ... }
     ```

2. Always check if `path` is not empty before accessing `path.back()` to avoid out-of-bounds crash:
   ```cpp
   if (!path.empty() && path.back() > nums[i]) continue;
   ```
