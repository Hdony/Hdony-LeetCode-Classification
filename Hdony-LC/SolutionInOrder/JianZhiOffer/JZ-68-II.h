/*
 * 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
 * 最近公共祖先的定义为：对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
 * 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
 * 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
 *
 * 示例 1:
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * 输出: 3
 * 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
 *
 * 示例 2:
 * 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * 输出: 5
 * 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
 *
 * 说明:
 * 所有节点的值都是唯一的。
 * p、q 为不同节点且均存在于给定的二叉树中。
 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

// Find two paths
// Time Complexity: O(3n)
// Space Complexity: O(2n)

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> path1;
        dfs(root, p, path1);

        vector<TreeNode*> path2;
        dfs(root, q, path2);

        TreeNode* res;
        for (int i = 0; i < path1.size() && i < path2.size(); i ++)
            if (path1[i] == path2[i])
                res = path1[i];
            else
                break;
        return res;
    }

private:
    bool dfs(TreeNode* node, TreeNode* target, vector<TreeNode*>& path) {

        if(!node) return false;

        path.push_back(node);
        if (node == target) return true;

        if (dfs(node->left, target, path)) return true;
        if (dfs(node->right, target, path)) return true;

        path.pop_back();
        return false;
    }
};


// Recursion implementation
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution1 {
public:
    // 在root中寻找p和q
    // 如果p和q都在root所在的二叉树中, 则返回LCA
    // 如果p和q只有一个在root所在的二叉树中, 则返回p或者q
    // 如果p和q均不在root所在的二叉树中, 则返回NULL
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == nullptr)
            return root;

        if (root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
            return root;

        if (left != nullptr)
            return left;

        if (right != nullptr)
            return right;

        return nullptr;
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || p == root || q == root) {
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        return l == nullptr ? r : (r == nullptr ? l : root);
    }
};

// Another Recursion implementation
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution3 {

private:
    TreeNode* ret = nullptr;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        assert(ret);
        return ret;
    }

private:
    // 在root中寻找p和q, 如果包含则返回 true
    // 否则返回false
    //
    // root是p或者q；root的左子树包含p或q；root的右子树包含p或q；三个条件有两个满足
    // 则 ret = root
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(!root)
            return false;

        bool mid = false;
        if (root == p || root == q)
            mid = true;

        bool left = dfs(root->left, p, q);
        bool right = dfs(root->right, p, q);

        if (mid + left + right >= 2)
            ret = root;

        return mid + left + right;
    }
};

