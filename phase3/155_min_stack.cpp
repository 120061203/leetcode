/*
 * 155. Min Stack
 * Difficulty: Medium
 * Tags: Stack, Design
 *
 * Description:
 * Design a stack that supports getMin in O(1).
 *
 * Constraints:
 * - 2 <= ops.length <= 3*10^4
 */

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
    void push(int val) {

    }
    void pop() {

    }
    int top() {
        return 0;
    }
    int getMin() {
        return 0;
    }
};

int main() {
    MinStack ms;
    ms.push(-2); ms.push(0); ms.push(-3);
    cout << ms.getMin() << "\n"; // -3
    ms.pop();
    cout << ms.top()    << "\n"; // 0
    cout << ms.getMin() << "\n"; // -2

    return 0;
}
