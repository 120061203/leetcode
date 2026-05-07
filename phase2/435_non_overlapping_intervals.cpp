/*
 * 435. Non-Overlapping Intervals
 * Difficulty: Medium
 * Tags: Array, Dynamic Programming, Greedy, Sorting
 *
 * Description:
 * Given an array of intervals, return the minimum number of intervals
 * you need to remove to make the rest of the intervals non-overlapping.
 *
 * Constraints:
 * - 1 <= intervals.length <= 10^5
 * intervals[i].length == 2
 * -5 * 10^4 <= starti < endi <= 5 * 10^4
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> iv1 = {{1,2},{2,3},{3,4},{1,3}};
    cout << sol.eraseOverlapIntervals(iv1) << "\n"; // 1
    vector<vector<int>> iv2 = {{1,2},{1,2},{1,2}};
    cout << sol.eraseOverlapIntervals(iv2) << "\n"; // 2

    return 0;
}
