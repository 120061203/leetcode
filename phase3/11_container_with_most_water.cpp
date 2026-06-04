/*
 * 11. Container With Most Water
 * Difficulty: Medium
 * Tags: Array, Two Pointers, Greedy
 *
 * Description:
 * Find two lines forming a container holding the most water.
 *
 * Constraints:
 * - 2 <= height.length <= 10^5
 * 0 <= height[i] <= 10^4
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<int> h1 = {1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(h1) << "\n"; // 期望: 49
    vector<int> h2 = {1,1};
    cout << sol.maxArea(h2) << "\n"; // 期望: 1

    return 0;
}
