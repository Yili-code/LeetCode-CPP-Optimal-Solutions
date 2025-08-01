## classification: greedy

## key insight

1. If total gas < total cost, there's no solution.
```cpp
int totalTank = 0;
for (int i = 0; i < nums.size(); ++i) {
  int gain = gas[i] - cost[i];
  total += gain;
}
```

2. Try to simulate the circuit:
   - Maintain a current tank (`currTank`) and total tank (`totalTank`).
   - If current tank becomes negative at station i (can't reach the next station), then **restart from i + 1.**
3. The valid start index is the one after the segment that failed.

## time complxity: O(n)