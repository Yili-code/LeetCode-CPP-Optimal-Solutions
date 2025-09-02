#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int findNonMinOrMax(vector<int> &nums) {
    priority_queue<int> maxHeap;

    for (int num : nums) { maxHeap.push(num); }

    if (maxHeap.size() <= 2) return -1;
    maxHeap.pop();
    return maxHeap.top();
  }
};