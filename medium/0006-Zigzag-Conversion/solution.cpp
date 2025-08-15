class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1 || s.size() <= numRows) return s; // preCheck

    vector<string> path(numRows);
    bool down = false;
    int i = 0;

    for (char ch : s) {
      path[i] += ch;
      if (i == 0 || i == numRows - 1) down = !down;
      i += down ? 1 : -1;
    }

    string result;
    for (string &str : path) result += str;
    return result;
  }
};