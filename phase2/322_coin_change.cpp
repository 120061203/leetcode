/*
 * 322. Coin Change
 * Difficulty: Medium
 * Tags: Array, Dynamic Programming, BFS
 *
 * Description:
 * Given an array of coins and an amount, return the fewest number of
 * coins needed to make up that amount. Return -1 if it's not possible.
 *
 * Constraints:
 * - 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

    }
};

int main() {
    Solution sol;

        vector<int> c1 = {1,5,6,9};
    cout << sol.coinChange(c1, 11) << "\n"; // 2
    vector<int> c2 = {2};
    cout << sol.coinChange(c2, 3) << "\n"; // -1

    return 0;
}
