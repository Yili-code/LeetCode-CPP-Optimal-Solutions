## classification: greedy

## key insight

1. The problem allows nagative numbers, so the case where all elements are negative must be considered. 
In such case, the correct answer should be the largest negative number, not zero.

2. If adding nums[i] makes the sum smaller, then start a new subarray from nums[i]