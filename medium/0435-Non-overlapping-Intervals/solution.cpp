class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[1] < b[1];
    });

    int count = 1; // always keep the first interval
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] >= end) {
        ++count;
        end = intervals[i][1];
      }
    }

    return intervals.size() - count; // total - non-overlapping intervals = minimum number to remove
  }
};