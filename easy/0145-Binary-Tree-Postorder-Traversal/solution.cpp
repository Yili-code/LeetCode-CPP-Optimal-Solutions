class Solution {
public:
  void postorder(TreeNode *node, vector<int> &result) {
    if (!node) {
      return;
    }
    postorder(node->left, result);  // left
    postorder(node->right, result); // right
    result.push_back(node->val);    // middle
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    postorder(root, result);
    return result;
  }
};