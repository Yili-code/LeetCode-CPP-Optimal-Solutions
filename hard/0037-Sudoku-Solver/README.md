## classification: backtracing

## key insight

Unlike many typical backtracing problems that require all possible solutions (e.g., permutations, subsets), **Sudoku Solver only needs a single valid solution**.

Because of this, the backtracing function returns a `bool`, allowing the algorithm to **terminate early as soon as one valid solution is found**, significantly improving efficiency.
