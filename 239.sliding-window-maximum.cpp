/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n - k + 1, 0);
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            if (dq.size() && dq.front() <= i - k) dq.pop_front();
            while (dq.size() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res[i - k + 1] = nums[dq.front()];
        }

        return res;
    }
};
// @lc code=end

