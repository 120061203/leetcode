/*
 * 424. Longest Repeating Char Replacement
 * Difficulty: Medium
 * Tags: Hash Table, String, Sliding Window
 *
 * Description:
 * Find longest substring with same letters after k replacements.
 *
 * Constraints:
 * - 1 <= s.length <= 10^5
 * 0 <= k <= s.length
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        return 0;
    }
};

int main() {
    Solution sol;

    // 测试用例
    cout << sol.characterReplacement("ABAB", 2) << "\n";    // 期望: 4
    cout << sol.characterReplacement("AABABBA", 1) << "\n"; // 期望: 4

    return 0;
}
