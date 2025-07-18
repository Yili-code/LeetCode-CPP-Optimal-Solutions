class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root)
      return false;

    targetSum -= root->val;

    // leaf node
    if (!root->left && !root->right) {
      return targetSum == 0;
    }

    return ((root->left && hasPathSum(root->left, targetSum)) ||
            (root->right && hasPathSum(root->right, targetSum)));
  }
};