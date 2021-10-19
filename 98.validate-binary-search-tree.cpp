/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        long last = LONG_MIN;
        return dfs(root, last);
    }

    bool dfs(TreeNode *cur, long &last) {
        if (!cur) return true;
        if (!dfs(cur->left, last) || cur->val <= last) return false;
        last = cur->val;
        return dfs(cur->right, last);
    }
};
// @lc code=end

