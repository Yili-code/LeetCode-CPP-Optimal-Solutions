#include <vector> 
using namespace std;

class Solution {
public: 
  long long maxProfit(vector<int> &prices, vector<int> &strategy, int k) {
    int n = prices.size();

    // Compute original sum
    long long original = 0;
    for (int i = 0; i < n; ++i) {
      original += 1LL * prices[i] * strategy[i];
    }

    // Compute the preffix sum
    vector<long long> ps(n + 1, 0); // ps[k]: sum of prices[i] * strategy[i] for i in [0, k - 1]
    vector<long long> p(n + 1, 0); // p[k]: sum prices[i] for i in [0, k - 1]

    for (int i = 0; i < n; ++i) {
      ps[i+1] = ps[i] + 1LL * prices[i] * strategy[i];
      p[i+1] = p[i] + 1LL * prices[i];
    }

    // Compute original with each gain
    long long result = original;

    int half = k / 2;
    for (int i = 0; i + k <= n; ++i) {
      int mid = i + half; // first one in second half
      int end = i + k; // the one out of second half range

      // compute the first half
      long long firstHalf = ps[mid] - ps[i];

      // compute the second half
      long long secondHalf = (p[end] - p[mid]) - (ps[end] - ps[mid]);

      long long gain = -firstHalf + secondHalf;
      result = max(result, original + gain);
    }

    return result;

  }
};