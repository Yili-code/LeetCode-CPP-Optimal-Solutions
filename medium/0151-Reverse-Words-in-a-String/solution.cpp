class Solution {
public:
  string reverseWords(string s) {
    // remove leading/trailing/multiple spaces
    removeExtraSpaces(s);

    // reverse the whole string
    reverse(s.begin(), s.end());

    // reverse each word in-place
    int re_start = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == ' ' || i == s.size() - 1) {
        reverse(s.begin() + re_start,
                (i == s.size() - 1 ? s.end() : s.begin() + i));
        re_start = i + 1;
      }
    }
    return s;
  }

private:
  void removeExtraSpaces(string &s) {
    // remove leading spaces
    int slow = 0;
    int fast = 0;
    while (s[fast] == ' ')
      ++fast;

    // remove mutiple spaces
    int n = s.size();
    while (fast < n) {
      if (s[fast] != ' ' || s[fast] == ' ' && s[fast - 1] != ' ') {
        s[slow++] = s[fast++];
      } else if (s[fast] == ' ' && s[fast - 1] == ' ') {
        ++fast;
      }
    }

    // remove trailing spaces
    if (slow > 0 && s[slow - 1] == ' ')
      slow--;
    s.resize(slow);
  }
};