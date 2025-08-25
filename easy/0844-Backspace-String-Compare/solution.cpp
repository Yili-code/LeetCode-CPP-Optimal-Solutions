class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sst, tst;

        // Process s
        for (char c : s) {
            if (c == '#') {
                if (!sst.empty()) sst.pop();
            } else {
                sst.push(c);
            }
        }

        // Process t
        for (char c : t) {
            if (c == '#') {
                if (!tst.empty()) tst.pop();
            } else {
                tst.push(c);
            }
        }

        // Compare stacks
        while (!sst.empty() && !tst.empty()) {
            if (sst.top() != tst.top()) return false;
            sst.pop();
            tst.pop();
        }

        return sst.empty() && tst.empty();
    }
};
