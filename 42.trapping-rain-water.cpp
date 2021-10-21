/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
class Solution {
public:
    // int trap(vector<int>& h) {
    //     int n = h.size();
    //     vector<int> lh(n, 0), rh(n, 0);
    //     lh[0] = h[0];
    //     for (int i = 1; i < n; i++) lh[i] = max(h[i - 1], lh[i - 1]);
    //     rh[n - 1] = h[n - 1];
    //     for (int i = n - 2; i >= 0; i--) rh[i] = max(h[i + 1], rh[i + 1]);

    //     int res = 0;
    //     for (int i = 1; i < n - 1; i++) res += max(min(lh[i], rh[i]) - h[i], 0);
    //     return res;
    // }

    // int trap(vector<int>& h) {
    //     stack<int> stk;
    //     int res = 0;
    //     for (int i = 0; i < h.size(); i++) {
    //         while (stk.size() && h[i] >= h[stk.top()]) {
    //             int t = stk.top(); stk.pop();
    //             if (stk.empty()) continue;
    //             int w = i - stk.top() - 1;
    //             int he = min(h[i], h[stk.top()]) - h[t];
    //             res += max(w * he, 0);
    //         }

    //         stk.push(i);
    //     }

    //     return res;
    // }

    // 竖着切的
    int trap(vector<int>& h) {
        int n = h.size(), res = 0;
        int maxL = h[0], maxR = h[n - 1];
        int l = 1, r = n - 2;
        while (l <= r) {
            if (maxL <= maxR) {
                res += max(0, maxL - h[l]);
                maxL = max(maxL, h[l]);
                l++;
            } else {
                res += max(0, maxR - h[r]);
                maxR = max(maxR, h[r]);
                r--;
            }
        }

        return res;
    }
};
// @lc code=end

