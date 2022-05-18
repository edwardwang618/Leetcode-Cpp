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

// [4, 2, 1] -> [2, 4, 1] -> [2, 4, 1]
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        for (int k = 1; ; k <<= 1) {
            prev = dummy;
            int cnt = 0;
            while (prev->next) {
                cnt++;
                ListNode *slow = prev, *fast = prev;
                for (int i = 0; i < k; i++) {
                    if (slow) slow = slow->next;
                    if (fast && fast->next) fast = fast->next->next;
                }

                if (!slow) break;
                ListNode *l1 = prev->next, *l2 = slow->next, *tail = nullptr;
                slow->next = nullptr;
                if (fast && fast->next) {
                    tail = fast->next;
                    fast->next = nullptr;
                }

                while (l1 || l2) {
                    if (!l1) {
                        prev->next = l2;
                        break;
                    } else if (!l2) {
                        prev->next = l1;
                        break;
                    } else if (l1->val <= l2->val) {
                        prev->next = l1;
                        l1 = l1->next;
                    } else {
                        prev->next = l2;
                        l2 = l2->next;
                    }
                    prev = prev->next;
                }

                while (prev->next) prev = prev->next;
                prev->next = tail;
            }

            if (cnt <= 1) break;
        }

        return dummy->next;
    }
};
// @lc code=end

