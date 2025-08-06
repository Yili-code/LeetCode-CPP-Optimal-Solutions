## classification: greedy

## key insight
1. Use post-order DFS (bottom-up traversal) to label each node with one of three states, and greedily place cameras only when absolutly necessary.
  - `0` : Node is not covered -> needs its parent to have a camera,
  - `1` : Node has a camera.
  - `2` : Node is covered.

2. Decision Rule during DFS traversal
  At each node:
  - If either child is in state 0 (not covered) → must place a camera at this node (return 1)
  - If either child has a camera (1) → this node is covered (return 2)
  - If both children are covered but have no camera (2) → this node is not covered (return 0)
 
```cpp

left    0 0 0 1 1 1 2 2 2

right   0 1 2 0 1 2 0 1 2 

parent  1 1 1 1 + + 1 + + 
parent  1 2 1 2 2 2 1 2 + 
parent  1 2 1 2 2 2 1 2 0

```

3. `if (backtracing(root) == 0) ++result;`

4. `if (!root) return 2` cus if (left == 2 && right == 2) return 0;