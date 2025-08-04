class Solution {
public:
  int candy(vector<int> &ratings) {
    vector<int> result(ratings.size(), 1);

    // left -> right
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) result[i] = max(result[i - 1] + 1, result[i]);
    }

    // right -> left
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) result[i] = max(result[i + 1] + 1, result[i]);
    }

    int sum = 0;
    for (int i : result) {
      sum += i;
    }

    return sum;
  }
};