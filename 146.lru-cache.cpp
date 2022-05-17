/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    // HashMap<key, ListNode{key, value}>
    // head   ->2->3->1->4   ->tail
    struct ListNode {
        int key, value;
        ListNode *prev, *next;
        ListNode(int key, int value) {
            this->key = key;
            this->value = value;
            prev = next = nullptr;
        }
    };
    ListNode *head, *tail;
    unordered_map<int, ListNode*> map;
    int capacity;

    void move_to_head(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = head->next;
        head->next->prev = node;

        node->prev = head;
        head->next = node;
    }

    void remove_tail() {
        ListNode* node = tail->prev;
        node->next->prev = node->prev;
        node->prev->next = node->next;
        map.erase(node->key);
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode(0, 0);
        tail = new ListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!map.count(key)) return -1;
        auto node = map[key];
        int res = node->value;
        move_to_head(node);
        return res;
    }
    
    void put(int key, int value) {
        if (!map.count(key)) {
            ListNode* node = new ListNode(key, value);
            node->next = head->next;
            head->next->prev = node;
            node->prev = head;
            head->next = node;

            map[key] = node;
            if (map.size() > capacity) {
                remove_tail();
            }
        } else {
            ListNode* node = map[key];
            node->value = value;
            move_to_head(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

