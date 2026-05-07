/*
 * 125. Valid Palindrome
 * Difficulty: Easy
 * Tags: Two Pointers, String
 *
 * Description:
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads
 * the same forward and backward.
 * Given a string s, return true if it is a palindrome, or false otherwise.
 *
 * Constraints:
 * - 1 <= s.length <= 2 * 10^5
 * - s consists only of printable ASCII characters.
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;
        while(left < right){
            if(!isalnum(s[left])) { left++; continue; }
            if(!isalnum(s[right])) { right--; continue; }
            if(tolower(s[left]) != tolower(s[right])) return false; // 比較時才轉小寫，不修改原字串
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // Input: s = "A man, a plan, a canal: Panama"
    // Output: true
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << "\n";

    // Input: s = "race a car"
    // Output: false
    cout << sol.isPalindrome("race a car") << "\n";

    return 0;
}
