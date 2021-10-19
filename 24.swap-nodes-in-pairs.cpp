/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0), *prev = dummy;
        dummy->next = head;
        while (prev) prev = swap(prev);
        return dummy->next;
    }

    // 是在链表中swap  prev的next和prev的next的next两个节点
    ListNode* swap(ListNode *prev) {
        if (!prev->next || !prev->next->next) return nullptr;
        ListNode *a = prev->next, *b = a->next;
        a->next = b->next;
        prev->next = b;
        b->next = a;
        return a;
    }
};
// @lc code=end

