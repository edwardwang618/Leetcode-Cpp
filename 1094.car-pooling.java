import java.util.PriorityQueue;

/*
 * @lc app=leetcode id=1094 lang=java
 *
 * [1094] Car Pooling
 */

// @lc code=start
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Arrays.sort(trips, ((x, y) -> Integer.compare(x[1], y[1])));
        PriorityQueue<int[]> minHeap = new PriorityQueue<>((x, y) -> Integer.compare(x[2], y[2]));
        int cnt = 0;
        for (int[] trip : trips) {
            while (!minHeap.isEmpty() && minHeap.peek()[2] <= trip[1]) {
                cnt -= minHeap.poll()[0];
            }

            cnt += trip[0];
            if (cnt > capacity) {
                return false;
            }

            minHeap.offer(trip);
        }

        return true;
    }
}
// @lc code=end

