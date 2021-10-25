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
        TreeNode *cur = root;
        while (stk.size() || cur) {
            while (cur) {
                stk.push(cur);
                if (cur->left) cur = cur->left;
                else cur = cur->right;
            }

            cur = stk.top(); stk.pop();
            res.push_back(cur->val);
            if (stk.size() && stk.top()->left == cur) cur = stk.top()->right;
            else cur = nullptr;
        }
        
        return res;
    }
};
// @lc code=end

