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
  void getPath(TreeNode *node, vector<int> path, vector<string> &result) {
    path.push_back(node->val); // middle

    // if node->left and node->right both are nullptr, then return path
    if (!node->left && !node->right) {
      string temp = to_string(path[0]);
      for (int i = 1; i < path.size(); ++i) {
        temp += "->" + to_string(path[i]);
      }
      result.push_back(temp);
      return;
    }

    // if one of node->left and node->right is not empty, then node = node->...
    // left
    if (node->left) {
      getPath(node->left, path, result);
    }

    // right
    if (node->right) {
      getPath(node->right, path, result);
    }
  }

  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root)
      return {};
    vector<string> result;
    vector<int> path;
    getPath(root, path, result);
    return result;
  }
};