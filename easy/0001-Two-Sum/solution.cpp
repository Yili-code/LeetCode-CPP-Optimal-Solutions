class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map; // value -> index
    for (int i = 0; i < nums.size(); ++i) {
      int sear = target - nums[i];

      auto iter = map.find(sear);
      if (iter != map.end()) {
        return {iter->second, i};
      } else {
        map.insert({nums[i], i});
      }
    }
    return {};
  }
};