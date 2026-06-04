/*
 * 84. Largest Rectangle In Histogram
 * Difficulty: Hard
 * Tags: Array, Stack, Monotonic Stack
 *
 * Description:
 * Find the largest rectangle in a histogram.
 *
 * Constraints:
 * - 1 <= heights.length <= 10^5
 * 0 <= heights[i] <= 10^4
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<int> h1 = {2,1,5,6,2,3};
    cout << sol.largestRectangleArea(h1) << "\n"; // 期望: 10
    vector<int> h2 = {2,4};
    cout << sol.largestRectangleArea(h2) << "\n"; // 期望: 4

    return 0;
}
