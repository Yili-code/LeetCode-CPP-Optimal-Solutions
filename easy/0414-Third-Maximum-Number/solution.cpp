#include <vector>
#include <queue>
#include <functional>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
  int thirdMax(vector<int> &nums) {
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> seen;

    for (int num : nums) {
      if (seen.count(num)) continue;
      seen.insert(num);

      pq.push(num);
      if (pq.size() > 3) pq.pop();
    }

    if (pq.size() < 3) return *max_element(nums.begin(), nums.end());
    return pq.top();
  } 
};