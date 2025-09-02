#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    // minHeap
    priority_queue<int, vector<int>, greater<int>> pq; 

    for (int num : nums) {
      if (pq.size() < k || num >= pq.top()) {
        pq.push(num);
      }
      
      if (pq.size() > k) pq.pop();
    }

    return pq.top();
  }
};