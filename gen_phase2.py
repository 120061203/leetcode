#!/usr/bin/env python3
"""Generate phase2 problem template files.

Phase 2 — Binary Search / Linked List / Trees (23 problems)
"""

import os

OUT = os.path.join(os.path.dirname(__file__), "phase2")
os.makedirs(OUT, exist_ok=True)

LINKED_LIST_HEADER = """\
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};\
"""

TREE_HEADER = """\
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};\
"""

problems = [
    # ── Binary Search ─────────────────────────────────────────────────────
    ("74_search_a_2d_matrix", "74. Search a 2D Matrix", "Medium",
     "Array, Binary Search, Matrix",
     "You are given an m x n integer matrix where each row is sorted in\n"
     " * non-decreasing order and the first integer of each row is greater\n"
     " * than the last integer of the previous row.\n"
     " * Given an integer target, return true if target is in matrix.",
     "m == matrix.length\n"
     " * n == matrix[i].length\n"
     " * 1 <= m, n <= 100\n"
     " * -10^4 <= matrix[i][j], target <= 10^4",
     "#include <iostream>\n#include <vector>\nusing namespace std;",
     "bool searchMatrix(vector<vector<int>>& matrix, int target)",
     "    vector<vector<int>> m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};\n"
     '    cout << sol.searchMatrix(m, 3) << "\\n"; // 1\n'
     '    cout << sol.searchMatrix(m, 13) << "\\n"; // 0'),

    ("153_find_minimum_in_rotated_sorted_array",
     "153. Find Minimum in Rotated Sorted Array", "Medium",
     "Array, Binary Search",
     "Given the sorted rotated array nums of unique elements, return the\n"
     " * minimum element of this array. Must run in O(log n).",
     "n == nums.length\n"
     " * 1 <= n <= 5000\n"
     " * -5000 <= nums[i] <= 5000\n"
     " * All the integers of nums are unique.",
     "#include <iostream>\n#include <vector>\nusing namespace std;",
     "int findMin(vector<int>& nums)",
     "    vector<int> n1 = {3,4,5,1,2};\n"
     '    cout << sol.findMin(n1) << "\\n"; // 1\n'
     "    vector<int> n2 = {4,5,6,7,0,1,2};\n"
     '    cout << sol.findMin(n2) << "\\n"; // 0'),

    ("33_search_in_rotated_sorted_array",
     "33. Search in Rotated Sorted Array", "Medium",
     "Array, Binary Search",
     "Given the array nums after the possible rotation and an integer target,\n"
     " * return the index of target if it is in nums, or -1 if it is not.\n"
     " * Must run in O(log n).",
     "1 <= nums.length <= 5000\n"
     " * -10^4 <= nums[i] <= 10^4\n"
     " * All values of nums are unique.\n"
     " * -10^4 <= target <= 10^4",
     "#include <iostream>\n#include <vector>\nusing namespace std;",
     "int search(vector<int>& nums, int target)",
     "    vector<int> n1 = {4,5,6,7,0,1,2};\n"
     '    cout << sol.search(n1, 0) << "\\n"; // 4\n'
     '    cout << sol.search(n1, 3) << "\\n"; // -1'),

    ("4_median_of_two_sorted_arrays",
     "4. Median of Two Sorted Arrays", "Hard",
     "Array, Binary Search, Divide and Conquer",
     "Given two sorted arrays nums1 and nums2 of size m and n respectively,\n"
     " * return the median of the two sorted arrays. Must run in O(log(m+n)).",
     "nums1.length == m\n"
     " * nums2.length == n\n"
     " * 0 <= m <= 1000\n"
     " * 0 <= n <= 1000\n"
     " * -10^6 <= nums1[i], nums2[i] <= 10^6",
     "#include <iostream>\n#include <vector>\nusing namespace std;",
     "double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)",
     "    vector<int> n1 = {1,3}, n2 = {2};\n"
     '    cout << sol.findMedianSortedArrays(n1, n2) << "\\n"; // 2.0\n'
     "    vector<int> n3 = {1,2}, n4 = {3,4};\n"
     '    cout << sol.findMedianSortedArrays(n3, n4) << "\\n"; // 2.5'),

    # ── Linked List ───────────────────────────────────────────────────────
    ("206_reverse_linked_list", "206. Reverse Linked List", "Easy",
     "Linked List, Recursion",
     "Given the head of a singly linked list, reverse the list,\n"
     " * and return the reversed list.",
     "The number of nodes in the list is the range [0, 5000].\n"
     " * -5000 <= Node.val <= 5000",
     LINKED_LIST_HEADER,
     "ListNode* reverseList(ListNode* head)",
     "// [1,2,3,4,5] → [5,4,3,2,1]\n"
     "    ListNode* h = new ListNode(1);\n"
     "    h->next = new ListNode(2);\n"
     "    h->next->next = new ListNode(3);\n"
     "    h->next->next->next = new ListNode(4);\n"
     "    h->next->next->next->next = new ListNode(5);\n"
     "    ListNode* r = sol.reverseList(h);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    ("21_merge_two_sorted_lists", "21. Merge Two Sorted Lists", "Easy",
     "Linked List, Recursion",
     "You are given the heads of two sorted linked lists list1 and list2.\n"
     " * Merge the two lists into one sorted list and return the head.",
     "The number of nodes in both lists is in the range [0, 50].\n"
     " * -100 <= Node.val <= 100",
     LINKED_LIST_HEADER,
     "ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)",
     "// [1,2,4] + [1,3,4] → [1,1,2,3,4,4]\n"
     "    ListNode* l1 = new ListNode(1);\n"
     "    l1->next = new ListNode(2); l1->next->next = new ListNode(4);\n"
     "    ListNode* l2 = new ListNode(1);\n"
     "    l2->next = new ListNode(3); l2->next->next = new ListNode(4);\n"
     "    ListNode* r = sol.mergeTwoLists(l1, l2);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    ("141_linked_list_cycle", "141. Linked List Cycle", "Easy",
     "Hash Table, Linked List, Two Pointers",
     "Given head, the head of a linked list, determine if the linked list\n"
     " * has a cycle in it.",
     "The number of the nodes in the list is in the range [0, 10^4].\n"
     " * -10^5 <= Node.val <= 10^5",
     LINKED_LIST_HEADER,
     "bool hasCycle(ListNode* head)",
     "// [3,2,0,-4] with cycle at pos 1 → true\n"
     "    ListNode* h = new ListNode(3);\n"
     "    h->next = new ListNode(2);\n"
     "    h->next->next = new ListNode(0);\n"
     "    h->next->next->next = new ListNode(-4);\n"
     "    h->next->next->next->next = h->next; // cycle\n"
     '    cout << sol.hasCycle(h) << "\\n"; // 1\n'
     "    // [1] no cycle → false\n"
     '    cout << sol.hasCycle(new ListNode(1)) << "\\n"; // 0'),

    ("143_reorder_list", "143. Reorder List", "Medium",
     "Linked List, Two Pointers, Stack, Recursion",
     "You are given the head of a singly linked-list:\n"
     " * L0 → L1 → … → Ln-1 → Ln\n"
     " * Reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …\n"
     " * Do not modify the values in the nodes, only nodes themselves may be changed.",
     "The number of nodes in the list is in the range [1, 5 * 10^4].\n"
     " * 1 <= Node.val <= 1000",
     LINKED_LIST_HEADER,
     "void reorderList(ListNode* head)",
     "// [1,2,3,4] → [1,4,2,3]\n"
     "    ListNode* h = new ListNode(1);\n"
     "    h->next = new ListNode(2); h->next->next = new ListNode(3);\n"
     "    h->next->next->next = new ListNode(4);\n"
     "    sol.reorderList(h);\n"
     '    while(h){ cout << h->val << " "; h = h->next; } cout << "\\n";'),

    ("19_remove_nth_node_from_end",
     "19. Remove Nth Node From End of List", "Medium",
     "Linked List, Two Pointers",
     "Given the head of a linked list, remove the nth node from the end of\n"
     " * the list and return its head.",
     "The number of nodes in the list is sz.\n"
     " * 1 <= sz <= 30\n"
     " * 0 <= Node.val <= 100\n"
     " * 1 <= n <= sz",
     LINKED_LIST_HEADER,
     "ListNode* removeNthFromEnd(ListNode* head, int n)",
     "// [1,2,3,4,5], n=2 → [1,2,3,5]\n"
     "    ListNode* h = new ListNode(1);\n"
     "    h->next = new ListNode(2); h->next->next = new ListNode(3);\n"
     "    h->next->next->next = new ListNode(4);\n"
     "    h->next->next->next->next = new ListNode(5);\n"
     "    ListNode* r = sol.removeNthFromEnd(h, 2);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    ("287_find_the_duplicate_number",
     "287. Find the Duplicate Number", "Medium",
     "Array, Two Pointers, Binary Search",
     "Given an array of integers nums containing n+1 integers where each\n"
     " * integer is in the range [1, n], there is only one repeated number.\n"
     " * Return this repeated number without modifying the array, using O(1) space.",
     "1 <= n <= 10^5\n"
     " * nums.length == n + 1\n"
     " * 1 <= nums[i] <= n\n"
     " * All integers in nums appear only once except for precisely one integer.",
     "#include <iostream>\n#include <vector>\nusing namespace std;",
     "int findDuplicate(vector<int>& nums)",
     "    vector<int> n1 = {1,3,4,2,2};\n"
     '    cout << sol.findDuplicate(n1) << "\\n"; // 2\n'
     "    vector<int> n2 = {3,1,3,4,2};\n"
     '    cout << sol.findDuplicate(n2) << "\\n"; // 3'),

    ("146_lru_cache", "146. LRU Cache", "Medium",
     "Hash Table, Linked List, Design",
     "Design a data structure that follows the constraints of a Least Recently\n"
     " * Used (LRU) cache.\n"
     " * LRUCache(int capacity): Initialize the LRU cache with positive size capacity.\n"
     " * int get(int key): Return the value of the key if the key exists, -1 otherwise.\n"
     " * void put(int key, int value): Update or insert the value. Evict the LRU key\n"
     " *   when the cache reaches its capacity.",
     "1 <= capacity <= 3000\n"
     " * 0 <= key <= 10^4\n"
     " * 0 <= value <= 10^5\n"
     " * At most 2 * 10^5 calls to get and put.",
     "#include <iostream>\n#include <unordered_map>\n#include <list>\nusing namespace std;",
     "// Design LRUCache class",
     "    // LRUCache cache(2);\n"
     "    // cache.put(1,1); cache.put(2,2);\n"
     '    // cout << cache.get(1) << "\\n"; // 1\n'
     "    // cache.put(3,3); // evicts key 2\n"
     '    // cout << cache.get(2) << "\\n"; // -1\n'
     "    // cache.put(4,4); // evicts key 1\n"
     '    // cout << cache.get(1) << "\\n"; // -1\n'
     '    // cout << cache.get(3) << "\\n"; // 3\n'
     '    // cout << cache.get(4) << "\\n"; // 4\n'
     '    cout << "LRUCache design problem" << "\\n";'),

    ("23_merge_k_sorted_lists", "23. Merge K Sorted Lists", "Hard",
     "Linked List, Divide and Conquer, Heap",
     "You are given an array of k linked-lists, each sorted in ascending order.\n"
     " * Merge all the linked-lists into one sorted list and return it.",
     "k == lists.length\n"
     " * 0 <= k <= 10^4\n"
     " * 0 <= lists[i].length <= 500\n"
     " * -10^4 <= lists[i][j] <= 10^4",
     "#include <iostream>\n#include <vector>\n#include <queue>\nusing namespace std;\n\n"
     "struct ListNode {\n"
     "    int val;\n"
     "    ListNode* next;\n"
     "    ListNode(int x) : val(x), next(nullptr) {}\n"
     "};",
     "ListNode* mergeKLists(vector<ListNode*>& lists)",
     "// [[1,4,5],[1,3,4],[2,6]] → [1,1,2,3,4,4,5,6]\n"
     "    ListNode* l1 = new ListNode(1);\n"
     "    l1->next = new ListNode(4); l1->next->next = new ListNode(5);\n"
     "    ListNode* l2 = new ListNode(1);\n"
     "    l2->next = new ListNode(3); l2->next->next = new ListNode(4);\n"
     "    ListNode* l3 = new ListNode(2);\n"
     "    l3->next = new ListNode(6);\n"
     "    vector<ListNode*> lists = {l1, l2, l3};\n"
     "    ListNode* r = sol.mergeKLists(lists);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    # ── Trees ─────────────────────────────────────────────────────────────
    ("226_invert_binary_tree", "226. Invert Binary Tree", "Easy",
     "Tree, DFS, BFS, Binary Tree",
     "Given the root of a binary tree, invert the tree, and return its root.",
     "The number of nodes in the tree is in the range [0, 100].\n"
     " * -100 <= Node.val <= 100",
     TREE_HEADER,
     "TreeNode* invertTree(TreeNode* root)",
     "// [4,2,7,1,3,6,9] → [4,7,2,9,6,3,1]\n"
     "    TreeNode* r = new TreeNode(4);\n"
     "    r->left = new TreeNode(2); r->right = new TreeNode(7);\n"
     "    r->left->left = new TreeNode(1); r->left->right = new TreeNode(3);\n"
     "    r->right->left = new TreeNode(6); r->right->right = new TreeNode(9);\n"
     "    TreeNode* res = sol.invertTree(r);\n"
     "    queue<TreeNode*> q; q.push(res);\n"
     "    while(!q.empty()){\n"
     "        TreeNode* cur = q.front(); q.pop();\n"
     '        cout << cur->val << " ";\n'
     "        if(cur->left) q.push(cur->left);\n"
     "        if(cur->right) q.push(cur->right);\n"
     '    } cout << "\\n"; // 4 7 2 9 6 3 1'),

    ("104_maximum_depth_of_binary_tree",
     "104. Maximum Depth of Binary Tree", "Easy",
     "Tree, DFS, BFS, Binary Tree",
     "Given the root of a binary tree, return its maximum depth.\n"
     " * A binary tree's maximum depth is the number of nodes along the\n"
     " * longest path from the root node down to the farthest leaf node.",
     "The number of nodes in the tree is in the range [0, 10^4].\n"
     " * -100 <= Node.val <= 100",
     TREE_HEADER,
     "int maxDepth(TreeNode* root)",
     "// [3,9,20,null,null,15,7] → 3\n"
     "    TreeNode* r1 = new TreeNode(3);\n"
     "    r1->left = new TreeNode(9);\n"
     "    r1->right = new TreeNode(20);\n"
     "    r1->right->left = new TreeNode(15);\n"
     "    r1->right->right = new TreeNode(7);\n"
     '    cout << sol.maxDepth(r1) << "\\n"; // 3\n'
     '    cout << sol.maxDepth(new TreeNode(1)) << "\\n"; // 1'),

    ("100_same_tree", "100. Same Tree", "Easy",
     "Tree, DFS, BFS, Binary Tree",
     "Given the roots of two binary trees p and q, write a function to check\n"
     " * if they are the same or not.",
     "The number of nodes in both trees is in the range [0, 100].\n"
     " * -10^4 <= Node.val <= 10^4",
     TREE_HEADER,
     "bool isSameTree(TreeNode* p, TreeNode* q)",
     "// p=[1,2,3], q=[1,2,3] → true\n"
     "    TreeNode* p1 = new TreeNode(1);\n"
     "    p1->left = new TreeNode(2); p1->right = new TreeNode(3);\n"
     "    TreeNode* q1 = new TreeNode(1);\n"
     "    q1->left = new TreeNode(2); q1->right = new TreeNode(3);\n"
     '    cout << sol.isSameTree(p1, q1) << "\\n"; // 1\n'
     "    // p=[1,2], q=[1,null,2] → false\n"
     "    TreeNode* p2 = new TreeNode(1); p2->left = new TreeNode(2);\n"
     "    TreeNode* q2 = new TreeNode(1); q2->right = new TreeNode(2);\n"
     '    cout << sol.isSameTree(p2, q2) << "\\n"; // 0'),

    ("572_subtree_of_another_tree",
     "572. Subtree of Another Tree", "Easy",
     "Tree, DFS, Binary Tree, String Matching",
     "Given the roots of two binary trees root and subRoot, return true if\n"
     " * there is a subtree of root with the same structure and node values\n"
     " * as subRoot, and false otherwise.",
     "The number of nodes in the root tree is in the range [1, 2000].\n"
     " * The number of nodes in the subRoot tree is in the range [1, 1000].\n"
     " * -10^4 <= root.val, subRoot.val <= 10^4",
     TREE_HEADER,
     "bool isSubtree(TreeNode* root, TreeNode* subRoot)",
     "// root=[3,4,5,1,2], subRoot=[4,1,2] → true\n"
     "    TreeNode* root = new TreeNode(3);\n"
     "    root->left = new TreeNode(4); root->right = new TreeNode(5);\n"
     "    root->left->left = new TreeNode(1); root->left->right = new TreeNode(2);\n"
     "    TreeNode* sub = new TreeNode(4);\n"
     "    sub->left = new TreeNode(1); sub->right = new TreeNode(2);\n"
     '    cout << sol.isSubtree(root, sub) << "\\n"; // 1'),

    ("235_lowest_common_ancestor_of_bst",
     "235. Lowest Common Ancestor of a Binary Search Tree", "Medium",
     "Tree, DFS, Binary Search Tree",
     "Given a BST and two nodes p and q, find their lowest common ancestor\n"
     " * (the lowest node that has both p and q as descendants).",
     "The number of nodes in the tree is in the range [2, 10^5].\n"
     " * -10^9 <= Node.val <= 10^9\n"
     " * All Node.val are unique.",
     TREE_HEADER,
     "TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)",
     "// [6,2,8,0,4,7,9], p=2, q=8 → 6\n"
     "    TreeNode* r = new TreeNode(6);\n"
     "    r->left = new TreeNode(2); r->right = new TreeNode(8);\n"
     "    r->left->left = new TreeNode(0); r->left->right = new TreeNode(4);\n"
     "    r->right->left = new TreeNode(7); r->right->right = new TreeNode(9);\n"
     "    TreeNode* res = sol.lowestCommonAncestor(r, r->left, r->right);\n"
     '    cout << (res ? res->val : -1) << "\\n"; // 6'),

    ("102_binary_tree_level_order_traversal",
     "102. Binary Tree Level Order Traversal", "Medium",
     "Tree, BFS, Binary Tree",
     "Given the root of a binary tree, return the level order traversal of\n"
     " * its nodes' values (i.e., from left to right, level by level).",
     "The number of nodes in the tree is in the range [0, 2000].\n"
     " * -1000 <= Node.val <= 1000",
     TREE_HEADER,
     "vector<vector<int>> levelOrder(TreeNode* root)",
     "// [3,9,20,null,null,15,7] → [[3],[9,20],[15,7]]\n"
     "    TreeNode* r = new TreeNode(3);\n"
     "    r->left = new TreeNode(9); r->right = new TreeNode(20);\n"
     "    r->right->left = new TreeNode(15); r->right->right = new TreeNode(7);\n"
     "    auto res = sol.levelOrder(r);\n"
     "    for(auto& lv : res){ for(int x : lv) cout << x << \" \"; cout << \"\\n\"; }"),

    ("98_validate_binary_search_tree",
     "98. Validate Binary Search Tree", "Medium",
     "Tree, DFS, Binary Search Tree",
     "Given the root of a binary tree, determine if it is a valid binary\n"
     " * search tree (BST).",
     "The number of nodes in the tree is in the range [1, 10^4].\n"
     " * -2^31 <= Node.val <= 2^31 - 1",
     TREE_HEADER,
     "bool isValidBST(TreeNode* root)",
     "// [2,1,3] → true\n"
     "    TreeNode* r1 = new TreeNode(2);\n"
     "    r1->left = new TreeNode(1); r1->right = new TreeNode(3);\n"
     '    cout << sol.isValidBST(r1) << "\\n"; // 1\n'
     "    // [5,1,4,null,null,3,6] → false\n"
     "    TreeNode* r2 = new TreeNode(5);\n"
     "    r2->left = new TreeNode(1); r2->right = new TreeNode(4);\n"
     "    r2->right->left = new TreeNode(3); r2->right->right = new TreeNode(6);\n"
     '    cout << sol.isValidBST(r2) << "\\n"; // 0'),

    ("230_kth_smallest_element_in_bst",
     "230. Kth Smallest Element in a BST", "Medium",
     "Tree, DFS, Binary Search Tree",
     "Given the root of a binary search tree, and an integer k, return the\n"
     " * kth smallest value (1-indexed) of all the values of the nodes in the tree.",
     "The number of nodes in the tree is n.\n"
     " * 1 <= k <= n <= 10^4\n"
     " * 0 <= Node.val <= 10^4",
     TREE_HEADER,
     "int kthSmallest(TreeNode* root, int k)",
     "// [3,1,4,null,2], k=1 → 1\n"
     "    TreeNode* r = new TreeNode(3);\n"
     "    r->left = new TreeNode(1); r->right = new TreeNode(4);\n"
     "    r->left->right = new TreeNode(2);\n"
     '    cout << sol.kthSmallest(r, 1) << "\\n"; // 1\n'
     '    cout << sol.kthSmallest(r, 2) << "\\n"; // 2'),

    ("105_construct_binary_tree",
     "105. Construct Binary Tree from Preorder and Inorder Traversal", "Medium",
     "Array, Hash Table, Divide and Conquer, Tree",
     "Given two integer arrays preorder and inorder where preorder is the\n"
     " * preorder traversal of a binary tree and inorder is the inorder\n"
     " * traversal of the same tree, construct and return the binary tree.",
     "1 <= preorder.length <= 3000\n"
     " * inorder.length == preorder.length\n"
     " * -3000 <= preorder[i], inorder[i] <= 3000\n"
     " * All values are unique.",
     "#include <iostream>\n#include <vector>\n#include <unordered_map>\nusing namespace std;\n\n"
     "struct TreeNode {\n"
     "    int val;\n"
     "    TreeNode* left;\n"
     "    TreeNode* right;\n"
     "    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}\n"
     "};",
     "TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)",
     "    vector<int> pre = {3,9,20,15,7}, in = {9,3,15,20,7};\n"
     "    TreeNode* r = sol.buildTree(pre, in);\n"
     '    cout << (r ? r->val : -1) << "\\n"; // 3 (root)'),

    ("124_binary_tree_maximum_path_sum",
     "124. Binary Tree Maximum Path Sum", "Hard",
     "Dynamic Programming, Tree, DFS, Binary Tree",
     "A path in a binary tree is a sequence of nodes where each pair of\n"
     " * adjacent nodes has an edge. The path does not need to pass through\n"
     " * the root. Return the maximum path sum of any non-empty path.",
     "The number of nodes in the tree is in the range [1, 3 * 10^4].\n"
     " * -1000 <= Node.val <= 1000",
     TREE_HEADER,
     "int maxPathSum(TreeNode* root)",
     "// [1,2,3] → 6\n"
     "    TreeNode* r1 = new TreeNode(1);\n"
     "    r1->left = new TreeNode(2); r1->right = new TreeNode(3);\n"
     '    cout << sol.maxPathSum(r1) << "\\n"; // 6\n'
     "    // [-10,9,20,null,null,15,7] → 42\n"
     "    TreeNode* r2 = new TreeNode(-10);\n"
     "    r2->left = new TreeNode(9); r2->right = new TreeNode(20);\n"
     "    r2->right->left = new TreeNode(15); r2->right->right = new TreeNode(7);\n"
     '    cout << sol.maxPathSum(r2) << "\\n"; // 42'),

    ("297_serialize_and_deserialize_binary_tree",
     "297. Serialize and Deserialize Binary Tree", "Hard",
     "String, Tree, DFS, BFS, Design, Binary Tree",
     "Design an algorithm to serialize and deserialize a binary tree.\n"
     " * Serialization is the process of converting a data structure into a\n"
     " * sequence of bits so that it can be stored or transmitted and\n"
     " * reconstructed later.",
     "The number of nodes in the tree is in the range [0, 10^4].\n"
     " * -1000 <= Node.val <= 1000",
     "#include <iostream>\n#include <string>\n#include <sstream>\n#include <queue>\nusing namespace std;\n\n"
     "struct TreeNode {\n"
     "    int val;\n"
     "    TreeNode* left;\n"
     "    TreeNode* right;\n"
     "    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}\n"
     "};",
     "// Design Codec class with serialize() and deserialize()",
     "    // Codec codec;\n"
     "    TreeNode* r = new TreeNode(1);\n"
     "    r->left = new TreeNode(2); r->right = new TreeNode(3);\n"
     "    r->right->left = new TreeNode(4); r->right->right = new TreeNode(5);\n"
     "    // string s = codec.serialize(r);\n"
     "    // TreeNode* res = codec.deserialize(s);\n"
     '    // cout << (res ? res->val : -1) << "\\n"; // 1\n'
     '    cout << "Codec design problem" << "\\n";'),
]


TEMPLATE = """\
/*
 * {title}
 * Difficulty: {difficulty}
 * Tags: {tags}
 *
 * Description:
 * {description}
 *
 * Constraints:
 * - {constraints}
 */

{includes}

class Solution {{
public:
    {solution_sig} {{

    }}
}};

int main() {{
    Solution sol;

    {test_main}

    return 0;
}}
"""


def make_file(out_dir, fname, title, difficulty, tags, description,
              constraints, includes, solution_sig, test_main):
    content = TEMPLATE.format(
        title=title,
        difficulty=difficulty,
        tags=tags,
        description=description,
        constraints=constraints,
        includes=includes,
        solution_sig=solution_sig,
        test_main=test_main,
    )
    path = os.path.join(out_dir, fname + ".cpp")
    with open(path, "w") as f:
        f.write(content)
    print(f"Created {fname}.cpp")


for p in problems:
    make_file(OUT, *p)

print(f"\nDone — {len(problems)} files created in {OUT}/")
