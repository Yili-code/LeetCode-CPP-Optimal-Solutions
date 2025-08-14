class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    heights.push_back(0); // sentinel to flush stack
    stack<int> st;        // store indices
    int maxArea = 0;

    for (int i = 0; i < heights.size(); ++i) {
      // find the right boundary for the heights[st.top()]
      while (!st.empty() && heights[i] < heights[st.top()]) {
        int h = heights[st.top()];
        st.pop();
        int left = st.empty() ? -1 : st.top();
        int width = i - left - 1;
        maxArea = max(maxArea, h * width);
      }
      st.push(i);
    }

    return maxArea;
  }
};