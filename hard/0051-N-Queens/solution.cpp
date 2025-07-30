class Solution {
public:
  vector<vector<string>> result;

  void backtracing(vector<string>& chessboard, int n, int row) {
    // termination condition
    if (row == n) {
      result.push_back(chessboard);
      return;
    }

    for (int col = 0; col < n; ++col) {
      if (isValid(row, col, chessboard, n)) {
        chessboard[row][col] = 'Q';
        backtracing(chessboard, n, row + 1);
        chessboard[row][col] = '.';
      }
    }
  }

  bool isValid(int row, int col, vector<string>& chessboard, int n) {
    // check column
    for (int  i = 0; i < row; ++i) {
      if (chessboard[i][col] == 'Q') return false;
    }

    // check upper-left diagonal
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
      if (chessboard[i][j] == 'Q') return false;
    }

    // check upper-right diagonal
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
      if (chessboard[i][j] == 'Q') return false;
    }

    return true;
  }

  vector<vector<string>> solveNQueens(int n) {
    result.clear();
    vector<string> chessboard(n, string(n, '.'));
    backtracing(chessboard, n, 0);
    return result;
  }
};