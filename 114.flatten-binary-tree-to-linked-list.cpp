/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        while (root) {
            if (root->left) {
                TreeNode *left = root->left;
                while (left->right) left = left->right;
                left->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }

            root = root->right;
        }
    }

    // void flatten(TreeNode* root) {
    //     dfs(root);
    // }

    // // 返回的是flatten root完事后的链表尾结点
    // TreeNode* dfs(TreeNode* root) {
    //     if (!root) return nullptr;

    //     TreeNode *left = root->left, *right = root->right;
    //     TreeNode *left_tail = dfs(left), *right_tail = dfs(right);

    //     root->right = left;
    //     root->left = nullptr;
        
    //     if (!left_tail) root->right = right;
    //     else left_tail->right = right;

    //     if (right_tail) return right_tail;
    //     if (left_tail) return left_tail;
    //     return root;
    // }
};
// @lc code=end

