/*
 * @lc app=leetcode id=450 lang=cpp
 *
 * [450] Delete Node in a BST
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            else {
                TreeNode *left = root->left;
                if (!left->right) {
                    root->val = left->val;
                    root->left = left->left;
                } else {
                    TreeNode *prev = left; 
                    left = left->right;
                    while (left->right) {
                        left = left->right;
                        prev = prev->right;
                    }
                    root->val = left->val;
                    prev->right = left->left;
                }
            }
        }

        return root;
    }
};
// @lc code=end

