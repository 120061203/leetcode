/*
 * 242. Valid Anagram
 * Difficulty: Easy
 * Tags: Hash Table, String, Sorting
 *
 * Description:
 * Given two strings s and t, return true if t is an anagram of s,
 * and false otherwise.
 * An anagram is a word or phrase formed by rearranging the letters of
 * a different word or phrase, using all the original letters exactly once.
 *
 * Constraints:
 * - 1 <= s.length, t.length <= 5 * 10^4
 * - s and t consist of lowercase English letters.
 */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

    }
};

int main() {
    Solution sol;

    // Input: s = "anagram", t = "nagaram"
    // Output: true
    cout << sol.isAnagram("anagram", "nagaram") << "\n";

    // Input: s = "rat", t = "car"
    // Output: false
    cout << sol.isAnagram("rat", "car") << "\n";

    return 0;
}
