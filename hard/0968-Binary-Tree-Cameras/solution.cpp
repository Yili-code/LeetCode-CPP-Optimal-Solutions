class Solution {
public:
  int result = 0;

  // post-order traversal
  int backtracing(TreeNode *root) {
    if (!root) return 2; // null nodes are considered covered

    int left = backtracing(root->left);
    int right = backtracing(root->right);

    if (left == 0 || right == 0) {
      ++result;
      return 1; // place camera here
    } else if (left == 1 || right == 1) {
      return 2; // this node is covered
    } else {
      return 0; // this node is not covered
    }
  }

  int minCameraCover(TreeNode *root) {
    if (backtracing(root) == 0) ++result;
    return result;
  }
};
