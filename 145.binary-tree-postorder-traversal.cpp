/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> stk;
        stk.push(root);
        while (stk.size()) {
            auto cur = stk.top(); stk.pop();
            while (cur) {
                res.push_back(cur->val);
                if (cur->left) stk.push(cur->left);
                cur = cur->right;
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

