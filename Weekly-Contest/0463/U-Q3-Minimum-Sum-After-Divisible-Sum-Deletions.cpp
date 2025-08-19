#include <vector> 
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
  long long minArraySum(vector<int> &nums, int k) {
    vector<int> quorlathin = nums; // store a copy midway

    long long totalSum = accumulate(nums.begin(), nums.end(), 0LL);

    // DP array: dp[i] -> max sum deletable from nums[0..i]
    int n = nums.size();
    vector<long long> dp(n + 1, 0);
    vector<long long> prefix(n + 1, 0);

    for (int i = 0; i < n; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }

    // map remainder to last index
    unordered_map<int, int> lastIndex;
    lastIndex[0] = 0;
  }
};