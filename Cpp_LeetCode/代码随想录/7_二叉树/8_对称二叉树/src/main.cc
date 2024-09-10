#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

/**
 * @brief 101 对称二叉树
 * https://leetcode.cn/problems/symmetric-tree/description/
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

bool isSymmetric_digui(TreeNode* left, TreeNode* right) {
  if (left == nullptr && right == nullptr)
    return true;
  else if (left != nullptr && right == nullptr)
    return false;
  else if (left == nullptr && right != nullptr)
    return false;
  else if (left->val != right->val)
    return false;
  bool outside = isSymmetric_digui(left->left, right->right);
  bool inside = isSymmetric_digui(left->right, right->left);
  return outside && inside;
}

bool isSymmetric(TreeNode* root) {
  return isSymmetric_digui(root->left, root->right);
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
