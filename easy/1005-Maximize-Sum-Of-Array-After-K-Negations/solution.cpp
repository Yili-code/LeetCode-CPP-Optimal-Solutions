class Solution {
public:
  int largestSumAfterKNegations(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int index = 0;
    // flip the negative numbers into positive
    while (k > 0 && index < nums.size() && nums[index] < 0)  {
      nums[index] = -nums[index];
      ++index;
      --k;
    }

    // If `k` is still odd, flip the number with the smallest absolute value once
    if (k % 2 == 1) {
      sort(nums.begin(), nums.end());
      nums[0] = -nums[0];
    }

    // sum all the numbers for the result
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    
    return sum;
  }
};