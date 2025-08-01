class Solution {
public:
  bool canJump(vector<int> &nums) {
    if (nums.empty())
      return false;

    int cover = 0;
    for (int i = 0; i <= cover; ++i) {
      cover = max(cover, nums[i] + i);
      if (cover >= nums.size() - 1)
        return true;
    }

    return false;
  }
};