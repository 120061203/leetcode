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
        if(lists.empty()) return nullptr;           // 空陣列直接回傳
        if(lists.size() == 1) return lists[0];      // 只有一個 list 直接回傳
        int mid = lists.size() / 2;                 // 從中間切割
        vector<ListNode*> leftVec(lists.begin(), lists.begin() + mid);   // 左半
        vector<ListNode*> rightVec(lists.begin() + mid, lists.end());    // 右半
        ListNode* leftList = mergeKLists(leftVec);  // 遞迴合併左半
        ListNode* rightList = mergeKLists(rightVec);// 遞迴合併右半
        return mergeTwoLists(leftList, rightList);  // 合併左右結果
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;                    // list1 空，回傳 list2
        if(!list2) return list1;                    // list2 空，回傳 list1
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2); // list1 較小，接上剩餘合併結果
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next); // list2 較小，接上剩餘合併結果
            return list2;
        }
    }
};

// Min Heap 解法：把每個 list 的頭節點放進 heap，每次取最小的接到結果上
class SolutionHeap {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 自訂比較子：值較大的優先級較低（min heap）
        auto cmp = [](ListNode* a, ListNode* b){ return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for(ListNode* node : lists){        // 把每個 list 的頭節點加入 heap
            if(node) pq.push(node);
        }

        ListNode dummy(0);                  // dummy 頭節點，簡化邊界處理
        ListNode* cur = &dummy;
        while(!pq.empty()){
            ListNode* node = pq.top(); pq.pop(); // 取出值最小的節點
            cur->next = node;                    // 接到結果鏈上
            cur = cur->next;
            if(node->next) pq.push(node->next);  // 把該節點的下一個加入 heap
        }
        return dummy.next;
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

    // SolutionHeap 測試
    SolutionHeap solH;
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(4); h1->next->next = new ListNode(5);
    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(3); h2->next->next = new ListNode(4);
    ListNode* h3 = new ListNode(2);
    h3->next = new ListNode(6);
    vector<ListNode*> lists2 = {h1, h2, h3};
    ListNode* r2 = solH.mergeKLists(lists2);
    while(r2){ cout << r2->val << " "; r2 = r2->next; } cout << "\n";

    return 0;
}
