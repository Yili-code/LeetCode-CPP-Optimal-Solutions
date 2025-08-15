## Topics: Array, Binary Search, Divide and Conquer

## key insight
1. Avoid fully emerging the arrays with divide and conquer and binary search.

2. Easy Solution: takes O(m + n) time and O(m + n)

```cpp
class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    vector<int> merged;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] < nums2[j]) merged.push_back(nums1[i++]);
      else merged.push_back(nums2[j++]);
    }

    while (i < nums1.size()) merged.push_back(nums1[i++]);
    while (j < nums2.size()) merged.push_back(nums2[j++]);

    int n = merged.size();
    if (n % 2 == 1) return merged[n / 2];
    return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
  }
}
```

3. Split the arrays into two halves such that: 

  - Left half has exactly `(m+n+1) / 2` elements.

  - All numbers in the left half <= all numbers in the right half

4. The median is: 

  - max of the left half if total length is odd 

  - average of max(left half) and min (right half) if total length if even