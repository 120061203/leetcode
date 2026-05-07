/*
 * 11. Container With Most Water
 * Difficulty: Medium
 * Tags: Array, Two Pointers, Greedy
 *
 * Description:
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the ith line are (i, 0)
 * and (i, height[i]).
 * Find two lines that together with the x-axis form a container, such
 * that the container contains the most water.
 *
 * Constraints:
 * - n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {

    }
};

int main() {
    Solution sol;

        vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(h1) << "\n"; // 49
    vector<int> h2 = {1,1};
    cout << sol.maxArea(h2) << "\n"; // 1

    return 0;
}
