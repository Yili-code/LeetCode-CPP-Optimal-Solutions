class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, int> um; // num -> count

    for (int num : nums) {
      if (um[num] == 1) return true;
      ++um[num];
    }

    return false;
  }
};