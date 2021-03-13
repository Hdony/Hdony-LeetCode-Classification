/*
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
 * 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 *
 * 示例 1:
 * 给定二叉树 [3,9,20,null,null,15,7]
 *    3
 *   / \
 *  9  20
 *    /  \
 *   15   7
 * 返回 true 。
 *
 * 示例 2:
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 *       1
 *      / \
 *     2   2
 *    / \
 *   3   3
 *  / \
 * 4   4
 * 返回 false 。
 *
 * 限制：
 * 0 <= 树的结点个数 <= 10000
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }

    int dfs(TreeNode* node) {
        if (node != nullptr) {
            int left = dfs(node->left);
            if (left == -1) return -1;

            int right = dfs(node->right);
            if (right == -1) return -1;

            return abs(left - right) > 1 ? -1 : max(left, right) + 1;
        } else
            return 0;
    }
};