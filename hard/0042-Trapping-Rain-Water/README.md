## classification: monotonic stack

## key insight
1. The stack stores indices of bars in monotonic decreasing order.

2. When we find a bar taller than the stack's top:
  - That means we found a right boundary.
  - The popped index is the bottom of a water container.
  - The new stack top is the left boundary.

3. Water height = `min(leftBoundaryHeight, rightBoundaryHeight) - bottomHeight`.

4. Water width = distance between boundarues minus 1.