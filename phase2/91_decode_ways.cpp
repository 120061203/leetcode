/*
 * 91. Decode Ways
 * Difficulty: Medium
 * Tags: String, Dynamic Programming
 *
 * Description:
 * A message containing letters from A-Z can be encoded into numbers using
 * '1' -> 'A', ..., '26' -> 'Z'. Given a string s of digits, return the
 * number of ways to decode it.
 *
 * Constraints:
 * - 1 <= s.length <= 100
 * s contains only digits and may contain leading zero(s).
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {

    }
};

int main() {
    Solution sol;

        cout << sol.numDecodings("12") << "\n"; // 2
    cout << sol.numDecodings("226") << "\n"; // 3
    cout << sol.numDecodings("06") << "\n"; // 0

    return 0;
}
