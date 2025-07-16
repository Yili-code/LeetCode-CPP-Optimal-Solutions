class Solution {
public:
  // helper function: return height if balanced, else return -1
  int check(TreeNode *node) {

    if (!node)
      return 0;

    int leftHeight = check(node->left);
    if (leftHeight == -1)
      return -1;

    int rightHeight = check(node->right);
    if (rightHeight == -1)
      return -1;

    // if tree is unbalanced
    if (abs(leftHeight - rightHeight) > 1)
      return -1;

    return 1 + max(leftHeight, rightHeight);
  }

  bool isBalanced(TreeNode *root) { return check(root) != -1; }
};