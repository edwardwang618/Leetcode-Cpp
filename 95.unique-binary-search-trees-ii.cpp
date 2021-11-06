/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
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
    vector<TreeNode*> generateTrees(int n) {
        return dfs(1, n);
    }

    vector<TreeNode *> dfs(int l, int r) {
        if (l > r) return {nullptr};
        vector<TreeNode *> res;
        for (int i = l; i <= r; i++) {
            for (auto &x : dfs(l, i - 1))
                for (auto &y : dfs(i + 1, r)) {
                    TreeNode *root = new TreeNode(i);
                    root->left = x;
                    root->right = y;
                    res.push_back(root);
                }
        }

        return res;
    }
};
// @lc code=end

