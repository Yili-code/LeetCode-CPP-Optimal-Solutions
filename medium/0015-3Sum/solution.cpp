// 3Sum
class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> result;

    // sort the array
    sort(nums.begin(), nums.end());

    // fix the first element using a loop
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int target = -nums[i];
      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        int sum = nums[left] + nums[right];

        if (target == sum) {
          result.push_back({nums[i], nums[left], nums[right]});

          while (left < right && nums[left] == nums[left + 1])
            ++left;
          while (left < right && nums[right] == nums[right - 1])
            --right;

          ++left;
          --right;

        } else if (sum < target) {
          left++;
        } else if (sum > target) {
          right--;
        }
      }
    }
    return result;
  }
};
