class Solution {
public:
  void helper(TreeNode *node, vector<int> &v, int &preVal, int &count, int &maxCount, bool &hasPrev) {
    if (!node) return;

    helper(node->left, v, preVal, count, maxCount, hasPrev);

    if (hasPrev && node->val == preVal) {
      ++count;
    } else {
      // New value encountered
      count = 1;
      preVal = node->val;
      hasPrev = true;
    }

    if (count > maxCount) {
      v.clear();
      v.push_back(node->val);
      maxCount = count;
    } else if (count == maxCount) {
      v.push_back(node->val);
    }

    helper(node->right, v, preVal, count, maxCount, hasPrev);
  }

  vector<int> findMode(TreeNode *root) {
    if (!root) return {};

    int preVal = 0;
    int count = 0;
    int maxCount = 0;
    bool hasPrev = false; // To handle the very first node
    vector<int> v;

    helper(root, v, preVal, count, maxCount, hasPrev);

    return v;
  }
};
