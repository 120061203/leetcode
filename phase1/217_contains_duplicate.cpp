/*
 * 217. Contains Duplicate
 * Difficulty: Easy
 * Tags: Array, Hash Table, Sorting
 *
 * Description:
 * Given an integer array nums, return true if any value appears at least
 * twice in the array, and return false if every element is distinct.
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * - -10^9 <= nums[i] <= 10^9
 */

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

    // Input: nums = [1,2,3,1]
    // Output: true
    vector<int> nums1 = {1, 2, 3, 1};
    cout << sol.containsDuplicate(nums1) << "\n";

    // Input: nums = [1,2,3,4]
    // Output: false
    vector<int> nums2 = {1, 2, 3, 4};
    cout << sol.containsDuplicate(nums2) << "\n";

    return 0;
}
