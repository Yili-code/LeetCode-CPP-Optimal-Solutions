class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (!root)
      return nullptr;

    // swap right child pointer and left child pointer
    swap(root->left, root->right);

    // left
    invertTree(root->left);

    // right
    invertTree(root->right);

    return root;
  }
};