/*
 * 338. Counting Bits
 * Difficulty: Easy
 * Tags: DP, Bit Manipulation
 *
 * Description:
 * Given an integer n, return an array ans of length n + 1 such that for
 * each i (0 <= i <= n), ans[i] is the number of 1's in the binary
 * representation of i.
 *
 * Constraints:
 * - 0 <= n <= 10^5
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {

    }
};

int main() {
    Solution sol;

    // Input: n = 2
    // Output: [0,1,1]
    auto res1 = sol.countBits(2);
    for (int x : res1) cout << x << " ";
    cout << "\n";

    // Input: n = 5
    // Output: [0,1,1,2,1,2]
    auto res2 = sol.countBits(5);
    for (int x : res2) cout << x << " ";
    cout << "\n";

    return 0;
}
