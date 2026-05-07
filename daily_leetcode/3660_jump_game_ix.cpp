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
#include <stack>
#include <numeric>
using namespace std;

// 關鍵觀察：
// 右跳 i→j 的條件（j>i, nums[j]<nums[i]）
// 與左跳 j→i 的條件（i<j, nums[i]>nums[j]）是同一件事。
// 因此每條邊都是雙向的，問題等價於：
//   找連通分量，ans[i] = 所在分量的最大值。
//
// 演算法：Union-Find + 單調棧（左到右掃描）
//   - 維護一個「棧頂值 >= 後進元素」的單調不遞減棧
//   - 當 nums[stk.top()] > nums[i]（即 stk.top() < i 且 nums[stk.top()] > nums[i]）
//     → 兩者之間有邊，union 起來並 pop
//   - 最後 ans[i] = 其連通分量的最大值
//
// 時間複雜度：O(n α(n)) ≈ O(n)

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> parent(n), rank_(n, 0);
        iota(parent.begin(), parent.end(), 0);
        vector<int> compMax(nums.begin(), nums.end());

        // 迭代 find + path halving，避免 std::function 和遞迴的 overhead
        auto find = [&](int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]]; // path halving
                x = parent[x];
            }
            return x;
        };

        auto unite = [&](int a, int b) {
            a = find(a); b = find(b);
            if (a == b) return;
            if (rank_[a] < rank_[b]) swap(a, b);
            parent[b] = a;
            if (rank_[a] == rank_[b]) rank_[a]++;
            compMax[a] = max(compMax[a], compMax[b]);
        };

        // Stack 存 (index, 該分量目前的最大值)
        // 比較時用分量最大值，避免 pop 後遺失更大的值
        stack<pair<int,int>> stk;
        for (int i = 0; i < n; i++) {
            int curMax = nums[i];
            // 若棧頂分量最大值 > nums[i]，代表該分量內有某個 j < i 且 nums[j] > nums[i]
            // → 邊存在，合併入同一分量
            while (!stk.empty() && stk.top().second > nums[i]) {
                unite(i, stk.top().first);
                curMax = max(curMax, stk.top().second);
                stk.pop();
            }
            stk.push({i, curMax});
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = compMax[find(i)];
        }
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
