## classification: greedy

## key insight
1. Declare variable: `int jumps = 0;`

2. Use `end` to record the current farthest reachable position
  - When `i` reachs `end`, increase `jumps` and update `end` to `farthest` 