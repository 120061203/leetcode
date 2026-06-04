/*
 * 42. Trapping Rain Water
 * Difficulty: Hard
 * Tags: Array, Two Pointers, Stack, DP
 *
 * Description:
 * Compute how much water can be trapped after raining.
 *
 * Constraints:
 * - 1 <= height.length <= 2*10^4
 * 0 <= height[i] <= 10^5
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(h1) << "\n"; // 期望: 6
    vector<int> h2 = {4,2,0,3,2,5};
    cout << sol.trap(h2) << "\n"; // 期望: 9

    return 0;
}
