/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *dummy = new ListNode(0), *prev = dummy;
    int t = 0;
    while (l1 || l2 || t) {
      if (l1) t += l1->val, l1 = l1->next;
      if (l2) t += l2->val, l2 = l2->next;
      prev->next = new ListNode(t % 10);
      prev = prev->next;
      t /= 10;
    }

    return dummy->next;
  }
};
// @lc code=end
