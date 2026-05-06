/*
 * 191. Number of 1 Bits
 * Difficulty: Easy
 * Tags: Divide & Conquer, Bit Manipulation
 *
 * Description:
 * Given a positive integer n, write a function that returns the number of
 * set bits in its binary representation (also known as the Hamming weight).
 *
 * Constraints:
 * - 1 <= n <= 2^31 - 1
 */

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {

    }
};

int main() {
    Solution sol;

    // Input: n = 11 (binary: 1011)
    // Output: 3
    cout << sol.hammingWeight(11) << "\n";

    // Input: n = 128 (binary: 10000000)
    // Output: 1
    cout << sol.hammingWeight(128) << "\n";

    return 0;
}
