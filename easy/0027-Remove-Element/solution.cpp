#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[index] = nums[i];
        index++;
      }
    }
    return index;
  }
};

void printVector(const vector<int> &nums, int length) {
  for (int i = 0; i < length; ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
}

int main() {
  Solution sol;

  vector<int> nums1 = {3, 2, 2, 3};
  int len1 = sol.removeElement(nums1, 3);
  cout << len1 << ": ";
  printVector(nums1, len1);

  vector<int> nums2 = {1, 2, 3, 4};
  int len2 = sol.removeElement(nums2, 5);
  cout << len2 << ": ";
  printVector(nums2, len2);

  vector<int> nums3 = {1, 1, 1, 1};
  int len3 = sol.removeElement(nums3, 1);
  cout << len3 << ": ";
  printVector(nums3, len3);

  vector<int> nums4 = {4, 1, 4, 2, 4, 3};
  int len4 = sol.removeElement(nums4, 4);
  cout << len4 << ": ";
  printVector(nums4, len4);

  vector<int> nums5 = {};
  int len5 = sol.removeElement(nums5, 0);
  cout << len5 << ": ";
  printVector(nums5, len5);

  return 0;
}
