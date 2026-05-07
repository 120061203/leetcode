/*
 * 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Tags: Hash Table, String, Sliding Window
 *
 * Description:
 * Given a string s, find the length of the longest substring without
 * repeating characters.
 *
 * Constraints:
 * - 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

    }
};

int main() {
    Solution sol;

        cout << sol.lengthOfLongestSubstring("abcabcbb") << "\n"; // 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << "\n"; // 1
    cout << sol.lengthOfLongestSubstring("pwwkew") << "\n"; // 3

    return 0;
}
