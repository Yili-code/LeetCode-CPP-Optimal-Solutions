class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> um; // alpha -> exist
    int maxLength = 0;
    int left = 0, right = 0;
    
    while (right < s.size()) {
      char c = s[right];
      ++um[c]; // include new char

      // check the left boundary to shrink window if duplicate
      while (um[c] > 1) {
        --um[s[left]];
        ++left;
      }

      maxLength = max(maxLength, right - left + 1);
      ++right;
    }

    return maxLength;
  }
};