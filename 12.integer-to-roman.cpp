/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<int> v = vector<int>(4, 0);
        for (int i = 0; i < 4; i++) {
            v[3 - i] = num % 10;
            num /= 10;
        }

        string res;
        if (v[0]) while (v[0]--) res += 'M';

        unordered_map<int, string> mp = {{1, "CDM"}, {2, "XLC"}, {3, "IVX"}};
        for (int i = 1; i <= 3; i++) {
            string s = mp[i];
            int val = v[i];
            if (val == 4) res += s.substr(0, 2);
            else if (val == 9) res += {s[0], s[2]};
            else {
                if (val >= 5) {
                    res += s[1];
                    val -= 5;
                }

                while (val--) res += s[0];
            }
        }

        return res;
    }
};
// @lc code=end

