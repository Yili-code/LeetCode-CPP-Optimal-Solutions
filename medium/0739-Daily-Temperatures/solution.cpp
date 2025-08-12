class Solution {
public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    vector<int> result(temperatures.size(), 0);
    stack<int> st;

    for (int i = 0; i < temperatures.size(); ++i) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        int currentIndex = i; // record the current index
        result[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }

    return result;
  }
};