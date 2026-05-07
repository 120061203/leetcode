/*
 * 56. Merge Intervals
 * Difficulty: Medium
 * Tags: Array, Sorting
 *
 * Description:
 * Given an array of intervals where intervals[i] = [starti, endi], merge
 * all overlapping intervals, and return an array of the non-overlapping
 * intervals that cover all the intervals in the input.
 *
 * Constraints:
 * - 1 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^4
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> iv = {{1,3},{2,6},{8,10},{15,18}};
    auto r = sol.merge(iv);
    for(auto& v : r) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << "\n"; // [1,6] [8,10] [15,18]

    return 0;
}
