class Solution {
public:
  string frequencySort(string s) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : s) {
      ++freq[ch];
    }

    // Max heap to sort by frequency
    priority_queue<pair<int, char>> maxHeap;
    for (auto &[ch, f] : freq) {
      maxHeap.push({f, ch}); // {frequency, character}
    }

    // Build result string
    string result;
    while (!maxHeap.empty()) {
      auto [f, ch] = maxHeap.top();
      maxHeap.pop();
      result.append(f, ch); // add 'ch' f times
    }

    return result;
  }
};
