/*
 * @lc app=leetcode id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
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
    // TreeNode* insertIntoBST(TreeNode* root, int val) {
    //     if (!root) return new TreeNode(val);
    //     if (val < root->val) root->left = insertIntoBST(root->left, val);
    //     else if (val > root->val) root->right = insertIntoBST(root->right, val);
        
    //     return root;
    // }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode *cur = root;
        while (cur) {
            if (val < cur->val) {
                if (!cur->left) cur->left = new TreeNode(val);
                cur = cur->left;
            } else if (val > cur->val) {
                if (!cur->right) cur->right = new TreeNode(val);
                cur = cur->right;
            } else break;
        }
        
        return root;
    }
};
// @lc code=end
