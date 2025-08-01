## classification: greedy

## key insight
1. Sort the array first so that negative numbers come first.
2. Flip negative numbers into positive until `k == 0` or no negatives left.
3. If `k` is still odd, flip the number with the smallest absolute value once.
   - Flipping twice has no effect.
4. Finally, sum all the numbers for the result.


## optimize
```cpp
if (k % 2 == 1) {
      sort(nums.begin(), nums.end());
      nums[0] = -nums[0];
    }

-> time complxity: O (n logn)

if (k % 2 == 1) {
  int* minPtr = min_element(nums.begin(), nums.end());
  *minPtr = -*minPtr;
}

-> time complxity: O (n)
```
`min_element` : find the pointer point to the address of smallest number in vector `nums`.

