class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (!root || root == p || root == q) return root;

    if (root->val < p->val && root->val < q->val) {
      TreeNode* right = lowestCommonAncestor(root->right, p, q);
      return right;
    } else if (root->val > p->val && root->val > q->val) {
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      return left;
    } else {
      return root;
    }
  }
};