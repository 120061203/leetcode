/*
 * 141. Linked List Cycle
 * Difficulty: Easy
 * Tags: Hash Table, Linked List, Two Pointers
 *
 * Description:
 * Given head, the head of a linked list, determine if the linked list
 * has a cycle in it.
 *
 * Constraints:
 * - The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
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
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;                          // 慢指針，每次走一步
        ListNode* fast = head;                          // 快指針，每次走兩步
        while(fast != nullptr && fast->next != nullptr){ // fast 或 fast->next 為空代表無環
            slow = slow->next;                          // slow 走一步
            fast = fast->next->next;                    // fast 走兩步
            if(slow == fast){                           // 相遇代表有環
                return true;
            }
        }
        return false;                                   // fast 走到底，無環
    }
};

int main() {
    Solution sol;

    // [3,2,0,-4] with cycle at pos 1 → true
    ListNode* h = new ListNode(3);
    h->next = new ListNode(2);
    h->next->next = new ListNode(0);
    h->next->next->next = new ListNode(-4);
    h->next->next->next->next = h->next; // cycle
    cout << sol.hasCycle(h) << "\n"; // 1
    // [1] no cycle → false
    cout << sol.hasCycle(new ListNode(1)) << "\n"; // 0

    return 0;
}
