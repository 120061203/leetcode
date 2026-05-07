/*
 * 20. Valid Parentheses
 * Difficulty: Easy
 * Tags: String, Stack
 *
 * Description:
 * Given a string s containing just the characters '(', ')', '{', '}', '['
 * and ']', determine if the input string is valid.
 * An input string is valid if:
 * - Open brackets must be closed by the same type of brackets.
 * - Open brackets must be closed in the correct order.
 * - Every close bracket has a corresponding open bracket of the same type.
 *
 * Constraints:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only '()[]{}'.
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                stk.push(c);
            }else{
                if(stk.empty()) return false;
                if(c == ')' && stk.top() != '(') return false;
                if(c == ']' && stk.top() != '[') return false;
                if(c == '}' && stk.top() != '{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main() {
    Solution sol;

    // Input: s = "()"
    // Output: true
    cout << sol.isValid("()") << "\n";

    // Input: s = "()[]{}"
    // Output: true
    cout << sol.isValid("()[]{}") << "\n";

    // Input: s = "(]"
    // Output: false
    cout << sol.isValid("(]") << "\n";

    return 0;
}
