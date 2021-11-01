/*
 * @lc app=leetcode id=862 lang=cpp
 *
 * [862] Shortest Subarray with Sum at Least K
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> preSum(n + 1, 0);
        for (int i = 0; i < nums.size(); i++)
            preSum[i + 1] = preSum[i] + nums[i];

        int res = nums.size() + 1;
        deque<int> dq;
        for (int i = 0; i < preSum.size(); i++) {
            // dq.front()不可能作为将来右端点的最优左端点来更新全局最优解
            while (dq.size() && preSum[i] - preSum[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            // dq.back()在此时不能作为将来右端点的最优左端点
            while (dq.size() && preSum[dq.back()] >= preSum[i]) 
                dq.pop_back();

            dq.push_back(i);
        }

        return res == n + 1 ? -1 : res;
    }
};
// @lc code=end

