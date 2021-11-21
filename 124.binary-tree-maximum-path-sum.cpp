/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        // x是节点，f[x]是从x向下的最大和，
        // res = max_x (f[x.l] + f[x.r] + x)
        // f[x.l] + f[x.r] + x的真实定义是，如果x.l和x.r都不空，f[x.l] + f[x.r] + x
        // 如果x.l不空，x.r空，那就是x + f[x.l];
        // .................     x+ f[x.r];
        // ...................    x

        int res = INT_MIN;
        dfs(root, res);
        return res;
    }

    // 返回的是从root向下能走出来的最大路径和
    int dfs(TreeNode *root, int &res) {
        if (!root) return 0;
        int l = max(0, dfs(root->left, res)), r = max(0, dfs(root->right, res));
        res = max(res, l + r + root->val);
        return root->val + max(l, r);
    }
};
// @lc code=end

