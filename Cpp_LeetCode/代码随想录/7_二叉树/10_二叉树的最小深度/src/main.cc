#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 104 二叉树的最大深度
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/description/
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

// 层序遍历求最小深度（根节点到叶子结点的最短距离）
int minDepth(TreeNode* root) {
  std::queue<TreeNode*> que;
  size_t size;
  int minDepth = 0;
  TreeNode* cur = root;
  if (cur != nullptr) {
    que.push(cur);
  }
  while (!que.empty()) {
    size = que.size();
    minDepth++;
    while (size--) {
      TreeNode* node = que.front();
      que.pop();
      if (node->left != nullptr) que.push(node->left);
      if (node->right != nullptr) que.push(node->right);
      if (node->left == nullptr && node->right == nullptr) return minDepth;
    }
  }
  return 0;  // 如果que为空，则返回0表示二叉树为空
}

// 后序遍历（左右中）求最小深度
int minDepth_V2(TreeNode* root) {
  if (root == nullptr) return 0;             // 遇到空节点，返回高度0
  int leftHeight = minDepth_V2(root->left);  // 左
  int rightHeight = minDepth_V2(root->right);  // 右
  // 以下为 中
  if (leftHeight == 0 && rightHeight != 0) return 1 + rightHeight;
  if (leftHeight != 0 && rightHeight == 0) return 1 + leftHeight;
  if (leftHeight == 0 && rightHeight == 0) return 1;
  return 1 + std::min(leftHeight, rightHeight);
}

int main(int argc, char* argv[]) {
  int n;
  std::vector<int> nums;
  while (std::cin >> n) {
    nums.emplace_back(n);
  }

  auto root = TreeInit(nums);

  return 0;
}
