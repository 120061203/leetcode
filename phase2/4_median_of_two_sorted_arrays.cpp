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
