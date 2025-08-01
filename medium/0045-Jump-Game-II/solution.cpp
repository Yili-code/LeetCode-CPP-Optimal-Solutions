class Solution {
public:
  int jump(vector<int> &nums) {
    int jumps = 0;    // Minimum number of jumps
    int end = 0;      // The farthest position reachable by the current jump
    int farthest = 0; // The farthest position reachable by the next jump

    for (int i = 0; i < nums.size() - 1; ++i) {
      farthest = max(farthest, i + nums[i]);

      // When reaching tht farthest position of the current step, a jump must be made next
      if (i == end) {
        ++jumps;
        end = farthest;
      }
    }

    return jumps;
  }
};
