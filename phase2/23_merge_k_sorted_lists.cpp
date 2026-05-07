/*
 * 23. Merge K Sorted Lists
 * Difficulty: Hard
 * Tags: Linked List, Divide and Conquer, Heap
 *
 * Description:
 * You are given an array of k linked-lists, each sorted in ascending order.
 * Merge all the linked-lists into one sorted list and return it.
 *
 * Constraints:
 * - k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    }
};

int main() {
    Solution sol;

    // [[1,4,5],[1,3,4],[2,6]] → [1,1,2,3,4,4,5,6]
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4); l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3); l2->next->next = new ListNode(4);
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* r = sol.mergeKLists(lists);
    while(r){ cout << r->val << " "; r = r->next; } cout << "\n";

    return 0;
}
