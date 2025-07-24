class Solution {
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (!root) {
      return new TreeNode(val); // 空樹，直接創建新節點
    }

    if (root->val > val) {
      root->left = insertIntoBST(root->left, val);
    } else {
      root->right = insertIntoBST(root->right, val);
    }

    return root;
  }
};