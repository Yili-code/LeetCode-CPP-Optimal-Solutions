class Solution {
public:
  void helper(TreeNode *node, vector<int> &v) {
    if (!node) return;

    helper(node->left, v);  // left
    v.push_back(node->val); // middle
    helper(node->right, v); // right
  }

  bool isValidBST(TreeNode *root) {
    // inorder traverse: left middle right
    if (!root) return true;

    vector<int> v;
    helper(root, v);

    // if vector v is increasing, then return true
    bool result = true;
    for (int i = 0; i < v.size() - 1; ++i) {
      if (v[i] >= v[i + 1])
        result = false;
    }
    return result;
  }
};