class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // count the frequency of each number
    unordered_map<int, int> freq; 
    for (int num : nums) { ++freq[num]; }

    // ues s minHeap to keep top k elements
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
    for (auto& [num, count] : freq) {
      minHeap.push({count, num});
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    // extract result from heap
    vector<int> result;
    while (!minHeap.empty()) {
      result.push_back(minHeap.top().second);
      minHeap.pop();
    }
    
    reverse(result.begin(), result.end());
    return result;
  }
};