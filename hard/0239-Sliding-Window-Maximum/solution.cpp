// Sliding Window Maximum
class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    // declare a deque to store index
    deque<int> dq; // store index
    vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
      // remove the index out of window
      if (!dq.empty() && dq.front() <= i - k) {
        dq.pop_front();
      }

      // keep the sequence monotonically decreasing
      while (!dq.empty() && nums[i] >= nums[dq.back()]) {
        dq.pop_back();
      }

      dq.push_back(i);

      // start recording results (only when i >= k - 1, meaning the window is
      // full)
      if (i >= k - 1) {
        result.push_back(nums[dq.front()]);
      }
    }

    return result;
  }
};
