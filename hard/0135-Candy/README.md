## problem description

distributing the minimum number of candies to children based on their ratings while satisfying two rules:
  1. Every child gets at least one candy.
  2. Children with a higher rating than their neighbors must get more candies than those neighbors.

## classification: greedy

## key insight
1. Use two directional passes to handle neighbor comparisons.

2. Ensure local minimum conditions are satisfied avoiding over-distribution.

3. This is a classic greedy solution that balances local optimality with global constrains.

---

## When to use bidirectional passes
1. neighbor-based constrains

2. Does this problem involve comparing to neighbors (i ± 1)?

3. Will processing in only one direction miss part of the requirement?

4. Can a two-pass traversal simplify local decisions?