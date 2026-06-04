/*
 * 39. Combination Sum
 * Difficulty: Medium
 * Tags: Array, Backtracking
 *
 * Description:
 * Find all combinations that sum to target (unlimited reuse).
 *
 * Constraints:
 * - 1 <= candidates.length <= 30
 * 1 <= target <= 40
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例：打印每个组合
    auto printCombos = [](vector<vector<int>>& res) {
        for (auto& combo : res) {
            cout << "[";
            for (int i = 0; i < (int)combo.size(); i++) {
                if (i) cout << ",";
                cout << combo[i];
            }
            cout << "] ";
        }
        cout << "\n";
    };

    vector<int> c1 = {2,3,6,7};
    auto r1 = sol.combinationSum(c1, 7);
    printCombos(r1); // 期望: [2,2,3] [7]

    vector<int> c2 = {2,3};
    auto r2 = sol.combinationSum(c2, 6);
    printCombos(r2); // 期望: [2,2,2] [3,3]

    return 0;
}
