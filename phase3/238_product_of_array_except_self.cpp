/*
 * 238. Product Of Array Except Self
 * Difficulty: Medium
 * Tags: Array, Prefix Sum
 *
 * Description:
 * Return array where each element is product of all others without division.
 *
 * Constraints:
 * - 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例：打印结果数组
    auto printVec = [](vector<int>& v) {
        for (int i = 0; i < (int)v.size(); i++) {
            if (i) cout << ",";
            cout << v[i];
        }
        cout << "\n";
    };

    vector<int> n1 = {1,2,3,4};
    auto r1 = sol.productExceptSelf(n1);
    printVec(r1); // 期望: 24,12,8,6

    vector<int> n2 = {-1,1,0,-3,3};
    auto r2 = sol.productExceptSelf(n2);
    printVec(r2); // 期望: 0,0,9,0,0

    return 0;
}
