/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
            ListNode *cur = head;
            int cnt = 0, x = cur->val;
            while (cur && cur->val == x) {
                cur = cur->next;
                cnt++;
            }

            if (cnt == 1) {
                prev->next = head;
                prev = prev->next;
            }
            
            head = cur;
        } 
        
        prev->next = nullptr;
        return dummy->next;
    }
};
// @lc code=end

