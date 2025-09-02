class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    // Count frequency
    unordered_map<string, int> freq; // word -> count
    for (const string& str : words) { ++freq[str]; }

    // Move to vector for sorting
    vector<pair<string, int>> vec(freq.begin(), freq.end());

    // Custom sorting
    sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
      if (a.second != b.second) return a.second > b.second;
      return a.first < b.first;
    });

    // Collect top k
    vector<string> result;
    for (int i = 0; i < k; ++i) { result.push_back(vec[i].first); }

    return result;
  }
};