#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 144 二叉树的前序遍历
 * https://leetcode.cn/problems/binary-tree-preorder-traversal/
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

void traversal(std::vector<int>& res, TreeNode* root) {
  if (root == nullptr) return;
  res.emplace_back(root->val);
  traversal(res, root->left);
  traversal(res, root->right);
}

std::vector<int> preorderTraversal(TreeNode* root) {
  std::vector<int> res;
  traversal(res, root);
  return res;
}

int main(int argc, char* argv[]) { return 0; }
