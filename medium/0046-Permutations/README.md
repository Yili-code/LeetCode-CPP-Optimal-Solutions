## classification: backtracing

## key insight

紀錄「位置」有沒有被用過，而不是值是否重複，因此不能使用 `unordered_set<int> used`, 而是
```cpp 
vector<bool> used(nums.size(), false);
create a boolean array with the same length as nums, and initialize all values to false (indicating that none of the elements have been used at the beginning.)
```
