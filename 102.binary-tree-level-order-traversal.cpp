/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *cur, int depth, vector<vector<int>> &res) {
        if (!cur) return;
        if (depth >= res.size()) res.push_back({});
        res[depth].push_back(cur->val);
        dfs(cur->left, depth + 1, res);
        dfs(cur->right, depth + 1, res);
    }
};
// @lc code=end

