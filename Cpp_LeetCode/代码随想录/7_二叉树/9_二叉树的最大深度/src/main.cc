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

// 后序遍历求最大深度
int maxDepth(TreeNode* root) {
  if (root == nullptr) return 0;
  int leftDepth = maxDepth(root->left);
  int rightDepth = maxDepth(root->right);
  return 1 + std::max(leftDepth, rightDepth);
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
