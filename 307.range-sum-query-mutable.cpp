/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

// @lc code=start
class NumArray {
public:

    struct Node {
        int l, r;
        int sum;
    };

    vector<Node> tr;

    void pushup(int u) {
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    }

    void build(int u, int l, int r, vector<int> &A) {
        tr[u] = {l, r};
        if (l == r) {
            tr[u].sum = A[l - 1];
            return;
        }

        int mid = l + r >> 1;
        build(u << 1, l, mid, A);
        build(u << 1 | 1, mid + 1, r, A);
        pushup(u);
    }

    int query(int u, int l, int r) {
        if (l <= tr[u].l && tr[u].r <= r) return tr[u].sum;

        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        if (l > mid) return query(u << 1 | 1, l, r);
        return query(u << 1, l, r) + query(u << 1 | 1, l, r);
    }

    void update(int u, int i, int x) {
        if (tr[u].l == tr[u].r) {
            tr[u].sum = x;
            return;
        }

        int mid = tr[u].l + tr[u].r >> 1;
        if (i <= mid) update(u << 1, i, x);
        else update(u << 1 | 1, i, x);

        pushup(u);
    }

    NumArray(vector<int>& nums) {
        int n = nums.size();
        tr.resize(n << 2);
        build(1, 1, n, nums);
    }
    
    void update(int i, int x) {
        i++;
        update(1, i, x);
    }
    
    int sumRange(int left, int right) {
        left++;
        right++;
        return query(1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

