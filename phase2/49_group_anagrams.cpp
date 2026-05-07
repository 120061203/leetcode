/*
 * 49. Group Anagrams
 * Difficulty: Medium
 * Tags: Array, Hash Table, String, Sorting
 *
 * Description:
 * Given an array of strings strs, group the anagrams together.
 *
 * Constraints:
 * - 1 <= strs.length <= 10^4
 * 0 <= strs[i].length <= 100
 * strs[i] consists of lowercase English letters.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    }
};

int main() {
    Solution sol;

        vector<string> s = {"eat","tea","tan","ate","nat","bat"};
    auto r = sol.groupAnagrams(s);
    cout << r.size() << "\n"; // 3

    return 0;
}
