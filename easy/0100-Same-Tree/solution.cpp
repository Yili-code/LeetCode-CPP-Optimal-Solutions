class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    if ((!p && q) || (p && !q))
      return false;
    if (p->val != q->val)
      return false;

    isSameTree(p->right, q->right);
    isSameTree(p->left, q->left);

    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
  }
};

// more simple
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q)
      return true;
    if (!p || !q)
      return false;
    if (p->val != q->val)
      return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
}