class Solution {
public:
  int sortPermutation(vector<int> &nums) {
    int n = nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());

    // if already sorted → return 0
    if (nums == sorted)
      return 0;

    int ans = 0;
    // try all possible k (from 0 up to max element)
    int maxVal = n - 1;

    for (int k = 0; k <= maxVal; ++k) {
      // build graph adjacency
      vector<vector<int>> adj(n);
      for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
          if ((nums[i] & nums[j]) == k) {
            adj[i].push_back(j);
            adj[j].push_back(i);
          }
        }
      }

      // compute connected components
      vector<int> comp(n, -1);
      int compId = 0;
      for (int i = 0; i < n; i++) {
        if (comp[i] == -1) {
          queue<int> q;
          q.push(i);
          comp[i] = compId;
          while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
              if (comp[v] == -1) {
                comp[v] = compId;
                q.push(v);
              }
            }
          }
          compId++;
        }
      }

      // check if sortable under this k
      bool ok = true;
      for (int i = 0; i < n; i++) {
        // nums[i] should move to position of sorted[i]
        // they must lie in the same component
        int val = sorted[i];
        // find index of val in nums
        int idx = find(nums.begin(), nums.end(), val) - nums.begin();
        if (comp[i] != comp[idx]) {
          ok = false;
          break;
        }
      }

      if (ok)
        ans = max(ans, k);
    }

    return ans;
  }
};