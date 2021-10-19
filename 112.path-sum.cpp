/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, targetSum);
    }

    // 从root出发是否能找到和为t的路径
    bool dfs(TreeNode *root, int t) {
        if (!root) return false;
        
        if (!root->left && !root->right) return root->val == t;
        bool l = root->left && dfs(root->left, t - root->val);
        if (l) return true;
        bool r = root->right && dfs(root->right, t - root->val);
        return r;
    }
};
// @lc code=end

