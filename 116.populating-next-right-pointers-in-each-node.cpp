/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (root) q.push(root);
        
        while (q.size()) {
            Node* last = nullptr;
            for (int i = q.size(); i; i--) {
                Node* cur = q.front(); q.pop();
                if (last) last->next = cur;

                last = cur;
                cur->next = nullptr;

                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }

        return root;
    }
};
// @lc code=end
