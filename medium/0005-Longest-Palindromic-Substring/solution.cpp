class Solution {
public:
  string longestPalindrome(string s) {
    if (s.empty()) return ""; // preCheck
    int maxLen = 1;
    int start = 0; // the maxLen string start index

    for (int center = 0; center < s.size(); ++center) {
      helper(s, center, center, maxLen, start); // odd length palindrome
      helper(s, center, center + 1, maxLen, start); // even length palindrome
    }

    return s.substr(start, maxLen);
  }

  void helper(const string &s, int left, int right, int &maxLen, int &start) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      // check whether the length greater than maxLen
      if (right - left + 1 > maxLen) {
        maxLen = right - left + 1;
        start = left;
      }
      
      right++;
      left--;
    }
  }
};