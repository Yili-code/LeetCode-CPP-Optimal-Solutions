class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        for (auto& q : queries) {
            int li = q[0], ri = q[1], ki = q[2], vi = q[3];
            for (int idx = li; idx <= ri; idx += ki) {
                nums[idx] = (1LL * nums[idx] * vi) % MOD; // prevent overflow
            }
        }

        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};
