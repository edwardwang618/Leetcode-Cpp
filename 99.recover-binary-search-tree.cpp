/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        TreeNode *cur = root, *n1 = nullptr, *n2 = nullptr, *prev = nullptr;
        while (cur) {
            if (!cur->left) {
                if (prev && cur->val < prev->val) {
                    if (!n1) n1 = prev;
                    n2 = cur;
                }

                prev = cur;
                cur = cur->right;
                continue;
            }

            TreeNode *left = cur->left;
            while (left->right && left->right != cur) left = left->right;
            if (!left->right) {
                left->right = cur;
                cur = cur->left;
            } else {
                if (prev && cur->val < prev->val) {
                    if (!n1) n1 = prev;
                    n2 = cur;
                }

                prev = cur;
                cur = cur->right;
                left->right = nullptr;
            }
        }

        swap(n1->val, n2->val);
    }
};
// @lc code=end

