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
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


class SolutionOptimized {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> freq;
        for(char c : s){
            freq[c]++;
        }
        for(char c : t){
            freq[c]--;
            if(freq[c] < 0){
                return false;
            }
        }
        return true;
    }
};



int main() {
    Solution sol;
    SolutionOptimized sol_optimized;
    // Input: s = "anagram", t = "nagaram"
    // Output: true
    cout << sol.isAnagram("anagram", "nagaram") << "\n";
    cout << sol_optimized.isAnagram("anagram", "nagaram") << "\n";
    // Input: s = "rat", t = "car"
    // Output: false
    cout << sol.isAnagram("rat", "car") << "\n";
    cout << sol_optimized.isAnagram("rat", "car") << "\n";

    return 0;
}
