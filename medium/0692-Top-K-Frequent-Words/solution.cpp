class Solution {
public:
  vector<string> topKFrequent(vector<string> &words, int k) {
    unordered_map<string, int> freq; // word -> count

    for (string str : words) { ++freq[str]; }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    for (auto &[word, count] : freq) {
      minHeap.push_back({count, word});
      if (minHeap.size() > k) minHeap.pop();
    }

    vector<string> result;
    while (!minHeap.empty()) {
      result.push_back(minHeap.top().second);
      minHeap.pop();
    }

    reverse(result.begin(), result.end());
    return result;
  }
};