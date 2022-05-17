/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy, *slow = dummy;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* tmp, *prev = nullptr, *cur = slow->next;
        while (cur) {
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        slow->next = nullptr;
        ListNode* l1 = dummy->next, *l2 = prev;
        dummy->next = nullptr;
        
        prev = dummy;
        while (l1 || l2) {
            if (l1) {
                prev->next = l1;
                l1 = l1->next;
                prev = prev->next;
            }
            if (l2) {
                prev->next = l2;
                l2 = l2->next;
                prev = prev->next;
            }
        }

        head = dummy->next;
    }
};
// @lc code=end

