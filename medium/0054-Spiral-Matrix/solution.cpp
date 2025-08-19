class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int count = m * n;

    vector<int> result;
    result.reserve(count);

    int left = 0, right = n - 1;
    int top = 0, bottom = m - 1;

    while ((int)result.size() < count) {
      // 1. Left → Right
      for (int j = left; j <= right && (int)result.size() < count; ++j) {
        result.push_back(matrix[top][j]);
      }
      ++top;

      // 2. Top → Bottom
      for (int i = top; i <= bottom && (int)result.size() < count; ++i) {
        result.push_back(matrix[i][right]);
      }
      --right;

      // 3. Right → Left
      for (int j = right; j >= left && (int)result.size() < count; --j) {
        result.push_back(matrix[bottom][j]);
      }
      --bottom;

      // 4. Bottom → Top
      for (int i = bottom; i >= top && (int)result.size() < count; --i) {
        result.push_back(matrix[i][left]);
      }
      ++left;
    }

    return result;
  }
};
