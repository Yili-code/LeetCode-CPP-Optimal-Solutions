class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    unordered_map<int, int> basket;
    int left = 0, maxLen = 0;

    for (int right = 0; right < fruits.size(); right++) {
      basket[fruits[right]]++;

      while (basket.size() > 2) {
        basket[fruits[left]]--;
        if (basket[fruits[left]] == 0) {
          besket.erase(fruits[left]);
        }
        left++;
      }

      maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
  }
};
