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
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     stack<TreeNode *> stk;
    //     TreeNode *cur = root;
    //     while (stk.size() || cur) {
    //         while (cur) {
    //             stk.push(cur);
    //             if (cur->left) cur = cur->left;
    //             else cur = cur->right;
    //         }

    //         cur = stk.top(); stk.pop();
    //         res.push_back(cur->val);
    //         if (stk.size() && stk.top()->left == cur) cur = stk.top()->right;
    //         else cur = nullptr;
    //     }
        
    //     return res;
    // }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur) {
            if (!cur->left) {
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
                reverse_add(cur->left, res);
                cur = cur->right;
            }
        }

        reverse_add(root, res);

        return res;
    }

    void reverse_add(TreeNode *cur, vector<int> &res) {
        TreeNode *tail = reverse(cur);
        cur = tail;
        while (tail) {
            res.push_back(tail->val);
            tail = tail->right;
        }

        reverse(cur);
    }

    TreeNode* reverse(TreeNode *cur) {
        TreeNode *prev = nullptr, *tmp = nullptr;
        while (cur) {
            tmp = cur->right;
            cur->right = prev;
            prev = cur;
            cur = tmp;
        }

        return prev;
    }
};
// @lc code=end

