class Solution {
public:
  void addFunction(TreeNode *node, int &result) {
    if (!node)
      return;

    // 如果有左子樹，並且左子樹是葉節點
    if (node->left && !node->left->left && !node->left->right) {
      result += node->left->val;
    }

    // 遞迴遍歷左右子樹
    addFunction(node->left, result);
    addFunction(node->right, result);
  }

  int sumOfLeftLeaves(TreeNode *root) {
    if (!root)
      return 0;
    int result = 0;
    addFunction(root, result);
    return result;
  }
};
