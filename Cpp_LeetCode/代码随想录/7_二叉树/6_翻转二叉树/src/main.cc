#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 226 翻转二叉树
 * https://leetcode.cn/problems/invert-binary-tree/
 */

// 二叉树结构定义
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
};

// 层序遍历初始化二叉树
TreeNode* TreeInit(const std::vector<int>& nums) {
  TreeNode* root = new TreeNode(nums[0]);
  std::queue<TreeNode*> que;
  TreeNode* cur = root;
  que.push(cur);
  for (int i = 1; i < nums.size(); i++) {
    cur = que.front();
    if (i % 2 == 1) {
      cur->left = new TreeNode(nums[i]);
      que.push(cur->left);
    } else {
      cur->right = new TreeNode(nums[i]);
      que.push(cur->right);
      que.pop();
    }
  }
  return root;
}

// 层序遍历二叉树
std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> res;
  std::queue<TreeNode*> que;  // 用队列模拟二叉树的层序遍历
  size_t size;                // 记录当前层的节点数
  if (root != nullptr) que.push(root);
  while (!que.empty()) {
    size = que.size();
    std::vector<int> level;
    while (size--) {
      TreeNode* node = que.front();
      que.pop();
      if (node->left != nullptr) que.push(node->left);
      if (node->right != nullptr) que.push(node->right);
      level.emplace_back(node->val);
    }
    res.emplace_back(level);
  }
  return res;
}

// 翻转二叉树
// 层序遍历方法
TreeNode* invertTree_V1(TreeNode* root) {
  std::queue<TreeNode*> que;
  size_t size;
  if (root != nullptr) que.push(root);
  TreeNode* cur;
  while (!que.empty()) {
    size = que.size();
    while (size--) {
      cur = que.front();
      que.pop();
      // 交换左右子树
      TreeNode* tmp = cur->left;
      cur->left = cur->right;
      cur->right = tmp;
      if (cur->left != nullptr) que.push(cur->left);
      if (cur->right != nullptr) que.push(cur->right);
    }
  }
  return root;
}

// 翻转二叉树
// 前序（中左右）遍历方法（递归）
TreeNode* invertTree_V2(TreeNode* root) {
  if (root == nullptr) return root;
  std::swap(root->left, root->right);
  invertTree_V2(root->left);
  invertTree_V2(root->right);
  return root;
}

// 后序遍历方法（递归）
TreeNode* invertTree_V3(TreeNode* root) {
  if (root == nullptr) return root;
  invertTree_V3(root->left);
  invertTree_V3(root->right);
  std::swap(root->left, root->right);
  return root;
}

// 中序遍历方法（递归）
TreeNode* invertTree_V4(TreeNode* root) {
  if (root == nullptr) return root;
  invertTree_V4(root->left);
  std::swap(root->left, root->right);
  invertTree_V4(root->left);
  return root;
}

int main(int argc, char* argv[]) {
  int n;
  std::vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  auto root = TreeInit(nums);

  auto res = levelOrder(root);
  for (auto& i : res) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  auto invertHead = invertTree_V2(root);
  auto res = levelOrder(invertHead);
  for (auto& i : res) {
    for (auto& j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}
