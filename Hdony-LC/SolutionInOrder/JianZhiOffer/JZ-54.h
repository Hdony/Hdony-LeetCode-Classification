/*
 * 给定一棵二叉搜索树，请找出其中第 k 大的节点。
 *
 * 示例 1:
 * 输入: root = [3,1,4,null,2], k = 1
 *    3
 *   / \
 *  1   4
 *   \
 *    2
 * 输出: 4
 *
 * 示例 2:
 * 输入: root = [5,3,6,2,4,null,null,1], k = 3
 *        5
 *       / \
 *      3   6
 *     / \
 *    2   4
 *   /
 *  1
 * 输出: 4
 *  
 * 限制：
 * 1 ≤ k ≤ 二叉搜索树元素个数
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
private:
    int res;
    int k;
public:
    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }

    void dfs(TreeNode* curr) {

        if (curr != nullptr) {
            dfs(curr->right);
            k--;
            if (k == 0) { // 正好是第k个，则更新res
                res = curr->val;
                return;
            }
            dfs(curr->left);
        }
    }
};
