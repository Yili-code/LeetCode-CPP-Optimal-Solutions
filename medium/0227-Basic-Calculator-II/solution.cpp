class Solution {
public:
  int calculate(string s) {
    if (s.size() == 0) return 0;

    int number = 0;
    stack<int> st;
    char op = '+';

    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];
       
      // If ch is digit, then the operator would not change
      if (isdigit(ch)) {
        number = number * 10 + (ch - '0');
      }

      // If ch is operator, then the operator would change
      if ((!isdigit(ch) && ch != ' ') || i == s.size() - 1) {
        if (op == '+') {
          st.push(number);
        } else if (op == '-') {
          st.push(-number);
        } else if (op == '*') {
          int temp = st.top() * number;
          st.pop();
          st.push(temp);
        } else if (op == '/') {
          int temp = st.top() / number;
          st.pop();
          st.push(temp);
        }

        number = 0;
        op = ch;
      }
    }

    int result = 0;
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }

    return result;
    
  }
};