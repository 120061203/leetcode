/*
 * 1143. Longest Common Subsequence
 * Difficulty: Medium
 * Tags: String, Dynamic Programming
 *
 * Description:
 * Given two strings text1 and text2, return the length of their longest
 * common subsequence.
 *
 * Constraints:
 * - 1 <= text1.length, text2.length <= 1000
 * text1 and text2 consist of only lowercase English letters.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

    }
};

int main() {
    Solution sol;

        cout << sol.longestCommonSubsequence("abcde", "ace") << "\n"; // 3
    cout << sol.longestCommonSubsequence("abc", "abc") << "\n"; // 3
    cout << sol.longestCommonSubsequence("abc", "def") << "\n"; // 0

    return 0;
}
