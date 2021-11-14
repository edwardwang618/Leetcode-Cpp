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
        // 1, 2, 3, 4, 5
        TreeNode *cur = root, *last = nullptr, *n1 = nullptr, *n2;
        while (cur) {
            if (!cur->left) {
                if (last && last->val > cur->val) {
                    if (!n1) n1 = last;
                    n2 = cur;
                }
                last = cur;
                cur = cur->right;
                continue;
            }

            TreeNode *left = cur->left;
            while (left->right && left->right != cur) left = left->right;
            if (!left->right) {
                left->right = cur;
                cur = cur->left;
            } else {
                left->right = nullptr;
                if (last && last->val > cur->val) {
                    if (!n1) n1 = last;
                    n2 = cur;
                }

                last = cur;
                cur = cur->right;
            }
        }

        swap(n1->val, n2->val);
    }
};
// @lc code=end

