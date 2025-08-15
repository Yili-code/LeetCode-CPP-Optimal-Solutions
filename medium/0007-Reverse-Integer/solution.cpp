class Solution {
public:
  int reverse(int x) {
    bool isNagetive = x < 0;

    string str = to_string(abs((long long)x));
    std::reverse(str.begin(), str.end());
    long long num = stoll(str);

    if (isNagetive) num = -num;
    if (num < INT_MIN || num > INT_MAX) return 0;
    return (int)num;
  }
};