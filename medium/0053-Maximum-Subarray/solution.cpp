class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      // If adding nums[i] makes the sum smaller, then start a new subarray from nums[i]
      currentSum = max(nums[i], currentSum + nums[i]);
      maxSum = max(maxSum, currentSum);
    }

    return maxSum;
  }
};
