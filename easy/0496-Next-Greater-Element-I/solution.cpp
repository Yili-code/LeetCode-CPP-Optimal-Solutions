class Solution {
public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    // monotonic stack
    vector<int> result(nums2.size(), -1);
    stack<int> st;
    for (int i = 0; i < nums2.size(); ++i) {
      while (!st.empty() && nums2[i] > nums2[st.top()]) {
        result[st.top()] = nums2[i];
        st.pop();
      }
      st.push(i);
    }

    // build value -> index mapping
    unordered_map<int, int> um;
    int i = 0;
    for (int num : nums2) {
      um[num] = result[i++];
    }

    for (int &num : nums1) {
      num = um[num];
    }

    return nums1;
  }
};