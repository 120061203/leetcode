/*
 * 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Tags: String, Dynamic Programming
 *
 * Description:
 * Given a string s, return the longest palindromic substring in s.
 *
 * Constraints:
 * - 1 <= s.length <= 1000
 * s consist of only digits and English letters.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

    }
};

int main() {
    Solution sol;

        cout << sol.longestPalindrome("babad") << "\n"; // "bab" or "aba"
    cout << sol.longestPalindrome("cbbd") << "\n"; // "bb"

    return 0;
}
