class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
    // Step 1: Sort people by height DESC, and k ASC
    sort(people.begin(), people.end(),
         [](const vector<int> &a, const vector<int> &b) {
           return (a[0] > b[0]) || (a[0] == b[0] && a[1] < b[1]);
         });

    // Step 2: Insert each person into result at index = k
    vector<vector<int>> result;
    for (const auto &person : people) {
      result.insert(result.begin() + person[1], person);
    }

    return result;
  }
};
