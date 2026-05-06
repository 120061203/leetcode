/*
 * 190. Reverse Bits
 * Difficulty: Easy
 * Tags: Divide & Conquer, Bit Manipulation
 *
 * Description:
 * Reverse bits of a given 32-bit unsigned integer.
 *
 * Constraints:
 * - The input must be a binary string of length 32.
 */

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {

    }
};

int main() {
    Solution sol;

    // Input: n = 00000010100101000001111010011100
    // Output:    964176192 (00111001011110000010100101000000)
    cout << sol.reverseBits(43261596) << "\n";

    // Input: n = 11111111111111111111111111111101
    // Output:    3221225471 (10111111111111111111111111111111)
    cout << sol.reverseBits(4294967293) << "\n";

    return 0;
}
