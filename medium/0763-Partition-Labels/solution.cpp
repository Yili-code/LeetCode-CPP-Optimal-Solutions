class Solution {
public:
  vector<int> partitionLabels(string s) {
    if (s.size() == 0) return {};
    
    // record the last occurrence of each character
    int lastIndex[26] = {0};
    for (int i = 0; i < s.size(); ++i) {
      lastIndex[s[i] - 'a'] = i;
    }

    vector<int> result;
    int left = -1, right = 0;
    for (int i = 0; i < s.size(); ++i) {
      right = max(right, lastIndex[s[i] - 'a']);
      if (i == right) {
        result.push_back(i - left);
        left = i;
      }
    }

    return result;
  }
};