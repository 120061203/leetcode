/*
 * 76. Minimum Window Substring
 * Difficulty: Hard
 * Tags: Hash Table, String, Sliding Window
 *
 * Description:
 * Given two strings s and t, return the minimum window substring of s
 * such that every character in t is included in the window.
 * Return empty string if no such window exists.
 *
 * Constraints:
 * - m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

    }
};

int main() {
    Solution sol;

        cout << sol.minWindow("ADOBECODEBANC", "ABC") << "\n"; // BANC
    cout << sol.minWindow("a", "a") << "\n"; // a
    cout << sol.minWindow("a", "aa") << "\n"; // ""

    return 0;
}
