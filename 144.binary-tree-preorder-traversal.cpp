/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode *> stk;
    //     stk.push(root);
    //     while (stk.size()) {
    //         auto cur = stk.top(); stk.pop();
    //         while (cur) {
    //             res.push_back(cur->val);
    //             if (cur->right) stk.push(cur->right);
    //             cur = cur->left;
    //         }
    //     }

    //     return res;
    // }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur) {
            if (!cur->left) {
                res.push_back(cur->val);
                cur = cur->right;
                continue;
            }

            TreeNode *left = cur->left;
            while (left->right && left->right != cur) left = left->right;
            if (!left->right) {
                res.push_back(cur->val);
                left->right = cur;
                cur = cur->left;
            } else {
                left->right = nullptr;
                cur = cur->right;
            }
        }

        return res;
    }
};
// @lc code=end

