## classification: backtracing

## common mistakes
1. Incorrect Data Type for `chessboard`
  ```cpp
  vector<string> chessboard(n, string(n, '.'));  // Initialize n x n board with '.'
  ```

2. Incorrect Implementation of `isValid()` Function
  - check column
  - Use two variables to scan diagonally up-left and diagonally up-right.
    - check upper-left diagonal
    ```cpp
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (chessboard[i][j] == 'Q') return false;
    }
    ```

    - check upper-right diagonal
    ```cpp 
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (chessboard[i][j] == 'Q') return false;
    } 
    ```
