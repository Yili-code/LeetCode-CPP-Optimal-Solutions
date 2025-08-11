class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    // preCheck
    if (strs.size() == 0) return 0;

    // DP definition: dp[i][j]: the number of ways to reach sum m = i and n = j
    vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

    for (string s : strs) {
      // count the number of zero and one in s
      int z = 0, o = 0; 
      for (char c : s) {
        if (c == '0') ++z;
        else ++o;
      }

      // Traverse backwards
      for (int i = m; i >= z; --i) {
        for (int j = n; j >= o; --j) {
          dp[i][j] = max(dp[i][j], dp[i - z][j - o] + 1);
        }
      }
    }

    return dp[m][n];
  }
};