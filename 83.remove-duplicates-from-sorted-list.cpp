/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0), *prev = dummy;
        while (head) {
            ListNode *tmp = head;
            while (tmp->next && tmp->next->val == head->val) tmp = tmp->next;

            prev->next = head;
            prev = head;

            head = tmp->next;
        }

        prev->next = nullptr;
        return dummy->next;
    }
};
// @lc code=end

