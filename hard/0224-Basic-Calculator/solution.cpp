class Solution {
public:
  int calculate(string s) {
    stack<int> st; // handling the expression between '(' and ')'
    int result = 0;
    int number = 0;
    int sign = 1; // 1: + ; -1: -

    for (int i = 0; i < s.size(); ++i) {
      char ch = s[i];

      if (isdigit(ch)) {
        number = number * 10 + (ch - '0');
      } else if (ch == '+' || ch == '-') {
        result += sign * number;
        number = 0;
        sign = ch == '+' ? 1 : -1;
      } else if (ch == '(') {
        st.push(sign); sign = 1;
        st.push(result); result = 0;
      } else if (ch == ')') {
        // handling the computation in the ()
        result += number * sign;
        number = 0;

        int preResult = st.top(); st.pop();
        int preSign = st.top(); st.pop();

        // Compute
        result = result* preSign + preResult;
      } 
    }

    result += sign * number;
    return result;
  }
};