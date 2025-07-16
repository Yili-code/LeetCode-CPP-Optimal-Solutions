// Repeated Substring Pattern
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

/*
s = 01234
doubled = 0123401234
trim = 12340123
false

s = 012012
doubled = 012012012012
trimmed = 1201201201
true

s = 012012

*/