// Remove All Adjacent Duplicates In String
class Solution {
public:
  string removeDuplicates(string s) {
    stack<char> st;

    for (char c : s) {
      if (!st.empty() && st.top() == c) {
        st.pop();
      } else {
        st.push(c); // <== You missed this!
      }
    }

    string result;
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }

    reverse(result.begin(), result.end());
    return result;
  }
};