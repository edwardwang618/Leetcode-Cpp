/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:

    struct Node {
        Node *left, *right;
        int l, r, h;

        Node(int l, int r, int h) {
            this->l = l;
            this->r = r;
            this->h = h;
            left = right = nullptr;
        }
    };

    Node *root;

    void pushup(Node *u) {
        if (u->left && !u->left->left && !u->right->left && u->left->h == u->right->h) {
            u->h = u->left->h;
            u->left = u->right = nullptr;
        }
    }

    void update(Node *root, int l, int r, int h) {
        if (!root) return;
        if (r < root->l || l > root->r) return;

        if (!root->left && !root->right) {
            if (l <= root->l && root->r <= r) {
                root->h = max(root->h, h);
                return;
            }

            if (l <= root->l) {
                root->left = new Node(root->l, r, root->h);
                root->right = new Node(r + 1, root->r, root->h);
                update(root->left, l, r, h);
            } else {
                root->left = new Node(root->l, l - 1, root->h);
                root->right = new Node(l, root->r, root->h);
                update(root->right, l, r, h);
            }
        } else {
            update(root->left, l, r, h);
            update(root->right, l, r, h);
        }

        pushup(root);
    }

    void dfs(Node *root, vector<vector<int>> &res, int &last) {
        if (!root) return;
        dfs(root->left, res, last);
        if (!root->left && !root->right && last != root->h) {
            res.push_back({root->l, root->h});
            last = root->h;
        }
        dfs(root->right, res, last);
    }

    vector<vector<int>> getSkyline(vector<vector<int>> &bs) {
        root = new Node(0, INT_MAX, 0);
        for (auto &b: bs) update(root, b[0], b[1] - 1, b[2]);

        vector<vector<int>> res;
        int last = 0;
        dfs(root, res, last);
        return res;
    }
};
// @lc code=end

