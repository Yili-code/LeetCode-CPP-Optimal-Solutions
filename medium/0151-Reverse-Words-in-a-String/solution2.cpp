class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        stringstream ss(s);
        string word;

        // Split sentence into words
        while (ss >> word) {
            st.push(word);
        }

        // Reconstruct in reverse
        string result;
        while (!st.empty()) {
            result += st.top();
            st.pop();
            if (!st.empty()) result += " ";
        }

        return result;
    }
};