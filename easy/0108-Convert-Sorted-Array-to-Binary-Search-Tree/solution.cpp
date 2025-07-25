class Solution {
public:
  TreeNode *helper(vector<int> &nums, int left, int right) {
    if (left > right)
      return nullptr;

    // build a new Note for the middle (or slightly right) one in vector
    int middle = (right + left + 1) / 2;
    TreeNode *middleNode = new TreeNode(nums[middle]);

    middleNode->left = helper(nums, left, middle - 1);   // left
    middleNode->right = helper(nums, middle + 1, right); // right

    return middleNode;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};
