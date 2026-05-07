/*
 * 206. Reverse Linked List
 * Difficulty: Easy
 * Tags: Linked List, Recursion
 *
 * Description:
 * Given the head of a singly linked list, reverse the list,
 * and return the reversed list.
 *
 * Constraints:
 * - The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

    }
};

int main() {
    Solution sol;

    // [1,2,3,4,5] → [5,4,3,2,1]
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    ListNode* r = sol.reverseList(h);
    while(r){ cout << r->val << " "; r = r->next; } cout << "\n";

    return 0;
}
