class Solution {
public:
  int monotoneIncreasingDigits(int n) {
    // turn integer into string in order to traverse easier
    string str = to_string(n);
    int flag = str.size(); // use flag to record the index which's back need to change to 9

    for (int i = str.size() - 1; i > 0; --i) {
      if (str[i - 1] > str[i]) {
        --str[i - 1];
        flag = i;
      }
    }

    for (int i = flag; i < str.size(); ++i) {
      str[i] = '9';
    }

    return stoi(str);
  }
};