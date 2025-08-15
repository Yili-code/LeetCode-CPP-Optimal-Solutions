class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    // Ensure nums1 is the smaller array
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();
    int totalLeft = (m + n + 1) / 2; // If m + n is odd, then the elements in left half = right + 1

    int left = 0, right = m;
    while (left <= right) {
      int i = (left + right) / 2; // the number taken from nums1 into the left half
      int j = totalLeft - i;      // the number taken from nums2 into the left half

      int nums1LeftMax = (i == 0) ? INT_MIN : nums1[i - 1];
      int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
      int nums2LeftMax = (j == 0) ? INT_MIN : nums2[j - 1];
      int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

      if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
        // Found correct partition
        if ((m + n) % 2 == 1) {
          return max(nums1LeftMax, nums2LeftMax);
        } else {
          return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
        }
      } else if (nums1LeftMax > nums2RightMin) {
        right = i - 1; // Move left in nums1
      } else {
        left = i + 1; // Move right in nums1
      }
    }

    return 0.0;
  }
};
