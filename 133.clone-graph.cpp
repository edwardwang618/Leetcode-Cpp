/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp = {{nullptr, nullptr}};
        return dfs(node, mp);
    }

    Node* dfs(Node* cur, unordered_map<Node*, Node*> &mp) {
        if (mp.count(cur)) return mp[cur];
        mp[cur] = new Node(cur->val);
        for (auto &x : cur->neighbors)
            mp[cur]->neighbors.push_back(dfs(x, mp));
        
        return mp[cur];
    }
};
// @lc code=end

