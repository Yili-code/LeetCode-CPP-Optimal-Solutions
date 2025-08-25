class Solution {
public:
  bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
    stack<int> st;
    int i = 0; // the index of popped

    for (int num : pushed) {
      st.push(num);
      while (!st.empty() && st.top() == popped[i]) {
        st.pop();
        ++i;
      }  
    }

    return i == popped.size();
  }
};