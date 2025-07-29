class Solution {
public:
  vector<string> result;
  string path;

  void backtracing(const string &s, int startIndex, int pointSum) {
    // termination condition 
    if (pointSum == 3) {
      string lastPart = s.substr(startIndex);
      if (isValid(lastPart)) {
        result.push_back(path + lastPart);
      }
      return;
    }

    // for loop
    for (int i = startIndex; i < s.size() && (i - startIndex) < 3; ++i) {
      // check whether sub is valid
      string sub = s.substr(startIndex, i - startIndex + 1);
      if (isValid(sub)) {
        int originLength = path.length();
        path = path + sub;
        path = path + '.';
        backtracing(s, i + 1, pointSum + 1);
        path.erase(originLength);
      }
    }
  }

  bool isValid(const string& s) {
    if (s.empty()) return false;
    if (s.length() > 1 && s[0] == '0') return false;
    if (stoi(s) > 255) return false;
    return true;
  }

  vector<string> restoreIpAddresses(string s) {
    result.clear();
    path.clear();
    if (s.length() < 4 || s.length() > 12) return result;
    backtracing(s, 0, 0);
    return result;
  }
};
