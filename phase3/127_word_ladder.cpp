/*
 * 127. Word Ladder
 * Difficulty: Hard
 * Tags: Hash Table, String, BFS
 *
 * Description:
 * Find shortest transformation sequence from beginWord to endWord.
 *
 * Constraints:
 * - 1 <= beginWord.length <= 10
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例
    vector<string> wl1 = {"hot","dot","dog","lot","log","cog"};
    cout << sol.ladderLength("hit", "cog", wl1) << "\n"; // 期望: 5

    vector<string> wl2 = {"hot","dot","dog","lot","log"};
    cout << sol.ladderLength("hit", "cog", wl2) << "\n"; // 期望: 0

    return 0;
}
