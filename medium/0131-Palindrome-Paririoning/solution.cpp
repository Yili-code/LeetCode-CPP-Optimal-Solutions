class Solution {
public:
  vector<vector<string>> result;
  vector<string> path;

  void backtracing(string &s, int startIndex) {
    // termination condition
    if (startIndex == s.length()) {
      result.push_back(path);
      return;
    };

    for (int i = startIndex; i < s.length(); ++i) {
      // Get the substring from startIndex to i
      string sub = s.substr(startIndex, i - startIndex + 1);

      if (isPalindrome(sub)) {
        path.push_back(sub);
        ;
        backtracing(s, i + 1);
        path.pop_back();
      }
    }
  }

  bool isPalindrome(const string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      if (s[left++] != s[right--])
        return false;
    }
    return true;
  }

  vector<vector<string>> partition(string s) {
    result.clear();
    path.clear();
    backtracing(s, 0);
    return result;
  }
};