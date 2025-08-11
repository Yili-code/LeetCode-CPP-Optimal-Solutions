class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 != 0) return 0;
        if (sum < abs(target)) return 0;
        int plus = (sum + target) / 2;

        // sort vector nums from smaller to greater
        sort(nums.begin(), nums.end()); 

        // dp state definition: dp[k]: number of ways to reach sum k
        vector<int> dp(plus + 1, 0);

        // initialization (base cases)
        dp[0] = 1;

        // backward traversal logic
        for (int num : nums) {
            for (int i = plus; i >= num; --i) {
                dp[i] += dp[i - num];
            }
        }

        return dp[plus];
    }
};