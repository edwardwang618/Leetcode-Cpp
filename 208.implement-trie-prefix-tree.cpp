/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start
class Trie {
public:

    struct Node {
        vector<Node*> ne;
        bool is_word;
        Node() {
            ne = vector<Node*>(26, nullptr);
            is_word = false;
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }
    
    void insert(string s) {
        Node* cur = root;
        for (char ch : s) {
            int u = ch - 'a';
            if (!cur->ne[u]) cur->ne[u] = new Node();
            cur = cur->ne[u];
        }

        cur->is_word = true;
    }
    
    bool search(string s) {
        Node* cur = root;
        for (char ch : s) {
            int u = ch - 'a';
            if (!cur->ne[u]) return false;
            cur = cur->ne[u];
        }

        return cur->is_word;
    }
    
    bool startsWith(string pre) {
        Node* cur = root;
        for (char ch : pre) {
            int u = ch - 'a';
            if (!cur->ne[u]) return false;
            cur = cur->ne[u];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

