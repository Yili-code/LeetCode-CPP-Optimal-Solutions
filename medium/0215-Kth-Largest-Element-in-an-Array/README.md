## nth_element
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    nth_element(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
    return nums[nums.size() - k];
  }
};
```

Syntax: `std:nth_element(start, nth, end, comparator);`
elements in left side are smaller and elements in right side are greater


## Min-heap (priority_queue)
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap
    for (int x : nums) {
      pq.push(x);
      if ((int)pq.size() > k) pq.pop();
    }
    return pq.top();
  }
};
```

## Priority_queue
```cpp
#include <queue>
#include <vector>
#include <functional> // for std::greater

std::priority_queue<int> maxHeap;

std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
```


## Quickselect
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = (int)nums.size();
        int target = n - k; // index if array were sorted ascending
        int l = 0, r = n - 1;
        std::mt19937 rng(std::random_device{}()); // randomize to avoid worst-case

        while (l <= r) {
            // choose random pivot to reduce worst-case likelihood
            int pivotIdx = std::uniform_int_distribution<int>(l, r)(rng);
            int pivot = nums[pivotIdx];
            // 3-way partition (Dutch National Flag style)
            int i = l, m = l, j = r;
            while (m <= j) {
                if (nums[m] < pivot) swap(nums[i++], nums[m++]);
                else if (nums[m] > pivot) swap(nums[m], nums[j--]);
                else m++;
            }
            // Now [l, i-1] < pivot, [i, j] == pivot, [j+1, r] > pivot
            if (target < i) r = i - 1;
            else if (target > j) l = j + 1;
            else return nums[target]; // target lies in the equal block
        }
        return -1; // should never reach here if input is valid
    }
};
```