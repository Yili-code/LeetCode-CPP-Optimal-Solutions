// valid parentheses
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (char ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        if (ch == '(') {
          st.push(')');
        } else if (ch == '{') {
          st.push('}');
        } else if (ch == '[') {
          st.push(']');
        }
      } else {
        if (st.empty())
          return false;

        if (st.top() != ch)
          return false;

        st.pop();
      }
    }
    if (!st.empty())
      return false;
    return true;
  }
};