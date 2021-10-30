/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<pair<Node *, int>> stk;
        Node *cur = root;
        int idx = 0;
        while (stk.size() || cur) {
            if (cur) {
                stk.push({cur, idx});
                while (cur->children.size()) {
                    cur = cur->children[0];
                    stk.push({cur, 0});
                }
            }

            auto p = stk.top(); stk.pop();
            res.push_back(p.first->val);
            cur = p.first;
            idx = p.second;
            if (stk.size() && cur != stk.top().first->children.back()) 
                cur = stk.top().first->children[++idx];
            else cur = nullptr;
        }

        return res;
    }
};
// @lc code=end

