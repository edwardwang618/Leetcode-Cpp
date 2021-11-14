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
        ListNode *dummy = new ListNode(0);
        //  a0 -> a1 = left ->... ->ak = right ->akp1
        dummy->next = head;
        ListNode *a0, *a1, *ak, *akp1;
        a0 = a1 = dummy;
        for (int i = 0; i < left - 1; i++) a0 = a0->next;
        a1 = a0->next;
        ak = a1;
        for (int i = 0; i < right - left; i++) ak = ak->next;
        akp1 = ak->next;

        ak->next = nullptr;
        a0->next = reverse(a1);
        a1->next = akp1;

        return dummy->next;
    }

    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *tmp;
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

