/*
 * 21. Merge Two Sorted Lists
 * Difficulty: Easy
 * Tags: Linked List, Recursion
 *
 * Description:
 * You are given the heads of two sorted linked lists list1 and list2.
 * Merge the two lists into one sorted list and return the head.
 *
 * Constraints:
 * - The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    }
};

int main() {
    Solution sol;

    // [1,2,4] + [1,3,4] → [1,1,2,3,4,4]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2); l1->next->next = new ListNode(4);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3); l2->next->next = new ListNode(4);
    ListNode* r = sol.mergeTwoLists(l1, l2);
    while(r){ cout << r->val << " "; r = r->next; } cout << "\n";

    return 0;
}
