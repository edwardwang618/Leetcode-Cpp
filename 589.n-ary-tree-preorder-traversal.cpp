/*
 * @lc app=leetcode id=589 lang=cpp
 *
 * [589] N-ary Tree Preorder Traversal
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node *> stk;
        stk.push(root);
        while (stk.size()) {
            auto cur = stk.top(); stk.pop();
            while (cur) {
                res.push_back(cur->val);
                auto v = cur->children;
                for (int i = v.size() - 1; i >= 1; i--) 
                    stk.push(v[i]);
                
                cur = v.size() ? v[0] : nullptr;
            }
        }

        return res;
    }
};
// @lc code=end

