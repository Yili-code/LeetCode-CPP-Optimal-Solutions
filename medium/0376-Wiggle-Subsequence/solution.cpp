class Solution {
public:
  int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() < 2)
      return nums.size();

    int index = 0;

    // Skip all initial equal numbers
    while (index + 1 < nums.size() && nums[index] == nums[index + 1]) {
      ++index;
    }

    // Edge case: all numbers are equal
    if (index + 1 == nums.size())
      return 1;

    bool up = nums[index + 1] > nums[index]; // first direction
    int result = 2;
    ++index;

    while (index + 1 < nums.size()) {
      int diff = nums[index + 1] - nums[index];

      if ((up && diff < 0) || (!up && diff > 0)) {
        ++result;
        up = !up; // flip direction
      }

      ++index;
    }

    return result;
  }
};
