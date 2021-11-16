/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }

    void dfs(TreeNode *cur, int t, vector<int> &path, vector<vector<int>> &res) {
        if (!cur) return;
        
        path.push_back(cur->val);
        if (!cur->left && !cur->right) {
            if (t == cur->val) res.push_back(path);

            path.pop_back();
            return;
        }

        dfs(cur->left, t - cur->val, path, res);
        dfs(cur->right, t - cur->val, path, res);

        path.pop_back();
    }
};
// @lc code=end

