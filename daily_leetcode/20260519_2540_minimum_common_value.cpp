/*
 * 2540. Minimum Common Value
 * Difficulty: Easy
 *
 * Description:
 * Given two integer arrays nums1 and nums2, sorted in non-decreasing order,
 * return the minimum integer common to both arrays. If there is no common
 * integer, return -1.
 *
 * Example 1: nums1 = [1,2,3], nums2 = [2,4] → 2
 * Example 2: nums1 = [1,2,3,6], nums2 = [2,3,4,5] → 2
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;

        // Two pointers: advance the smaller pointer to find a match
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) return nums1[i]; // found common element
            else if (nums1[i] < nums2[j]) i++;          // nums1 is behind, advance it
            else j++;                                    // nums2 is behind, advance it
        }

        return -1; // no common element
    }
};

int main() {
    Solution sol;

    vector<int> a1 = {1,2,3}, b1 = {2,4};
    cout << sol.getCommon(a1, b1) << "\n"; // 2

    vector<int> a2 = {1,2,3,6}, b2 = {2,3,4,5};
    cout << sol.getCommon(a2, b2) << "\n"; // 2

    vector<int> a3 = {1,3,5}, b3 = {2,4,6};
    cout << sol.getCommon(a3, b3) << "\n"; // -1

    return 0;
}
