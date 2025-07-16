/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
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