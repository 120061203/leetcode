/*
 * 19. Remove Nth Node From End of List
 * Difficulty: Medium
 * Tags: Linked List, Two Pointers
 *
 * Description:
 * Given the head of a linked list, remove the nth node from the end of
 * the list and return its head.
 *
 * Constraints:
 * - The number of nodes in the list is sz.
 * 1 <= sz <= 30
 * 0 <= Node.val <= 100
 * 1 <= n <= sz
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

    }
};

int main() {
    Solution sol;

    // [1,2,3,4,5], n=2 → [1,2,3,5]
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2); h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    h->next->next->next->next = new ListNode(5);
    ListNode* r = sol.removeNthFromEnd(h, 2);
    while(r){ cout << r->val << " "; r = r->next; } cout << "\n";

    return 0;
}
