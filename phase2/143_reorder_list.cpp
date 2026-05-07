/*
 * 143. Reorder List
 * Difficulty: Medium
 * Tags: Linked List, Two Pointers, Stack, Recursion
 *
 * Description:
 * You are given the head of a singly linked-list:
 * L0 → L1 → … → Ln-1 → Ln
 * Reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
 * Do not modify the values in the nodes, only nodes themselves may be changed.
 *
 * Constraints:
 * - The number of nodes in the list is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 1000
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
    void reorderList(ListNode* head) {

    }
};

int main() {
    Solution sol;

    // [1,2,3,4] → [1,4,2,3]
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2); h->next->next = new ListNode(3);
    h->next->next->next = new ListNode(4);
    sol.reorderList(h);
    while(h){ cout << h->val << " "; h = h->next; } cout << "\n";

    return 0;
}
