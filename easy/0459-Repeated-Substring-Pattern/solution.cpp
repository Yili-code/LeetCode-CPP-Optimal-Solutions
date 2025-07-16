class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    string doubled = s + s;
    string trimmed = doubled.substr(1, doubled.size() - 2);
    return trimmed.find(s) != string::npos;
  }
};

class Solution {
public:
  bool repeatedSubstringPattern(string s) {
    string trimmed = s.substr(1, s.size() - 2);
    return trimmed.find(s) !
  }
}