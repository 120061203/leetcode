/*
 * 3691. Maximum Total Subarray Value II
 * Difficulty: Hard
 *
 * 描述：
 * 給定整數陣列 nums 和整數 k，從所有子陣列中選恰好 k 個不同（l,r 對不重複）的子陣列，
 * 最大化所有子陣列的「值」總和，其中子陣列的值 = max - min。
 *
 * 核心想法：
 * 二分搜尋第 k 大的子陣列值 m，再用滑動視窗計算「值 < x 的子陣列數量與總和」。
 * 答案 = sum(值 > m 的子陣列) + m × (k - count(值 > m 的子陣列))
 *
 * 滑動視窗維護：用兩個 (值, count) 的單調陣列追蹤當前視窗的 max/min 加權總和，
 * 當 max - min >= x 時從左縮窗，讓視窗內只保留值 < x 的子陣列。
 *
 * 時間複雜度：O(n log V)，V = max(nums) - min(nums)
 *
 * Example 1: nums=[1,3,2], k=2 → 4
 * Example 2: nums=[4,2,5,1], k=3 → 12
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    // 回傳「值 < x 的子陣列」的數量與總和
    // 用平面陣列模擬單調雙端佇列，避免 deque 的堆積分配開銷
    void countLess(vector<int>& nums, long long x, long long& cnt, long long& sum) {
        int n = nums.size();
        cnt = 0; sum = 0;

        // maxVal/maxCnt: 遞減單調陣列，追蹤各 l 的最大值
        // minVal/minCnt: 遞增單調陣列，追蹤各 l 的最小值
        // 每個 slot (val, c) 代表有 c 個 l 值以 val 為其 max/min
        static int maxVal[50001], minVal[50001];
        static long long maxCnt[50001], minCnt[50001];
        int maxHead = 0, maxTail = 0;
        int minHead = 0, minTail = 0;
        long long maxSum = 0, minSum = 0; // 當前視窗的 max/min 加權總和
        int left = 0;

        for (int r = 0; r < n; r++) {
            int v = nums[r];

            // 加入 max 陣列：從尾端彈出所有 <= v 的元素（它們的 max 由 v 取代）
            long long mc = 1;
            while (maxHead < maxTail && maxVal[maxTail - 1] <= v) {
                --maxTail;
                maxSum -= (long long)maxVal[maxTail] * maxCnt[maxTail];
                mc += maxCnt[maxTail];
            }
            maxVal[maxTail] = v; maxCnt[maxTail] = mc;
            maxSum += (long long)v * mc;
            ++maxTail;

            // 加入 min 陣列：從尾端彈出所有 >= v 的元素
            long long nc = 1;
            while (minHead < minTail && minVal[minTail - 1] >= v) {
                --minTail;
                minSum -= (long long)minVal[minTail] * minCnt[minTail];
                nc += minCnt[minTail];
            }
            minVal[minTail] = v; minCnt[minTail] = nc;
            minSum += (long long)v * nc;
            ++minTail;

            // 從左縮窗，直到視窗內 max - min < x
            while (maxHead < maxTail && minHead < minTail &&
                   (long long)maxVal[maxHead] - minVal[minHead] >= x) {
                maxSum -= maxVal[maxHead];
                if (--maxCnt[maxHead] == 0) ++maxHead;

                minSum -= minVal[minHead];
                if (--minCnt[minHead] == 0) ++minHead;

                ++left;
            }

            // 視窗 [left..r] 內所有子陣列的值均 < x
            cnt += r - left + 1;
            sum += maxSum - minSum;
        }
    }

public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long total = (long long)n * (n + 1) / 2;

        // 所有子陣列的值總和（x 超大，視窗不縮）
        long long total_sum, dummy;
        countLess(nums, (long long)2e9 + 1, dummy, total_sum);

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        // 二分搜尋最大的 m，使得「值 >= m 的子陣列數」>= k
        // 等價於 countLess(m) <= total - k
        long long lo = 0, hi = mx - mn;
        while (lo < hi) {
            long long mid = lo + (hi - lo + 1) / 2;
            long long cnt, s;
            countLess(nums, mid, cnt, s);
            if (total - cnt >= k) lo = mid; // 值 >= mid 的子陣列夠多，可以更大
            else hi = mid - 1;
        }

        long long m = lo; // 第 k 大的子陣列值

        // 計算值嚴格 > m 的子陣列數量與總和
        long long cnt_le, sum_le;
        countLess(nums, m + 1, cnt_le, sum_le);
        long long count_above = total - cnt_le;
        long long sum_above = total_sum - sum_le;

        // 不足 k 個的部分用值 = m 的子陣列補滿
        return sum_above + m * (k - count_above);
    }
};

int main() {
    Solution sol;

    // Example 1: expected 4
    vector<int> nums1 = {1, 3, 2};
    cout << sol.maxTotalValue(nums1, 2) << "\n"; // 4

    // Example 2: expected 12
    vector<int> nums2 = {4, 2, 5, 1};
    cout << sol.maxTotalValue(nums2, 3) << "\n"; // 12

    // 全部相等，值都是 0
    vector<int> nums3 = {5, 5, 5};
    cout << sol.maxTotalValue(nums3, 1) << "\n"; // 0

    // 單一元素
    vector<int> nums4 = {7};
    cout << sol.maxTotalValue(nums4, 1) << "\n"; // 0

    return 0;
}
