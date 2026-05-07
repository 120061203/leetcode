/*
 * 424. Longest Repeating Character Replacement
 * Difficulty: Medium
 * Tags: Hash Table, String, Sliding Window
 *
 * Description:
 * You are given a string s and an integer k. You can choose any character
 * of the string and change it to any other uppercase English character.
 * Return the length of the longest substring containing the same letter
 * you can get after performing the above operations at most k times.
 *
 * Constraints:
 * - 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

    }
};

int main() {
    Solution sol;

        cout << sol.characterReplacement("ABAB", 2) << "\n"; // 4
    cout << sol.characterReplacement("AABABBA", 1) << "\n"; // 4

    return 0;
}
