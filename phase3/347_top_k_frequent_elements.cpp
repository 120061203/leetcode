/*
 * 347. Top K Frequent Elements
 * Difficulty: Medium
 * Tags: Array, Hash Table, Heap
 *
 * Description:
 * Return the k most frequent elements.
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * 1 <= k <= number of unique elements
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
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

    vector<int> n1 = {1,1,1,2,2,3};
    auto r1 = sol.topKFrequent(n1, 2);
    printVec(r1); // 期望: 1,2

    vector<int> n2 = {1};
    auto r2 = sol.topKFrequent(n2, 1);
    printVec(r2); // 期望: 1

    return 0;
}
