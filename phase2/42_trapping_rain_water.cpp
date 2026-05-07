/*
 * 42. Trapping Rain Water
 * Difficulty: Hard
 * Tags: Array, Two Pointers, Stack, Dynamic Programming
 *
 * Description:
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it can trap after
 * raining.
 *
 * Constraints:
 * - n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

    }
};

int main() {
    Solution sol;

        vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(h1) << "\n"; // 6
    vector<int> h2 = {4,2,0,3,2,5};
    cout << sol.trap(h2) << "\n"; // 9

    return 0;
}
