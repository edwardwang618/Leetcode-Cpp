/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *cur = head;
        while (cur) {
            len++;
            cur = cur->next;
        }

        if (!len) return head;
        k %= len;

        if (!k) return head;

        ListNode *dummy = new ListNode(0), *slow = dummy, *fast = dummy;
        dummy->next = head;
        for (int i = 0; i < k; i++) fast = fast->next;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode *res = slow->next;
        slow->next = nullptr;
        fast->next = head;

        return res;
    }
};
// @lc code=end

