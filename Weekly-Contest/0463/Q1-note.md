## Time Complexity: O(n^2)

```cpp
class Solution {
public:
  long long maxProfit(vector<int> &prices, vector<int> &strategy, int k) {
    // original
    int result = 0;
    for (int a = 0; a < prices.size(); ++a) {
      result += prices[a] * strategy[a];
    }

    // modified    
    for (int i = 0; i < prices.size() - (k - 1); ++i) {
      int sum = 0;

      for (int a = 0; a < prices.size(); ++a) {
        // strategy[a] == 0
        if (a >= i && a <= i + k / 2 - 1) continue;
        
        // strategy[a] == 1
        else if (a > i + k / 2 - 1 && a <= i + k - 1) {
          sum += prices[a];
          continue;
        }
        
        sum += prices[a] * strategy[a];
      }
      result = max(result, sum);
    }

    return result;
  }
};
```

## Optimization

newSum = originalSum + gain(i)

`gain(i)`: the difference made by modifying the window `[i, i+k-1]`.

  - If `a` is in first half: old contribution = `prices[a] * strategy[a]`, new = `0`.
    -> difference = `-prices[a] * strategy[a]`.

  - If `a` is in second half: old contribution = `prices[a] * strategy[a]`, new = `prices[a]`.
    -> difference = `prices[a] * (1 - strategy[a])`.

`gain(i)` = ( a=i ~ i+k/2-1 (-prices[a] * strategy[a])) + (a=i+k/2 ~ i+k-1 (prices[a] * (1 - strategy[a])))