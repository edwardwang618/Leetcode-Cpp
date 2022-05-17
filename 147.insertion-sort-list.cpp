/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode(0);
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        while (dummy->next) {
            ListNode *prev = dummy, *max_prev;
            int max = -5001;
            while (prev->next) {
                if (prev->next->val > max) {
                    max = prev->next->val;
                    max_prev = prev;
                }
                prev = prev->next;
            }

            ListNode *node = max_prev->next;
            max_prev->next = max_prev->next->next;
            add_to_head(res, node);
        }

        return res->next;
    }

    void add_to_head(ListNode *dummy, ListNode *node) {
        node->next = dummy->next;
        dummy->next = node;
    }
};
// @lc code=end

