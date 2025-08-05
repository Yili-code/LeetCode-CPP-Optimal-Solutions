class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.size() == 0 || intervals.size() == 1) return intervals;

    // Sort by start time, and by end time if starts are equal 
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    vector<vector<int>> result;
    int start = intervals[0][0];
    int end = intervals[0][1];

    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] <= end) {
        end = max(end, intervals[i][1]); // overlapping, merge
      } else {
        result.push_back({start, end});
        // move to next interval
        start = intervals[i][0];
        end = intervals[i][1];  
      }
    }

    result.push_back({start, end}); // push the last merged interval
    return result;
  }
};