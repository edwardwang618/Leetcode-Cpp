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
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if (!root) return nullptr;
    //     if (key < root->val) root->left = deleteNode(root->left, key);
    //     else if (key > root->val) root->right = deleteNode(root->right, key);
    //     else {
    //         if (!root->left) return root->right;
    //         else if (!root->right) return root->left;

    //         TreeNode *left = root->left;
    //         if (!left->right) {
    //             root->val = left->val;
    //             root->left = left->left;
    //         } else {
    //             TreeNode *front = left->right;
    //             while (front->right) {
    //                 front = front->right;
    //                 left = left->right;
    //             }

    //             root->val = front->val;
    //             left->right = front->left;
    //         }
    //     }

    //     return root;
    // }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (key < root->val) root->left = deleteNode(root->left, key);
        else if (key > root->val) root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) return nullptr;
            if (root->left) {
                root = zig(root);
                root->right = deleteNode(root->right, key);
            } else {
                root = zag(root);
                root->left = deleteNode(root->left, key);
            }
        }

        return root;
    }

    // 对root进行右旋，返回新的树根
    TreeNode* zig(TreeNode *root) {
        TreeNode *left = root->left;
        root->left = left->right;
        left->right = root;
        return left;
    }

    TreeNode* zag(TreeNode *root) {
        TreeNode *right = root->right;
        root->right = right->left;
        right->left = root;
        return right;
    }
};
// @lc code=end

