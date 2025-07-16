class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
  }
};

class Solution {
public:
  inr maxDepth(TreeNode *root) {
    if (!root)
      return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};