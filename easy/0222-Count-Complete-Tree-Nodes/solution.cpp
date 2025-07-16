class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root)
      return 0;

    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    if (leftDepth == rightDepth) {
      return (1 << leftDepth) + countNodes(root->right);
    } else {
      return (1 << rightDepth) + countNodes(root->left);
    }
  }

  int getDepth(TreeNode *node) {
    int depth = 0;
    while (node) {
      ++depth;
      node = node->left;
    }
    return depth;
  }
};
