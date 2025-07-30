class Solution {
public:
  bool backtracing(vector<vector<char>> &board) {
    for (int row = 0; row < 9; ++row) {
      for (int col = 0; col < 9; ++col) {
        if (board[row][col] == '.') {
          for (char c = '1'; c <= '9'; ++c) {
            if (isValid(board, row, col, c)) {
              board[row][col] = c;
              if (backtracing(board))
                return true;
              board[row][col] = '.';
            }
          }
          return false;
        }
      }
    }
    return true;
  }

  bool isValid(vector<vector<char>> &board, int row, int col, int num) {
    // check row, column and square
    for (int i = 0; i < 9; ++i) {
      if (board[row][i] == num || board[i][col] == num ||
          board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
        return false;
    }
    return true;
  }

  void solveSudoku(vector<vector<char>> &board) { backtracing(board); }
};
