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
        // 把所有節點指標收進 vector，方便用 index 從頭尾交替取
        vector<ListNode*> nodes;
        for (ListNode* cur = head; cur; cur = cur->next)
            nodes.push_back(cur);

        int left = 0, right = nodes.size() - 1;
        while (left < right) {
            // 頭節點接尾節點，尾節點接下一個頭節點
            nodes[left]->next = nodes[right];
            nodes[right]->next = nodes[left + 1];
            left++;
            right--;
        }
        // 最後停在中間的節點，斷掉它的 next 避免形成環
        nodes[left]->next = nullptr;
    }
};

// 三步驟法：找中點 → 反轉後半 → 交替合併，空間 O(1)
class Solution2 {
    // 步驟一：快慢指針找中點，回傳前半段最後一個節點
    ListNode* findMid(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow; // slow 停在前半段末尾
    }

    // 步驟二：反轉從 head 開始的 linked list，回傳新的頭
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr, *cur = head;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        // 1. 找中點，切斷前後兩段
        ListNode* mid = findMid(head);
        ListNode* secondHalf = mid->next;
        mid->next = nullptr;

        // 2. 反轉後半段
        secondHalf = reverse(secondHalf);

        // 3. 交替合併前半和反轉後的後半
        ListNode* first = head, *second = secondHalf;
        while (second) {
            ListNode* tmp1 = first->next, *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};

int main() {
    // Solution 1: vector 法
    {
        Solution sol;
        ListNode* h = new ListNode(1);
        h->next = new ListNode(2); h->next->next = new ListNode(3);
        h->next->next->next = new ListNode(4);
        sol.reorderList(h);
        while(h){ cout << h->val << " "; h = h->next; } cout << "\n"; // 1 4 2 3
    }

    // Solution 2: 找中點+反轉法
    {
        Solution2 sol;
        ListNode* h = new ListNode(1);
        h->next = new ListNode(2); h->next->next = new ListNode(3);
        h->next->next->next = new ListNode(4); h->next->next->next->next = new ListNode(5);
        sol.reorderList(h);
        while(h){ cout << h->val << " "; h = h->next; } cout << "\n"; // 1 5 2 4 3
    }

    return 0;
}
