class Solution {
public:
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (!root) return nullptr;

    if (root->val < low ) {
      // some node in its right subtree may be accepted
      return trimBST(root->right, low, high);
    } else if (root->val > high) {
      // some node in its left subtree may be accepted
      return trimBST(root->left, low, high);
    }

    // low < root->val < high, then keep trimming
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
  }
};