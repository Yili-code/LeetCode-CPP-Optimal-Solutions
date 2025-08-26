class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> qu;
    qu.push(root);

    while (!qu.empty()) {
      int size = qu.size();
      vector<int> temp;

      for (int i = 0; i < size; ++i) {
        TreeNode *frontNode = qu.front();
        qu.pop();

        temp.push_back(frontNode->val);

        if (frontNode->left) qu.push(frontNode->left);
        if (frontNode->right) qu.push(frontNode->right);
      }

      result.push_back(temp);
    }

    return result;
  }
};