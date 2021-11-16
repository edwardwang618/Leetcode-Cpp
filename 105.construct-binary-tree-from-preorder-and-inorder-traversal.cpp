/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) mp[inorder[i]] = i;
        return dfs(preorder, 0, n - 1, inorder, 0, n - 1, mp);
    }

    // 返回以preorder[pl:pr]作为前序遍历和inorder[il:ir]作为中序遍历的二叉树
    TreeNode* dfs(vector<int>& preorder, int pl, int pr, 
                    vector<int>& inorder, int il, int ir,
                    unordered_map<int, int> &mp) {
        if (pl > pr) return nullptr;
        if (pl == pr) return new TreeNode(preorder[pl]);

        TreeNode *root = new TreeNode(preorder[pl]);
        int idx = mp[root->val];
        int sz = idx - il;
        root->left = dfs(preorder, pl + 1, pl + sz, inorder, il, idx - 1, mp);
        root->right = dfs(preorder, pl + sz + 1, pr, inorder, idx + 1, ir, mp);
        return root;
    }
};
// @lc code=end

