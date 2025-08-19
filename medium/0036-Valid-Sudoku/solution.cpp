#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    if (board.size() != 9 || board[0].size() != 9) return false;

    for (int i = 0; i < 9; ++i) {
      unordered_map<char, int> column; 
      for (int j = 0; j < 9; ++j) {
        char num = board[j][i];
        if (num == '.') continue;
        if (column[num] == 1) {
          cout << num << "column" << endl;
          return false;
        } else {
          ++column[num];
        }
      }

      unordered_map<char, int> row;
      for (int j = 0; j < 9; ++j) {
        char num = board[i][j];
        if (num == '.') continue;
        if (row[num] == 1) {
          cout << "row" << endl;
          return false;
        } else {
          ++row[num];
        }
      }

      unordered_map<char, int> square;
      int rowStart = (i / 3) * 3;
      int colStart = (i % 3) * 3;

      for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
          char num = board[rowStart + r][colStart + c];
          if (num == '.') continue;
          if (square[num] == 1) {
            return false;
          } else {
            ++square[num];
          }
        }
      }
    }

    return true;
  }
};

