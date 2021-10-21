/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    // pull model
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> f(n, 0x3f3f3f3f);
    //     // f[i]是从i向后跳多少步能到n - 1
    //     // f[k] = 1 + min(f[k + 1], ..., f[k + nums[k]])
    //     f[n - 1] = 0;
    //     for (int i = n - 2; i >= 0; i--)
    //         for (int s = 1; s <= nums[i] && i + s < n; s++)
    //             f[i] = min(f[i], 1 + f[i + s]);

    //     return f[0];
    // }

    // push model
    // int jump(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> f(n, 0x3f3f3f3f);
    //     // f[i]是从0到i至少要跳多少步
    //     // push model
    //     f[0] = 0;

    //     // f[i]能更新f[i + 1], ..., f[i + nums[i]]
    //     // 跳f[i]次能到i，跳f[i] + 1次就能到f[i + 1], ..., f[i + nums[i]]
    //     for (int i = 0; i < n - 1; i++)
    //         // j是步长
    //         for (int j = 1; j <= nums[i] && i + j < n; j++)
    //             f[i + j] = min(f[i + j], f[i] + 1);

    //     return f[n - 1];
    // }

    int jump(vector<int>& nums) {
        // 可以证明，跳k步能跳到的位置组成的集合是个闭区间
        int n = nums.size();
        if (n <= 1) return 0;

        // [l, r]是跳res步能到的位置的区间
        int l = 0, r = 0, res = 0;
        while (l <= r) {
            res++;
            int far = l;
            for (int i = l; i <= r; i++) {
                far = max(far, i + nums[i]);
                if (far >= n - 1) return res;
            }

            l = r + 1;
            r = far;
        } 

        return -1;
    }
};
// @lc code=end

