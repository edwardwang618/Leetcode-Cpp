/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
         return dfs(lists, 0, lists.size() - 1);
    }

    // 返回的是合并lists[l : r]的头结点
    ListNode* dfs(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return lists[l];

        int mid = l + (r - l >> 1);
        ListNode *l1 = dfs(lists, l, mid), *l2 = dfs(lists, mid + 1, r);
        ListNode *dummy = new ListNode(0), *prev = dummy;
        while (l1 || l2) {
            if (!l2) {
                prev->next = l1;
                break;
            }
            if (!l1) {
                prev->next = l2;
                break;
            }
            if (l1->val <= l2->val) prev->next = l1, l1 = l1->next;
            else prev->next = l2, l2 = l2->next;

            prev = prev->next;
        }

        return dummy->next;
    }
};
// @lc code=end

