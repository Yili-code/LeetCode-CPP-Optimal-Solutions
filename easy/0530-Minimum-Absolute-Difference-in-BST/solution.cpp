class Solution {
public:
  void helper(TreeNode *node, vector<int>& v) {
    if (!node) return;

    helper(node->left, v); // left
    v.push_back(node->val); // middle 
    helper(node->right, v); // right
    
    return;
  }

  int getMinimumDifference(TreeNode *root) {
    if (!root) return 0;

    vector<int> v;
    helper(root, v);

    int result = __INT_MAX__;
    for (int i = 0; i < v.size() - 1; ++i) {
      if (v[i + 1] - v[i] < result) {
        result = v[i + 1] - v[i];
      }
    }

    return result;
  }
};