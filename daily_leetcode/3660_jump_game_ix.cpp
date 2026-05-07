/*
 * 3660. Jump Game IX
 * Difficulty: Medium
 * Tags: Array, Greedy, Monotonic Stack
 *
 * Description:
 * You are given an integer array nums.
 * From any index i, you can jump to another index j under the following rules:
 *   - Jump to index j where j > i is allowed only if nums[j] < nums[i].
 *   - Jump to index j where j < i is allowed only if nums[j] > nums[i].
 *
 * For each index i, find the maximum value in nums that can be reached by
 * following any sequence of valid jumps starting at i.
 *
 * Return an array ans where ans[i] is the maximum value reachable starting
 * from index i.
 *
 * Example 1:
 * Input:  nums = [2,1,3]
 * Output: [2,2,3]
 * - i=0: No jump increases the value → ans[0] = 2
 * - i=1: Jump to j=0 (nums[0]=2 > nums[1]=1) → ans[1] = 2
 * - i=2: nums[2]=3 is the max → ans[2] = 3
 *
 * Example 2:
 * Input:  nums = [2,3,1]
 * Output: [3,3,3]
 * - i=0: Jump to j=2 (nums[2]=1 < nums[0]=2), then j=1 (nums[1]=3 > nums[2]=1) → ans[0] = 3
 * - i=1: nums[1]=3 is the max → ans[1] = 3
 * - i=2: Jump to j=1 (nums[1]=3 > nums[2]=1) → ans[2] = 3
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - 1 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// 關鍵觀察：
// 右跳 i→j 的條件（j>i, nums[j]<nums[i]）
// 與左跳 j→i 的條件（i<j, nums[i]>nums[j]）是同一件事。
// 因此每條邊都是雙向的，問題等價於：
//   找連通分量，ans[i] = 所在分量的最大值。
//
// 演算法：前綴最大值 + Divide & Conquer
//
// prevMax[i] = [0..i] 的最大值及其最左 index（= pivot）
// process(r, rightMin, rightMax):
//   - [pivotIndex..r] 內所有元素皆與 pivot 相連（值 <= pMax，可直接左跳到 pivot）
//     → 它們在同一連通分量，答案相同
//   - 若 pMax > rightMin：pivot 能右跳，與右側相連 → currMax = rightMax
//     否則：與右側無連接             → currMax = pMax
//   - 遞迴處理 [0..pivotIndex-1]，更新 rightMin（加入本段元素）
//
// 時間複雜度：O(n)，每個元素只被處理一次

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);

        // prevMax[i] = {[0..i] 的最大值, 其最左 index}
        using Item = pair<int, int>;
        vector<Item> prevMax(n);
        Item prev = {INT_MIN, -1};
        for (int i = 0; i < n; ++i) {
            if (nums[i] > prev.first) prev = {nums[i], i};
            prevMax[i] = prev;
        }

        auto process = [&](auto& self, int r, int rightMin, int rightMax) -> void {
            auto [pMax, pivotIndex] = prevMax[r];

            // pMax > rightMin：pivot 能右跳，整段連到右側；否則答案就是 pMax
            int currMax = pMax <= rightMin ? pMax : rightMax;

            int nextRightMin = min(pMax, rightMin);
            for (int i = pivotIndex; i <= r; ++i) {
                ans[i] = currMax;
                nextRightMin = min(nextRightMin, nums[i]);
            }

            if (pivotIndex == 0) return;
            self(self, pivotIndex - 1, nextRightMin, currMax);
        };

        process(process, n - 1, INT_MAX, 0);
        return ans;
    }
};

int main() {
    Solution sol;

    // Input: nums = [2,1,3]
    // Output: [2,2,3]
    vector<int> nums1 = {2, 1, 3};
    auto res1 = sol.maxValue(nums1);
    for (int x : res1) cout << x << " ";
    cout << "\n";

    // Input: nums = [2,3,1]
    // Output: [3,3,3]
    vector<int> nums2 = {2, 3, 1};
    auto res2 = sol.maxValue(nums2);
    for (int x : res2) cout << x << " ";
    cout << "\n";

    // Input: nums = [13,4,11]
    // Output: [13,13,13]
    vector<int> nums3 = {13, 4, 11};
    auto res3 = sol.maxValue(nums3);
    for (int x : res3) cout << x << " ";
    cout << "\n";

    return 0;
}
