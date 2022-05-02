/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // city  0  1  2
        // gas   2  3  4
        // cost  3  4  3
        for (int i = 0; i < n; ) {
            int oil = 0;
            int step;
            for (step = 1; step <= n; step++) {
                int next = (i + step) % n;
                oil += gas[(i + step - 1) % n] - cost[(i + step - 1) % n];
                if (oil < 0) {
                    break;
                }
            }

            if (step == n + 1) return i;
            i += step;
        }
        
        return -1;
    }
};
// @lc code=end
