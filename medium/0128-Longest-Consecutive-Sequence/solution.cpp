class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 0;

    for (int num : s) {
      int length = 0;
      if (s.find(num - 1) == s.end()) {
        length = 1;
        while (s.find(num + 1) != s.end()) {
          ++length;
          ++num;
        }
      }
      maxLen = max(length, maxLen);
    }

    return maxLen;
  }
};