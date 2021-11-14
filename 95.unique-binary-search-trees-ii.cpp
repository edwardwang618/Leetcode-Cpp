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

    // 返回[l:r]组成的BST的所有方案
    vector<TreeNode *> dfs(int l, int r) {
        if (l > r) return {nullptr};

        vector<TreeNode *> res;
        // 枚举树根
        for (int i = l; i <= r; i++) {
            auto left = dfs(l, i - 1), right = dfs(i + 1, r);
            for (auto le : left) 
                for (auto ri : right) {
                    TreeNode *root = new TreeNode(i);
                    root->left = le;
                    root->right = ri;
                    res.push_back(root);
                }
        }

        return res;
    }
};
// @lc code=end

