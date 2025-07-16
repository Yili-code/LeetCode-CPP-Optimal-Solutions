// Minimum Size Subarray Sum
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    // declaration left, sum, result.
    int left = 0, sum = 0;
    int result = INT_MAX;

    for (int right = 0; right < nums.size(); ++right) {
      sum = sum + nums[right];

      while (sum >= target) {
        result = min(result, right - left + 1);
        sum = sum - nums[left];
        ++left;
      }
    }
    return (result == INT_MAX) ? 0 : result;
  }
};

// 2, 3, 1, 2, 4, 3
// 0  1  2  3  4  5
// nums.size() = 6

int main() {
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  Solution sol;
  int result = sol.minSubArrayLen(target, nums);
  cout << result << endl;
  return 0;
}