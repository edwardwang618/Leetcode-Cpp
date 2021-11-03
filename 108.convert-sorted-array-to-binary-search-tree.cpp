/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }

    TreeNode* dfs(vector<int> &A, int l, int r) {
        if (l > r) return nullptr;
        int mid = l + (r - l >> 1);
        TreeNode *root = new TreeNode(A[mid]);
        root->left = dfs(A, l, mid - 1);
        root->right = dfs(A, mid + 1, r);
        return root;
    }
};
// @lc code=end

