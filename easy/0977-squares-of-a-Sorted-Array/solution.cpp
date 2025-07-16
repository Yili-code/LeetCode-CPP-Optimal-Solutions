class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> newVector(nums.size());
    int index = nums.size() - 1;
    int left = 0;
    int right = nums.size() - 1;
    while (right >= left) {
      if (nums[right] * nums[right] > nums[left] * nums[left]) {
        newVector[index] = nums[right] * nums[right];
        right--;
        index--;
      } else {
        newVector[index] = nums[left] * nums[left];
        left++;
        index--;
      }
    }
    return newVector;
  }
};