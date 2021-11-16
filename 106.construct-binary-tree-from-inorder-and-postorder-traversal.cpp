/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[inorder[i]] = i;
        return dfs(postorder, 0, n - 1, inorder, 0, n - 1, mp);
    }

    TreeNode* dfs(vector<int>& postorder, int pl, int pr, vector<int>& inorder, int il, int ir, unordered_map<int, int> &mp) {
        if (pl > pr) return nullptr;
        if (pl == pr) return new TreeNode(postorder[pl]);

        TreeNode* root = new TreeNode(postorder[pr]);
        int idx = mp[root->val], sz = idx - il;
        root->left = dfs(postorder, pl, pl + sz - 1, inorder, il, idx - 1, mp);
        root->right = dfs(postorder, pl + sz, pr - 1, inorder, idx + 1, ir, mp);
        return root;
    }
};
// @lc code=end

