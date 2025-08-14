## classification: monotonic stack

## key insight
1. Brute-force approacb with `O(n^2)` -> Time Limit Exceeded

```cpp
class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int result = heights[0];
    for (int i = 0; i < heights.size(); ++i) {
      int area = 0;
      int left = i, right = i;
      
      while (left - 1 >= 0 && heights[left - 1] >= heights[i]) --left;
      while (right + 1 < heights.size() && heights[right + 1] >= heights[i]) ++right;

      area = (right - left + 1) * heights[i];
      if (area >= result) result = area;
    }

    return result;
  }
}; 
```

2. Stack-based O(n)

find the nearest smaller bar on the left and right for each bar in a single pass.

  - Maintain indices of bars in decreasing height order in a stack.

    - find greater, then maintain in increasing order in the stack.

    - find smaller, then maintain in decreasing order in the stack.
  
  - When you see a bar shorter than the one on top of the stack, you pop from the stack and calculate area.
  
  - Each bar is pushed and popped at most once -> O(n) time.

3. sentinel to flush stack: `height.push_back(0);`

4. `int left = st.empty() ? -1 : st.top();`

If stack is empty after popping, that means this bar extends all the way to the start.
Otherwise, `st.top()` now points to the first smaller bar on the left.

5. `int width = i - left - 1;`

`i` = first smaller bar on the right (current index).
