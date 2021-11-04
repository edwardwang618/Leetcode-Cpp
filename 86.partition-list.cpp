/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *l1 = new ListNode(0), *prev1 = l1;
        ListNode *l2 = new ListNode(0), *prev2 = l2;

        while (head) {
            if (head->val < x) {
                prev1->next = head;
                prev1 = prev1->next;
            } else {
                prev2->next = head;
                prev2 = prev2->next;
            }

            head = head->next;
        }

        prev2->next = nullptr;
        prev1->next = l2->next;
        return l1->next;
    }
};
// @lc code=end

