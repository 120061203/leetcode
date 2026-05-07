/*
 * 57. Insert Interval
 * Difficulty: Medium
 * Tags: Array
 *
 * Description:
 * You are given an array of non-overlapping intervals sorted in ascending
 * order by start point, and a new interval. Insert the interval and
 * merge if necessary.
 *
 * Constraints:
 * - 0 <= intervals.length <= 10^4
 * intervals[i].length == 2
 * 0 <= starti <= endi <= 10^5
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

    }
};

int main() {
    Solution sol;

        vector<vector<int>> iv = {{1,3},{6,9}};
    vector<int> ni = {2,5};
    auto r = sol.insert(iv, ni);
    for(auto& v : r) cout << "[" << v[0] << "," << v[1] << "] ";
    cout << "\n"; // [1,5] [6,9]

    return 0;
}
