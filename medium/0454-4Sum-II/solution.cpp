class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    unordered_map<int, int> sum_map; // sum -> count
    for (int i : nums1) {
      for (int j : nums2) {
        sum_map[i + j]++;
      }
    }

    int result = 0;
    for (int i : nums3) {
      int sum = 0;
      for (int j : nums4) {
        int sear = 0 - (i + j);
        if (sum_map.find(sear) != sum_map.end()) {
          result += sum_map[sear];
        }
      }
    }
    return result;
  }
};
