class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> um;         // pattern -> string
    unordered_map<string, char> reverse_um; // string -> pattern

    // convert strging s into vector<string>
    vector<string> words;
    string temp;
    for (int i = 0; i <= s.size(); ++i) {
      if (i == s.size() || s[i] == ' ') {
        if (!temp.empty()) {
          words.push_back(temp);
          temp.clear();
        }
      } else {
        temp.push_back(s[i]);
      }
    }

    // preCheck
    if (words.size() != pattern.size())
      return false;

    // bidirection mapping
    for (int i = 0; i < pattern.size(); ++i) {
      char ch = pattern[i];
      string word = words[i];

      if (um.count(ch) && um[ch] != word)
        return false;
      if (reverse_um.count(word) && reverse_um[word] != ch)
        return false;

      um[ch] = word;
      reverse_um[word] = ch;
    }

    return true;
  }
};
