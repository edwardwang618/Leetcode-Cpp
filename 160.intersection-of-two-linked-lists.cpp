/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0, len2 = 0;
        ListNode *l1 = headA, *l2 = headB;
        while (l1) {
            l1 = l1->next;
            len1++;
        }
        while (l2) {
            l2 = l2->next;
            len2++;
        }
        if (len1 < len2) {
            swap(headA, headB);
            swap(len1, len2);
        }
        
        while (len1 > len2) {
            headA = headA->next;
            len1--;
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};
// @lc code=end

