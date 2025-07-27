class Solution {
public:
  vector<int> temp;
  vector<vector<int>> result;
  int total;

  void backtracking(int k, int n, int startIndex) {
    if (n < 0) return;
    
    // termination condition
    if (temp.size() == k) {
      if (n == 0) result.push_back(temp);
      return;
    } 

    // recursion
    for (int i = startIndex; i <= min(n, 9); ++i) {
      temp.push_back(i);
      backtracking(k, n - i, i + 1);
      temp.pop_back();
    }
  }

  vector<vector<int>> combinationSum3(int k, int n) {
    backtracking(k, n, 1);
    return result;
  }
};

// k: 3  n: 7