/*
 * 139. Word Break
 * Difficulty: Medium
 * Tags: Hash Table, String, Dynamic Programming, Trie, Memoization
 *
 * Description:
 * Given a string s and a dictionary of strings wordDict, return true if s
 * can be segmented into a space-separated sequence of one or more
 * dictionary words.
 *
 * Constraints:
 * - 1 <= s.length <= 300
 * 1 <= wordDict.length <= 1000
 * 1 <= wordDict[i].length <= 20
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

    }
};

int main() {
    Solution sol;

        vector<string> d1 = {"leet","code"};
    cout << sol.wordBreak("leetcode", d1) << "\n"; // 1
    vector<string> d2 = {"apple","pen"};
    cout << sol.wordBreak("applepenapple", d2) << "\n"; // 1

    return 0;
}
