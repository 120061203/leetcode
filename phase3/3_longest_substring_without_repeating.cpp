/*
 * 3. Longest Substring Without Repeating
 * Difficulty: Medium
 * Tags: Hash Table, String, Sliding Window
 *
 * Description:
 * Find the longest substring without repeating characters.
 *
 * Constraints:
 * - 0 <= s.length <= 5*10^4
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        return 0;
    }
};

int main() {
    Solution sol;

    // 测试用例
    cout << sol.lengthOfLongestSubstring("abcabcbb") << "\n"; // 期望: 3
    cout << sol.lengthOfLongestSubstring("bbbbb") << "\n";    // 期望: 1
    cout << sol.lengthOfLongestSubstring("pwwkew") << "\n";   // 期望: 3

    return 0;
}
