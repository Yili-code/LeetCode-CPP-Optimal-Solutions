class Solution {
public:
  int findMinArrowShots(vector<vector<int>> &points) {
    if (points.empty()) return 0;

    sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b) { 
      return a[0] < b[0]; 
    });

    int result = 1;
    int limit = points[0][1];

    for (int i = 1; i < points.size(); ++i) {
      if (points[i][0] <= limit) {
        // overlap, narrow down the overlapping range
        limit = min(limit, points[i][1]);
      } else {
        ++result;
        limit = points[i][1];
      }
    }

    return result;
  }
};
