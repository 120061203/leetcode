/*
 * 347. Top K Frequent Elements
 * Difficulty: Medium
 * Tags: Array, Hash Table, Heap
 *
 * Description:
 * Given an integer array nums and an integer k, return the k most
 * frequent elements.
 *
 * Constraints:
 * - 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

    }
};

int main() {
    Solution sol;

        vector<int> n1 = {1,1,1,2,2,3};
    auto r1 = sol.topKFrequent(n1, 2);
    for(int x : r1) cout << x << " ";
    cout << "\n"; // 1 2

    return 0;
}
