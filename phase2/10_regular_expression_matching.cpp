/*
 * 10. Regular Expression Matching
 * Difficulty: Hard
 * Tags: String, Dynamic Programming, Recursion
 *
 * Description:
 * Given an input string s and a pattern p, implement regular expression
 * matching with support for '.' and '*'.
 * '.' matches any single character.
 * '*' matches zero or more of the preceding element.
 *
 * Constraints:
 * - 1 <= s.length <= 20
 * 1 <= p.length <= 20
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

    }
};

int main() {
    Solution sol;

        cout << sol.isMatch("aa", "a") << "\n"; // 0
    cout << sol.isMatch("aa", "a*") << "\n"; // 1
    cout << sol.isMatch("ab", ".*") << "\n"; // 1

    return 0;
}
