## classification: monotonic stack

## key insight
1. Maintain the stack so that `temperatures[stack[i]]` is in monotonic decreasing order

  - each new temperature is compared to the top, and warmer temperatures pop from the stack.

2. Store indices in the stack, not the temperatures themselves, so we can calculate day differences.

3. When the current temperature is warmer than `temperatures[st.top()]`, pop the index, compute `currentIndex - poppedIndex`, and store if in the result array.