/*
 * @lc app=leetcode id=1146 lang=cpp
 *
 * [1146] Snapshot Array
 */

// @lc code=start
class SnapshotArray {
 public:
  #define x first
  #define y second
  vector<vector<pair<int, int>>> vs;
  int snap_id;

  SnapshotArray(int length) {
    snap_id = 0;
    vs.resize(length, {{-1, 0}});
  }

  void set(int index, int val) {
    auto &v = vs[index];
    if (v.back().x == snap_id) v.back().y = val;
    else v.push_back({snap_id, val});
  }

  int snap() {
    return snap_id++;
  }

  int get(int index, int snap_id) {
    auto &v = vs[index];
    int l = 0, r = v.size() - 1;
    while (l < r) {
      int mid = l + (r - l + 1 >> 1);
      if (v[mid].x <= snap_id) l = mid;
      else r = mid - 1;
    }

    return v[l].y;
  }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
// @lc code=end
