/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string ss, sr;
        dfs(root, ss);
        ss = "," + ss;
        dfs(subRoot, sr);
        sr = "," + sr;
        return kmp(ss, sr);
    }

    bool kmp(const string &s, const string &p) {
        auto ne = builNe(p);
        for (int i = 0, j = 0; i < s.size(); ) {
            if (j == -1 || s[i] == p[j]) i++, j++;
            else j = ne[j];

            if (j == p.size()) return true;
        }

        return false;
    }

    vector<int> builNe(const string &p) {
        int m = p.size();
        vector<int> ne = vector<int>(m, 0);
        for (int i = 0, j = ne[0] = -1; i < m - 1; ) 
            if (j == -1 || p[i] == p[j]) {
                i++;
                j++;
                ne[i] = p[i] != p[j] ? j : ne[j];
            } else j = ne[j];

        return ne;
    }

    // 遍历root为根的子树并且把其先序遍历append到s里
    // 假设一棵树的先序遍历规定其格式为 v,v,v,..,v
    void dfs(TreeNode *root, string &s) {
        if (!root) {
            s += "#";
            return;
        }

        s += to_string(root->val) + ",";
        dfs(root->left, s);
        s += ',';
        dfs(root->right, s);
    }
};
// @lc code=end