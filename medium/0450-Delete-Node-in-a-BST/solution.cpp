class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (!root) return nullptr;

    if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left && !root->right) {
        return nullptr;
      } else if (!root->left) {
        return root->right;
      } else if (!root->right) {
        return root->left;
      } else {
        // find min in right subtree (successor)
        int successor = findMin(root->right);
        root->val = successor;

        // delete the successor
        root->right = deleteNode(root->right, successor);
      }
    }
    
    return root;
  }

private:
  int findMin(TreeNode* root) {
    while (root->left) {
      root = root->left;
    }

    return root->val;
  }
};