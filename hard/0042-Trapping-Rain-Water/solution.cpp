class Solution {
public:
  int trap(vector<int> &height) {
    stack<int> st; // store indices
    int result = 0;

    for (int i = 0; i < height.size(); ++i) {
      while (!st.empty() && height[i] > height[st.top()]) {
        int middle = st.top();
        st.pop();
        if (st.empty()) break;
        int h = min(height[i], height[st.top()]) - height[middle];
        int w = i - st.top() - 1;
        result += h * w;
      }
      st.push(i);
    }
    return result;
  }
};
