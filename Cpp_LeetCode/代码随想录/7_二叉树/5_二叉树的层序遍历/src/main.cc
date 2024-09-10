#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 102 二叉树的层序遍历
 * https://leetcode.cn/problems/binary-tree-level-order-traversal/description/
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::queue<TreeNode*> que;
  std::vector<std::vector<int>> res;
  if (root != nullptr) que.push(root);
  size_t size;
  while (!que.empty()) {
    size = que.size();
    std::vector<int> level;
    while (size--) {
      TreeNode* node = que.front();
      que.pop();
      level.emplace_back(node->val);
      if (node->left != nullptr) que.push(node->left);
      if (node->right != nullptr) que.push(node->right);
    }
    res.emplace_back(level);
  }
  return res;
}

int main(int argc, char* argv[]) { return 0; }
