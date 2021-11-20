/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode *dummy = new ListNode(0), *slow = dummy, *fast = dummy;
        dummy->next = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *l2 = slow->next;
        slow->next = nullptr;
        ListNode *l1 = sortList(dummy->next);
        l2 = sortList(l2);
        ListNode *prev = dummy;
        while (l1 || l2) {
            if (!l1) {
                prev->next = l2;
                break;
            }
            if (!l2) {
                prev->next = l1;
                break;
            }
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        return dummy->next;
    }
};
// @lc code=end

