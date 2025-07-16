class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> um;
    for (char ch : magazine) {
      ++um[ch];
    }

    for (char ch : ransomNote) {
      if (um[ch] != 0) {
        --um[ch];
      } else if (um[ch] == 0) {
        return false;
      }
    }

    return true;
  }
};