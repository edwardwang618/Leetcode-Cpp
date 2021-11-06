/*
 * @lc app=leetcode id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode(0), *prev = dummy;
        dummy->next = head;
        // prev->a1->...->an->anp1
        for (int i = 0; i < left - 1; i++) prev = prev->next;
        ListNode *an = prev, *a1 = prev->next;
        for (int i = 0; i < right - left + 1; i++) an = an->next;
        ListNode *anp1 = an->next;
        an->next = nullptr;
        prev->next = reverse(prev->next);
        a1->next = anp1;

        return dummy->next;
    }

    ListNode* reverse(ListNode *head) {
        ListNode *prev, *tmp;
        while (head) {
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }
};
// @lc code=end

