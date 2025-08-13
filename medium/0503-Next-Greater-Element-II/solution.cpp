class Solution {
public:
  vector<int> nextGreaterElements(vector<int> &nums) {
    vector<int> result(nums.size(), -1);
    stack<int> st;

    for (int i = 0; i < 2 * nums.size(); ++i) {
      int num = nums[i % nums.size()];
      while (!st.empty() && num > nums[st.top()]) {
        result[st.top()] = num;
        st.pop();
      }
      if (i < nums.size()) st.push(i);
    }

    return result;
  }
};
