/*
 * 287. Find the Duplicate Number
 * Difficulty: Medium
 * Tags: Array, Two Pointers, Binary Search
 *
 * Description:
 * Given an array of integers nums containing n+1 integers where each
 * integer is in the range [1, n], there is only one repeated number.
 * Return this repeated number without modifying the array, using O(1) space.
 *
 * Constraints:
 * - 1 <= n <= 10^5
 * nums.length == n + 1
 * 1 <= nums[i] <= n
 * All integers in nums appear only once except for precisely one integer.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {1,3,4,2,2};
    cout << sol.findDuplicate(n1) << "\n"; // 2
    vector<int> n2 = {3,1,3,4,2};
    cout << sol.findDuplicate(n2) << "\n"; // 3

    return 0;
}
