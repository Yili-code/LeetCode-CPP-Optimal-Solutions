// Intersection of Two Arrays
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    int hash[1000] = {0};
    vector<int> result;

    for (int num : nums1) {
      hash[num] = 1;
    }

    for (int num : nums2) {
      if (hash[num] == 1) {
        result.push_back(num);
        hash[num] = -1;
      }
    }
    return result;
  }
};