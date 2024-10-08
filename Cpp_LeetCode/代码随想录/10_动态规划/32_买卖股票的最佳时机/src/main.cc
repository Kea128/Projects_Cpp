#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief 121_买卖股票的最佳时机
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

/**
 * @brief 递归当前节点是否偷，返回偷与不偷的数组
 * @note 使用后序遍历。 因为要通过递归函数的返回值来做下一步计算
 */
std::vector<int> robtree(TreeNode *cur) {
  if (cur == nullptr) {
    return std::vector<int>{0, 0};
  }
  // 递归计算左右节点的偷与不偷
  std::vector<int> left = robtree(cur->left);
  std::vector<int> right = robtree(cur->right);

  // 偷当前节点
  int val1 = cur->val + left[0] + right[0];
  // 不偷当前节点
  int val2 = std::max(left[0], left[1]) + std::max(right[0], right[1]);
  return {val2, val1};
}

int rob(TreeNode *root) {
  std::vector<int> res = robtree(root);
  return std::max(res[0], res[1]);
}

int main(int argc, char const *argv[]) { return 0; }
