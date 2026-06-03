/*
 * 4. Median of Two Sorted Arrays
 * Difficulty: Hard
 * Tags: Array, Binary Search, Divide and Conquer
 *
 * Description:
 * Given two sorted arrays nums1 and nums2 of size m and n respectively,
 * return the median of the two sorted arrays. Must run in O(log(m+n)).
 *
 * Constraints:
 * - nums1.length == m
 * nums2.length == n
 * 0 <= m <= 1000
 * 0 <= n <= 1000
 * -10^6 <= nums1[i], nums2[i] <= 10^6
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 確保在較短的陣列上做 binary search，減少搜尋範圍
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        int m = nums1.size(), n = nums2.size();
        int half = (m + n + 1) / 2; // 左半段總共需要幾個元素

        int lo = 0, hi = m;
        while (lo <= hi) {
            int i = (lo + hi) / 2; // nums1 的切割點：左邊取 i 個
            int j = half - i;      // nums2 的切割點：左邊取 j 個

            // 取邊界值，用 INT_MIN/MAX 處理切到邊緣的情況
            int left1  = (i == 0) ? INT_MIN : nums1[i - 1];
            int right1 = (i == m) ? INT_MAX : nums1[i];
            int left2  = (j == 0) ? INT_MIN : nums2[j - 1];
            int right2 = (j == n) ? INT_MAX : nums2[j];

            if (left1 > right2) {
                hi = i - 1; // nums1 切太右，往左移
            } else if (left2 > right1) {
                lo = i + 1; // nums1 切太左，往右移
            } else {
                // 切割正確：左半最大值 ≤ 右半最小值
                int leftMax  = max(left1, left2);
                int rightMin = min(right1, right2);
                if ((m + n) % 2 == 1)
                    return leftMax;          // 奇數：中位數是左半最大值
                else
                    return (leftMax + rightMin) / 2.0; // 偶數：取兩邊界平均
            }
        }
        return 0.0;
    }
};

int main() {
    Solution sol;

        vector<int> n1 = {1,3}, n2 = {2};
    cout << sol.findMedianSortedArrays(n1, n2) << "\n"; // 2.0
    vector<int> n3 = {1,2}, n4 = {3,4};
    cout << sol.findMedianSortedArrays(n3, n4) << "\n"; // 2.5

    return 0;
}
