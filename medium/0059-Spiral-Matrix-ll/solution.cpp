// Spiral Matrix II

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> v(n, vector<int>(n, 0));
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int count = 1;

    while (count <= n * n) {
      // left to right
      for (int i = left; i <= right; i++) {
        v[top][i] = count++;
      }
      top++;

      // top to bottom
      for (int i = top; i <= bottom; i++) {
        v[i][right] = count++;
      }
      right--;

      // right to left
      for (int i = right; i >= left; i--) {
        v[bottom][i] = count++;
      }
      bottom--;

      // bottom to top
      for (int i = bottom; i >= top; i--) {
        v[i][left] = count++;
      }
      left++;
    }
    return v;
  }
};

int main() {
  int n;
  cin >> n;
  Solution sol;
  vector<vector<int>> result = sol.generateMatrix(n);

  for (const auto &row : result) {
    for (int val : row) {
      cout << val << "\t";
    }
    cout << "\n";
  }

  return 0;
}