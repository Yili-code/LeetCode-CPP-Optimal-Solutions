class Solution {
public:
  void inorder(TreeNode *node, vector<int> &result) {
    if (!node) {
      return;
    }

    inorder(node->left, result);  // left
    result.push_back(node->val);  // middle
    inorder(node->right, result); // right
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    inorder(root, result);
    return result;
  }
};