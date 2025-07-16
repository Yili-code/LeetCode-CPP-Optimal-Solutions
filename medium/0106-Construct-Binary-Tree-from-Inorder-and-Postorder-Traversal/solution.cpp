class Solution {
  TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int instart,
                   int inend, int poststart, int postend) {
    if (instart > inend || poststart > postend)
      return nullptr;

    // create a new node
    int rootValue = postorder[postend];
    TreeNode *root = new TreeNode(rootValue);

    // find the root index in inorder array
    int middleIndex = instart;
    while (inorder[middleIndex] != rootValue) {
      ++middleIndex;
    }

    // record the size, in order to adjust the range of left/right subtree
    int size = middleIndex - instart;

    // connect to left node
    root->left = helper(inorder, postorder, instart, middleIndex - 1, poststart,
                        poststart + size - 1);

    // connect to right node
    root->right = helper(inorder, postorder, middleIndex + 1, inend,
                         poststart + size, postend - 1);

    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    if (n == 0)
      return nullptr;
    return helper(inorder, postorder, 0, n - 1, 0, n - 1);
  }
};