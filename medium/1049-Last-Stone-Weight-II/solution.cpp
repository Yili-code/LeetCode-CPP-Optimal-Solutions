class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    // pre-check
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    sort(stones.rbegin(), stones.rend());
    if (stones[0] > target) return stones[0] - (sum - stones[0]);

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : stones) {
      for (int i = target; i >= num; --i) {
        dp[i] = dp[i] || dp[i - num];
      }
    }

    for (int i = target; i >= 0; --i) {
      if (dp[i]) return sum - 2 * i;   
    }

    return 0; // theorectically unreachable
  }
};