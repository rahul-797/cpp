int maxDepth(TreeNode* root) {
  queue<TreeNode*> q;
  if (root == NULL) return 0;
  int height = 0;
  q.push(root);
  vector<TreeNode*> vec;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      TreeNode* temp = q.front();
      q.pop();
      if (temp->left != NULL) q.push(temp->left);
      if (temp->right != NULL) q.push(temp->right);
    }
    height++;
  }
  return height;
}
