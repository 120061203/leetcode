/*
 * 153. Find Minimum in Rotated Sorted Array
 * Difficulty: Medium
 * Tags: Array, Binary Search
 *
 * Description:
 * Given the sorted rotated array nums of unique elements, return the
 * minimum element of this array. Must run in O(log n).
 *
 * Constraints:
 * - n == nums.length
 * 1 <= n <= 5000
 * -5000 <= nums[i] <= 5000
 * All the integers of nums are unique.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {3,4,5,1,2};
    cout << sol.findMin(n1) << "\n"; // 1
    vector<int> n2 = {4,5,6,7,0,1,2};
    cout << sol.findMin(n2) << "\n"; // 0

    return 0;
}
