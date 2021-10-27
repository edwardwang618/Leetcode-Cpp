/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string s;
        dfs(root, s, res);
        return res;
    }

    void dfs(TreeNode *cur, string &s, vector<string> &res) {
        if (!cur) return;
        string value = to_string(cur->val);
        s += value;
        if (!cur->left && !cur->right) {
            res.push_back(s);
            s.resize(s.size() - value.size());
            return;
        }

        s += "->";
        if (cur->left) dfs(cur->left, s, res);
        if (cur->right) dfs(cur->right, s, res);
        s.resize(s.size() - 2 - value.size());
    }
};
// @lc code=end

