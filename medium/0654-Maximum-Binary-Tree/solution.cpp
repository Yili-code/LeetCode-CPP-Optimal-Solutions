class Solution {
public:
  TreeNode *helper(vector<int> &nums, int start, int end) {
    // if vector is empty, then return nullptr
    if (start > end)
      return nullptr;

    // find the max value in current tree
    int rootVal = nums[start];
    int maxValIndex = start;
    for (int i = start; i <= end; ++i) {
      if (nums[i] > rootVal) {
        maxValIndex = i;   // record the max value index
        rootVal = nums[i]; // update the max value
      }
    }

    // create a new node
    TreeNode *root = new TreeNode(rootVal);

    root->left = helper(nums, start, maxValIndex - 1); // connect to left child
    root->right = helper(nums, maxValIndex + 1, end);  // connect to right child

    return root;
  }

  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    int n = nums.size();
    if (n == 0)
      return nullptr;
    return helper(nums, 0, n - 1);
  }
};