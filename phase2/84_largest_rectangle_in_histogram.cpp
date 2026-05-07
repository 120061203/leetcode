/*
 * 84. Largest Rectangle in Histogram
 * Difficulty: Hard
 * Tags: Array, Stack, Monotonic Stack
 *
 * Description:
 * Given an array of integers heights representing the histogram's bar
 * height where the width of each bar is 1, return the area of the
 * largest rectangle in the histogram.
 *
 * Constraints:
 * - 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

    }
};

int main() {
    Solution sol;

        vector<int> h1 = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(h1) << "\n"; // 10
    vector<int> h2 = {2,4};
    cout << sol.largestRectangleArea(h2) << "\n"; // 4

    return 0;
}
