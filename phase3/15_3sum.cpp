/*
 * 15. 3Sum
 * Difficulty: Medium
 * Tags: Array, Two Pointers, Sorting
 *
 * Description:
 * Find all unique triplets that sum to zero.
 *
 * Constraints:
 * - -10^5 <= nums[i] <= 10^5
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例：打印每组三元组
    auto printTriples = [](vector<vector<int>>& res) {
        for (auto& group : res) {
            cout << "[" << group[0] << "," << group[1] << "," << group[2] << "] ";
        }
        cout << "\n";
    };

    vector<int> n1 = {-1,0,1,2,-1,-4};
    auto r1 = sol.threeSum(n1);
    printTriples(r1); // 期望: [-1,-1,2] [-1,0,1]

    vector<int> n2 = {0,1,1};
    auto r2 = sol.threeSum(n2);
    printTriples(r2); // 期望: (空)

    vector<int> n3 = {0,0,0};
    auto r3 = sol.threeSum(n3);
    printTriples(r3); // 期望: [0,0,0]

    return 0;
}
