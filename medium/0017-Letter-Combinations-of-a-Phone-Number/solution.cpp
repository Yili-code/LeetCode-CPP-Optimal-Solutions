class Solution {
public:
  vector<string> result;
  string temp;
  vector<vector<char>> alphabits = {{'a', 'b', 'c'}, {'d', 'e', 'f'},
                                    {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                    {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                    {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

  void backtracking(const string &digits, int index) {
    // termination condition
    if (index == digits.size()) {
      result.push_back(temp);
      return;
    }

    int num = digits[index] - '2';
    for (char c : alphabits[num]) {
      temp.push_back(c);
      backtracking(digits, index + 1);
      temp.pop_back(); // backtrack
    }
  }

  vector<string> letterCombinations(string digits) {
    result.clear();
    temp.clear();
    if (digits.empty())
      return result; // edge case

    backtracking(digits, 0);
    return result;
  }
};
