#!/usr/bin/env python3
"""Generate phase2 problem template files for blind75."""

import os

OUT = os.path.join(os.path.dirname(__file__), "phase2")

LINKED_LIST_HEADER = """\
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
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
};
"""

DEFAULT_HEADER = """\
#include <iostream>
#include <vector>
using namespace std;
"""

problems = [
    # (filename, title, difficulty, tags, description, constraints, includes, solution_sig, test_main)

    # ── Easy (not yet in phase1) ─────────────────────────────────────────
    ("70_climbing_stairs", "70. Climbing Stairs", "Easy",
     "Math, Dynamic Programming, Memoization",
     "You are climbing a staircase. It takes n steps to reach the top.\n"
     " * Each time you can either climb 1 or 2 steps.\n"
     " * In how many distinct ways can you climb to the top?",
     "1 <= n <= 45",
     "#include <iostream>\nusing namespace std;",
     "int climbStairs(int n)",
     'cout << sol.climbStairs(2) << "\\n"; // 2\n'
     '    cout << sol.climbStairs(3) << "\\n"; // 3'),

    ("100_same_tree", "100. Same Tree", "Easy",
     "Tree, DFS, BFS, Binary Tree",
     "Given the roots of two binary trees p and q, write a function to check\n"
     " * if they are the same or not.",
     "The number of nodes in both trees is in the range [0, 100].\n"
     " * -10^4 <= Node.val <= 10^4",
     TREE_HEADER.strip(),
     "bool isSameTree(TreeNode* p, TreeNode* q)",
     "// p = [1,2,3], q = [1,2,3] → true\n"
     "    TreeNode* p1 = new TreeNode(1);\n"
     "    p1->left = new TreeNode(2); p1->right = new TreeNode(3);\n"
     "    TreeNode* q1 = new TreeNode(1);\n"
     "    q1->left = new TreeNode(2); q1->right = new TreeNode(3);\n"
     '    cout << sol.isSameTree(p1, q1) << "\\n"; // 1\n'
     "    // p = [1,2], q = [1,null,2] → false\n"
     "    TreeNode* p2 = new TreeNode(1); p2->left = new TreeNode(2);\n"
     "    TreeNode* q2 = new TreeNode(1); q2->right = new TreeNode(2);\n"
     '    cout << sol.isSameTree(p2, q2) << "\\n"; // 0'),

    ("104_maximum_depth_of_binary_tree", "104. Maximum Depth of Binary Tree", "Easy",
     "Tree, DFS, BFS, Binary Tree",
     "Given the root of a binary tree, return its maximum depth.\n"
     " * A binary tree's maximum depth is the number of nodes along the\n"
     " * longest path from the root node down to the farthest leaf node.",
     "The number of nodes in the tree is in the range [0, 10^4].\n"
     " * -100 <= Node.val <= 100",
     TREE_HEADER.strip(),
     "int maxDepth(TreeNode* root)",
     "// [3,9,20,null,null,15,7] → 3\n"
     "    TreeNode* r1 = new TreeNode(3);\n"
     "    r1->left = new TreeNode(9);\n"
     "    r1->right = new TreeNode(20);\n"
     "    r1->right->left = new TreeNode(15);\n"
     "    r1->right->right = new TreeNode(7);\n"
     '    cout << sol.maxDepth(r1) << "\\n"; // 3\n'
     '    cout << sol.maxDepth(new TreeNode(1)) << "\\n"; // 1'),

    ("141_linked_list_cycle", "141. Linked List Cycle", "Easy",
     "Hash Table, Linked List, Two Pointers",
     "Given head, the head of a linked list, determine if the linked list\n"
     " * has a cycle in it.",
     "The number of the nodes in the list is in the range [0, 10^4].\n"
     " * -10^5 <= Node.val <= 10^5",
     LINKED_LIST_HEADER.strip(),
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

    ("206_reverse_linked_list", "206. Reverse Linked List", "Easy",
     "Linked List, Recursion",
     "Given the head of a singly linked list, reverse the list,\n"
     " * and return the reversed list.",
     "The number of nodes in the list is the range [0, 5000].\n"
     " * -5000 <= Node.val <= 5000",
     LINKED_LIST_HEADER.strip(),
     "ListNode* reverseList(ListNode* head)",
     "// [1,2,3,4,5] → [5,4,3,2,1]\n"
     "    ListNode* h = new ListNode(1);\n"
     "    h->next = new ListNode(2);\n"
     "    h->next->next = new ListNode(3);\n"
     "    ListNode* r = sol.reverseList(h);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    ("21_merge_two_sorted_lists", "21. Merge Two Sorted Lists", "Easy",
     "Linked List, Recursion",
     "You are given the heads of two sorted linked lists list1 and list2.\n"
     " * Merge the two lists into one sorted list and return the head.",
     "The number of nodes in both lists is in the range [0, 50].\n"
     " * -100 <= Node.val <= 100",
     LINKED_LIST_HEADER.strip(),
     "ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)",
     "// [1,2,4] + [1,3,4] → [1,1,2,3,4,4]\n"
     "    ListNode* l1 = new ListNode(1);\n"
     "    l1->next = new ListNode(2); l1->next->next = new ListNode(4);\n"
     "    ListNode* l2 = new ListNode(1);\n"
     "    l2->next = new ListNode(3); l2->next->next = new ListNode(4);\n"
     "    ListNode* r = sol.mergeTwoLists(l1, l2);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    ("226_invert_binary_tree", "226. Invert Binary Tree", "Easy",
     "Tree, DFS, BFS, Binary Tree",
     "Given the root of a binary tree, invert the tree, and return its root.",
     "The number of nodes in the tree is in the range [0, 100].\n"
     " * -100 <= Node.val <= 100",
     TREE_HEADER.strip(),
     "TreeNode* invertTree(TreeNode* root)",
     "// [4,2,7,1,3,6,9] → [4,7,2,9,6,3,1]\n"
     "    TreeNode* r = new TreeNode(4);\n"
     "    r->left = new TreeNode(2); r->right = new TreeNode(7);\n"
     "    r->left->left = new TreeNode(1); r->left->right = new TreeNode(3);\n"
     "    r->right->left = new TreeNode(6); r->right->right = new TreeNode(9);\n"
     "    TreeNode* res = sol.invertTree(r);\n"
     "    // BFS print\n"
     "    queue<TreeNode*> q; q.push(res);\n"
     "    while(!q.empty()){\n"
     "        TreeNode* cur = q.front(); q.pop();\n"
     '        cout << cur->val << " ";\n'
     "        if(cur->left) q.push(cur->left);\n"
     "        if(cur->right) q.push(cur->right);\n"
     '    } cout << "\\n";'),

    ("572_subtree_of_another_tree", "572. Subtree of Another Tree", "Easy",
     "Tree, DFS, Binary Tree, String Matching",
     "Given the roots of two binary trees root and subRoot, return true if\n"
     " * there is a subtree of root with the same structure and node values\n"
     " * as subRoot, and false otherwise.",
     "The number of nodes in the root tree is in the range [1, 2000].\n"
     " * The number of nodes in the subRoot tree is in the range [1, 1000].\n"
     " * -10^4 <= root.val, subRoot.val <= 10^4",
     TREE_HEADER.strip(),
     "bool isSubtree(TreeNode* root, TreeNode* subRoot)",
     "// root=[3,4,5,1,2], subRoot=[4,1,2] → true\n"
     "    TreeNode* root = new TreeNode(3);\n"
     "    root->left = new TreeNode(4); root->right = new TreeNode(5);\n"
     "    root->left->left = new TreeNode(1); root->left->right = new TreeNode(2);\n"
     "    TreeNode* sub = new TreeNode(4);\n"
     "    sub->left = new TreeNode(1); sub->right = new TreeNode(2);\n"
     '    cout << sol.isSubtree(root, sub) << "\\n"; // 1'),

    # ── Medium ────────────────────────────────────────────────────────────
    ("3_longest_substring_without_repeating_characters",
     "3. Longest Substring Without Repeating Characters", "Medium",
     "Hash Table, String, Sliding Window",
     "Given a string s, find the length of the longest substring without\n"
     " * repeating characters.",
     "0 <= s.length <= 5 * 10^4\n"
     " * s consists of English letters, digits, symbols and spaces.",
     "#include <iostream>\n#include <string>\n#include <unordered_map>\nusing namespace std;",
     "int lengthOfLongestSubstring(string s)",
     '    cout << sol.lengthOfLongestSubstring("abcabcbb") << "\\n"; // 3\n'
     '    cout << sol.lengthOfLongestSubstring("bbbbb") << "\\n"; // 1\n'
     '    cout << sol.lengthOfLongestSubstring("pwwkew") << "\\n"; // 3'),

    ("5_longest_palindromic_substring", "5. Longest Palindromic Substring", "Medium",
     "String, Dynamic Programming",
     "Given a string s, return the longest palindromic substring in s.",
     "1 <= s.length <= 1000\n"
     " * s consist of only digits and English letters.",
     "#include <iostream>\n#include <string>\nusing namespace std;",
     "string longestPalindrome(string s)",
     '    cout << sol.longestPalindrome("babad") << "\\n"; // "bab" or "aba"\n'
     '    cout << sol.longestPalindrome("cbbd") << "\\n"; // "bb"'),

    ("11_container_with_most_water", "11. Container With Most Water", "Medium",
     "Array, Two Pointers, Greedy",
     "You are given an integer array height of length n. There are n vertical\n"
     " * lines drawn such that the two endpoints of the ith line are (i, 0)\n"
     " * and (i, height[i]).\n"
     " * Find two lines that together with the x-axis form a container, such\n"
     " * that the container contains the most water.",
     "n == height.length\n"
     " * 2 <= n <= 10^5\n"
     " * 0 <= height[i] <= 10^4",
     DEFAULT_HEADER.strip(),
     "int maxArea(vector<int>& height)",
     "    vector<int> h1 = {1,8,6,2,5,4,8,3,7};\n"
     '    cout << sol.maxArea(h1) << "\\n"; // 49\n'
     "    vector<int> h2 = {1,1};\n"
     '    cout << sol.maxArea(h2) << "\\n"; // 1'),

    ("15_3sum", "15. 3Sum", "Medium",
     "Array, Two Pointers, Sorting",
     "Given an integer array nums, return all the triplets [nums[i], nums[j],\n"
     " * nums[k]] such that i != j, i != k, and j != k, and\n"
     " * nums[i] + nums[j] + nums[k] == 0.\n"
     " * The solution set must not contain duplicate triplets.",
     "3 <= nums.length <= 3000\n"
     " * -10^5 <= nums[i] <= 10^5",
     "#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;",
     "vector<vector<int>> threeSum(vector<int>& nums)",
     "    vector<int> n1 = {-1,0,1,2,-1,-4};\n"
     "    auto r1 = sol.threeSum(n1);\n"
     "    for(auto& v : r1){ for(int x : v) cout << x << \" \"; cout << \"\\n\"; }\n"
     "    // [[-1,-1,2],[-1,0,1]]"),

    ("19_remove_nth_node_from_end", "19. Remove Nth Node From End of List", "Medium",
     "Linked List, Two Pointers",
     "Given the head of a linked list, remove the nth node from the end of\n"
     " * the list and return its head.",
     "The number of nodes in the list is sz.\n"
     " * 1 <= sz <= 30\n"
     " * 0 <= Node.val <= 100\n"
     " * 1 <= n <= sz",
     LINKED_LIST_HEADER.strip(),
     "ListNode* removeNthFromEnd(ListNode* head, int n)",
     "// [1,2,3,4,5], n=2 → [1,2,3,5]\n"
     "    ListNode* h = new ListNode(1);\n"
     "    h->next = new ListNode(2); h->next->next = new ListNode(3);\n"
     "    h->next->next->next = new ListNode(4);\n"
     "    h->next->next->next->next = new ListNode(5);\n"
     "    ListNode* r = sol.removeNthFromEnd(h, 2);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    ("33_search_in_rotated_sorted_array", "33. Search in Rotated Sorted Array", "Medium",
     "Array, Binary Search",
     "Given the array nums after the possible rotation and an integer target,\n"
     " * return the index of target if it is in nums, or -1 if it is not.",
     "1 <= nums.length <= 5000\n"
     " * -10^4 <= nums[i] <= 10^4\n"
     " * All values of nums are unique.\n"
     " * -10^4 <= target <= 10^4",
     DEFAULT_HEADER.strip(),
     "int search(vector<int>& nums, int target)",
     "    vector<int> n1 = {4,5,6,7,0,1,2};\n"
     '    cout << sol.search(n1, 0) << "\\n"; // 4\n'
     '    cout << sol.search(n1, 3) << "\\n"; // -1'),

    ("39_combination_sum", "39. Combination Sum", "Medium",
     "Array, Backtracking",
     "Given an array of distinct integers candidates and a target integer\n"
     " * target, return a list of all unique combinations of candidates where\n"
     " * the chosen numbers sum to target. You may use the same number\n"
     " * unlimited times.",
     "1 <= candidates.length <= 30\n"
     " * 2 <= candidates[i] <= 40\n"
     " * All elements of candidates are distinct.\n"
     " * 1 <= target <= 40",
     "#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;",
     "vector<vector<int>> combinationSum(vector<int>& candidates, int target)",
     "    vector<int> c = {2,3,6,7};\n"
     "    auto r = sol.combinationSum(c, 7);\n"
     "    for(auto& v : r){ for(int x : v) cout << x << \" \"; cout << \"\\n\"; }\n"
     "    // [[2,2,3],[7]]"),

    ("46_permutations", "46. Permutations", "Medium",
     "Array, Backtracking",
     "Given an array nums of distinct integers, return all the possible\n"
     " * permutations.",
     "1 <= nums.length <= 6\n"
     " * -10 <= nums[i] <= 10\n"
     " * All the integers of nums are unique.",
     DEFAULT_HEADER.strip(),
     "vector<vector<int>> permute(vector<int>& nums)",
     "    vector<int> n = {1,2,3};\n"
     "    auto r = sol.permute(n);\n"
     '    cout << r.size() << "\\n"; // 6'),

    ("48_rotate_image", "48. Rotate Image", "Medium",
     "Array, Math, Matrix",
     "You are given an n x n 2D matrix representing an image. Rotate the\n"
     " * image by 90 degrees (clockwise). You must rotate the image in-place.",
     "n == matrix.length == matrix[i].length\n"
     " * 1 <= n <= 20\n"
     " * -1000 <= matrix[i][j] <= 1000",
     "#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;",
     "void rotate(vector<vector<int>>& matrix)",
     "    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};\n"
     "    sol.rotate(m);\n"
     "    for(auto& row : m){ for(int x : row) cout << x << \" \"; cout << \"\\n\"; }\n"
     "    // [[7,4,1],[8,5,2],[9,6,3]]"),

    ("49_group_anagrams", "49. Group Anagrams", "Medium",
     "Array, Hash Table, String, Sorting",
     "Given an array of strings strs, group the anagrams together.",
     "1 <= strs.length <= 10^4\n"
     " * 0 <= strs[i].length <= 100\n"
     " * strs[i] consists of lowercase English letters.",
     "#include <iostream>\n#include <vector>\n#include <string>\n"
     "#include <unordered_map>\n#include <algorithm>\nusing namespace std;",
     "vector<vector<string>> groupAnagrams(vector<string>& strs)",
     '    vector<string> s = {"eat","tea","tan","ate","nat","bat"};\n'
     "    auto r = sol.groupAnagrams(s);\n"
     '    cout << r.size() << "\\n"; // 3'),

    ("54_spiral_matrix", "54. Spiral Matrix", "Medium",
     "Array, Matrix, Simulation",
     "Given an m x n matrix, return all elements of the matrix in spiral order.",
     "m == matrix.length\n"
     " * n == matrix[i].length\n"
     " * 1 <= m, n <= 10\n"
     " * -100 <= matrix[i][j] <= 100",
     DEFAULT_HEADER.strip(),
     "vector<int> spiralOrder(vector<vector<int>>& matrix)",
     "    vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};\n"
     "    auto r = sol.spiralOrder(m);\n"
     "    for(int x : r) cout << x << \" \";\n"
     '    cout << "\\n"; // 1 2 3 6 9 8 7 4 5'),

    ("56_merge_intervals", "56. Merge Intervals", "Medium",
     "Array, Sorting",
     "Given an array of intervals where intervals[i] = [starti, endi], merge\n"
     " * all overlapping intervals, and return an array of the non-overlapping\n"
     " * intervals that cover all the intervals in the input.",
     "1 <= intervals.length <= 10^4\n"
     " * intervals[i].length == 2\n"
     " * 0 <= starti <= endi <= 10^4",
     "#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;",
     "vector<vector<int>> merge(vector<vector<int>>& intervals)",
     "    vector<vector<int>> iv = {{1,3},{2,6},{8,10},{15,18}};\n"
     "    auto r = sol.merge(iv);\n"
     "    for(auto& v : r) cout << \"[\" << v[0] << \",\" << v[1] << \"] \";\n"
     '    cout << "\\n"; // [1,6] [8,10] [15,18]'),

    ("57_insert_interval", "57. Insert Interval", "Medium",
     "Array",
     "You are given an array of non-overlapping intervals sorted in ascending\n"
     " * order by start point, and a new interval. Insert the interval and\n"
     " * merge if necessary.",
     "0 <= intervals.length <= 10^4\n"
     " * intervals[i].length == 2\n"
     " * 0 <= starti <= endi <= 10^5",
     DEFAULT_HEADER.strip(),
     "vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)",
     "    vector<vector<int>> iv = {{1,3},{6,9}};\n"
     "    vector<int> ni = {2,5};\n"
     "    auto r = sol.insert(iv, ni);\n"
     "    for(auto& v : r) cout << \"[\" << v[0] << \",\" << v[1] << \"] \";\n"
     '    cout << "\\n"; // [1,5] [6,9]'),

    ("62_unique_paths", "62. Unique Paths", "Medium",
     "Math, Dynamic Programming, Combinatorics",
     "There is a robot on an m x n grid. The robot is initially located at\n"
     " * the top-left corner. The robot tries to move to the bottom-right\n"
     " * corner. The robot can only move either down or right at any point.\n"
     " * Given the two integers m and n, return the number of possible unique\n"
     " * paths.",
     "1 <= m, n <= 100",
     "#include <iostream>\nusing namespace std;",
     "int uniquePaths(int m, int n)",
     '    cout << sol.uniquePaths(3, 7) << "\\n"; // 28\n'
     '    cout << sol.uniquePaths(3, 2) << "\\n"; // 3'),

    ("72_edit_distance", "72. Edit Distance", "Medium",
     "String, Dynamic Programming",
     "Given two strings word1 and word2, return the minimum number of\n"
     " * operations required to convert word1 to word2.\n"
     " * Operations: insert, delete, or replace a character.",
     "0 <= word1.length, word2.length <= 500\n"
     " * word1 and word2 consist of lowercase English letters.",
     "#include <iostream>\n#include <string>\n#include <vector>\nusing namespace std;",
     "int minDistance(string word1, string word2)",
     '    cout << sol.minDistance("horse", "ros") << "\\n"; // 3\n'
     '    cout << sol.minDistance("intention", "execution") << "\\n"; // 5'),

    ("73_set_matrix_zeroes", "73. Set Matrix Zeroes", "Medium",
     "Array, Hash Table, Matrix",
     "Given an m x n integer matrix, if an element is 0, set its entire\n"
     " * row and column to 0's. Do it in place.",
     "m == matrix.length\n"
     " * n == matrix[0].length\n"
     " * 1 <= m, n <= 200\n"
     " * -2^31 <= matrix[i][j] <= 2^31 - 1",
     DEFAULT_HEADER.strip(),
     "void setZeroes(vector<vector<int>>& matrix)",
     "    vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};\n"
     "    sol.setZeroes(m);\n"
     "    for(auto& row : m){ for(int x : row) cout << x << \" \"; cout << \"\\n\"; }\n"
     "    // [[1,0,1],[0,0,0],[1,0,1]]"),

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
     DEFAULT_HEADER.strip(),
     "bool searchMatrix(vector<vector<int>>& matrix, int target)",
     "    vector<vector<int>> m = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};\n"
     '    cout << sol.searchMatrix(m, 3) << "\\n"; // 1\n'
     '    cout << sol.searchMatrix(m, 13) << "\\n"; // 0'),

    ("78_subsets", "78. Subsets", "Medium",
     "Array, Backtracking, Bit Manipulation",
     "Given an integer array nums of unique elements, return all possible\n"
     " * subsets (the power set). The solution set must not contain duplicate\n"
     " * subsets.",
     "1 <= nums.length <= 10\n"
     " * -10 <= nums[i] <= 10\n"
     " * All the numbers of nums are unique.",
     DEFAULT_HEADER.strip(),
     "vector<vector<int>> subsets(vector<int>& nums)",
     "    vector<int> n = {1,2,3};\n"
     "    auto r = sol.subsets(n);\n"
     '    cout << r.size() << "\\n"; // 8'),

    ("79_word_search", "79. Word Search", "Medium",
     "Array, Backtracking, Matrix, DFS",
     "Given an m x n grid of characters board and a string word, return true\n"
     " * if word exists in the grid. The word can be constructed from letters\n"
     " * of sequentially adjacent cells (horizontally or vertically adjacent).\n"
     " * The same letter cell may not be used more than once.",
     "m == board.length\n"
     " * n == board[i].length\n"
     " * 1 <= m, n <= 6\n"
     " * 1 <= word.length <= 15",
     "#include <iostream>\n#include <vector>\n#include <string>\nusing namespace std;",
     "bool exist(vector<vector<char>>& board, string word)",
     "    vector<vector<char>> b = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};\n"
     '    cout << sol.exist(b, "ABCCED") << "\\n"; // 1\n'
     '    cout << sol.exist(b, "SEE") << "\\n"; // 1\n'
     '    cout << sol.exist(b, "ABCB") << "\\n"; // 0'),

    ("91_decode_ways", "91. Decode Ways", "Medium",
     "String, Dynamic Programming",
     "A message containing letters from A-Z can be encoded into numbers using\n"
     " * '1' -> 'A', ..., '26' -> 'Z'. Given a string s of digits, return the\n"
     " * number of ways to decode it.",
     "1 <= s.length <= 100\n"
     " * s contains only digits and may contain leading zero(s).",
     "#include <iostream>\n#include <string>\n#include <vector>\nusing namespace std;",
     "int numDecodings(string s)",
     '    cout << sol.numDecodings("12") << "\\n"; // 2\n'
     '    cout << sol.numDecodings("226") << "\\n"; // 3\n'
     '    cout << sol.numDecodings("06") << "\\n"; // 0'),

    ("98_validate_binary_search_tree", "98. Validate Binary Search Tree", "Medium",
     "Tree, DFS, Binary Search Tree",
     "Given the root of a binary tree, determine if it is a valid binary\n"
     " * search tree (BST).",
     "The number of nodes in the tree is in the range [1, 10^4].\n"
     " * -2^31 <= Node.val <= 2^31 - 1",
     TREE_HEADER.strip(),
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

    ("102_binary_tree_level_order_traversal",
     "102. Binary Tree Level Order Traversal", "Medium",
     "Tree, BFS, Binary Tree",
     "Given the root of a binary tree, return the level order traversal of\n"
     " * its nodes' values (i.e., from left to right, level by level).",
     "The number of nodes in the tree is in the range [0, 2000].\n"
     " * -1000 <= Node.val <= 1000",
     TREE_HEADER.strip(),
     "vector<vector<int>> levelOrder(TreeNode* root)",
     "// [3,9,20,null,null,15,7] → [[3],[9,20],[15,7]]\n"
     "    TreeNode* r = new TreeNode(3);\n"
     "    r->left = new TreeNode(9); r->right = new TreeNode(20);\n"
     "    r->right->left = new TreeNode(15); r->right->right = new TreeNode(7);\n"
     "    auto res = sol.levelOrder(r);\n"
     "    for(auto& lv : res){ for(int x : lv) cout << x << \" \"; cout << \"\\n\"; }"),

    ("105_construct_binary_tree", "105. Construct Binary Tree from Preorder and Inorder Traversal",
     "Medium",
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
     '    cout << (r ? r->val : -1) << "\\n"; // 3'),

    ("128_longest_consecutive_sequence", "128. Longest Consecutive Sequence", "Medium",
     "Array, Hash Table, Union Find",
     "Given an unsorted array of integers nums, return the length of the\n"
     " * longest consecutive elements sequence. Must run in O(n).",
     "0 <= nums.length <= 10^5\n"
     " * -10^9 <= nums[i] <= 10^9",
     "#include <iostream>\n#include <vector>\n#include <unordered_set>\nusing namespace std;",
     "int longestConsecutive(vector<int>& nums)",
     "    vector<int> n1 = {100,4,200,1,3,2};\n"
     '    cout << sol.longestConsecutive(n1) << "\\n"; // 4\n'
     "    vector<int> n2 = {0,3,7,2,5,8,4,6,0,1};\n"
     '    cout << sol.longestConsecutive(n2) << "\\n"; // 9'),

    ("133_clone_graph", "133. Clone Graph", "Medium",
     "Hash Table, DFS, BFS, Graph",
     "Given a reference of a node in a connected undirected graph, return a\n"
     " * deep copy (clone) of the graph.",
     "The number of nodes in the graph is in the range [0, 100].\n"
     " * 1 <= Node.val <= 100\n"
     " * Node.val is unique for each node.",
     "#include <iostream>\n#include <vector>\n#include <unordered_map>\nusing namespace std;\n\n"
     "class Node {\npublic:\n"
     "    int val;\n"
     "    vector<Node*> neighbors;\n"
     "    Node(int v) : val(v) {}\n"
     "};",
     "Node* cloneGraph(Node* node)",
     "    Node* n1 = new Node(1); Node* n2 = new Node(2);\n"
     "    Node* n3 = new Node(3); Node* n4 = new Node(4);\n"
     "    n1->neighbors = {n2,n4}; n2->neighbors = {n1,n3};\n"
     "    n3->neighbors = {n2,n4}; n4->neighbors = {n1,n3};\n"
     "    Node* r = sol.cloneGraph(n1);\n"
     '    cout << (r ? r->val : -1) << "\\n"; // 1'),

    ("139_word_break", "139. Word Break", "Medium",
     "Hash Table, String, Dynamic Programming, Trie, Memoization",
     "Given a string s and a dictionary of strings wordDict, return true if s\n"
     " * can be segmented into a space-separated sequence of one or more\n"
     " * dictionary words.",
     "1 <= s.length <= 300\n"
     " * 1 <= wordDict.length <= 1000\n"
     " * 1 <= wordDict[i].length <= 20",
     "#include <iostream>\n#include <string>\n#include <vector>\n"
     "#include <unordered_set>\nusing namespace std;",
     "bool wordBreak(string s, vector<string>& wordDict)",
     '    vector<string> d1 = {"leet","code"};\n'
     '    cout << sol.wordBreak("leetcode", d1) << "\\n"; // 1\n'
     '    vector<string> d2 = {"apple","pen"};\n'
     '    cout << sol.wordBreak("applepenapple", d2) << "\\n"; // 1'),

    ("143_reorder_list", "143. Reorder List", "Medium",
     "Linked List, Two Pointers, Stack, Recursion",
     "You are given the head of a singly linked-list:\n"
     " * L0 → L1 → … → Ln-1 → Ln\n"
     " * Reorder it to: L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …\n"
     " * Do not modify the values in the nodes, only nodes themselves may be changed.",
     "The number of nodes in the list is in the range [1, 5 * 10^4].\n"
     " * 1 <= Node.val <= 1000",
     LINKED_LIST_HEADER.strip(),
     "void reorderList(ListNode* head)",
     "// [1,2,3,4] → [1,4,2,3]\n"
     "    ListNode* h = new ListNode(1);\n"
     "    h->next = new ListNode(2); h->next->next = new ListNode(3);\n"
     "    h->next->next->next = new ListNode(4);\n"
     "    sol.reorderList(h);\n"
     '    while(h){ cout << h->val << " "; h = h->next; } cout << "\\n";'),

    ("152_maximum_product_subarray", "152. Maximum Product Subarray", "Medium",
     "Array, Dynamic Programming",
     "Given an integer array nums, find a subarray that has the largest\n"
     " * product, and return the product.",
     "1 <= nums.length <= 2 * 10^4\n"
     " * -10 <= nums[i] <= 10",
     DEFAULT_HEADER.strip(),
     "int maxProduct(vector<int>& nums)",
     "    vector<int> n1 = {2,3,-2,4};\n"
     '    cout << sol.maxProduct(n1) << "\\n"; // 6\n'
     "    vector<int> n2 = {-2,0,-1};\n"
     '    cout << sol.maxProduct(n2) << "\\n"; // 0'),

    ("153_find_minimum_in_rotated_sorted_array",
     "153. Find Minimum in Rotated Sorted Array", "Medium",
     "Array, Binary Search",
     "Given the sorted rotated array nums of unique elements, return the\n"
     " * minimum element of this array. Must run in O(log n).",
     "n == nums.length\n"
     " * 1 <= n <= 5000\n"
     " * -5000 <= nums[i] <= 5000\n"
     " * All the integers of nums are unique.",
     DEFAULT_HEADER.strip(),
     "int findMin(vector<int>& nums)",
     "    vector<int> n1 = {3,4,5,1,2};\n"
     '    cout << sol.findMin(n1) << "\\n"; // 1\n'
     "    vector<int> n2 = {4,5,6,7,0,1,2};\n"
     '    cout << sol.findMin(n2) << "\\n"; // 0'),

    ("155_min_stack", "155. Min Stack", "Medium",
     "Stack, Design",
     "Design a stack that supports push, pop, top, and retrieving the\n"
     " * minimum element in constant time.",
     "-2^31 <= val <= 2^31 - 1\n"
     " * Methods pop, top and getMin operations will always be called on\n"
     "   non-empty stacks.",
     "#include <iostream>\n#include <stack>\nusing namespace std;",
     "// Design MinStack class",
     "    // MinStack ms;\n"
     "    // ms.push(-2); ms.push(0); ms.push(-3);\n"
     '    // cout << ms.getMin() << "\\n"; // -3\n'
     "    // ms.pop();\n"
     '    // cout << ms.top() << "\\n"; // 0\n'
     '    // cout << ms.getMin() << "\\n"; // -2\n'
     '    cout << "MinStack design problem" << "\\n";'),

    ("198_house_robber", "198. House Robber", "Medium",
     "Array, Dynamic Programming",
     "You are a professional robber. Given an integer array nums representing\n"
     " * the amount of money of each house, return the maximum amount of money\n"
     " * you can rob tonight without alerting the police (cannot rob two\n"
     " * adjacent houses).",
     "1 <= nums.length <= 100\n"
     " * 0 <= nums[i] <= 400",
     DEFAULT_HEADER.strip(),
     "int rob(vector<int>& nums)",
     "    vector<int> n1 = {1,2,3,1};\n"
     '    cout << sol.rob(n1) << "\\n"; // 4\n'
     "    vector<int> n2 = {2,7,9,3,1};\n"
     '    cout << sol.rob(n2) << "\\n"; // 12'),

    ("200_number_of_islands", "200. Number of Islands", "Medium",
     "Array, DFS, BFS, Union Find, Matrix",
     "Given an m x n 2D binary grid which represents a map of '1's (land)\n"
     " * and '0's (water), return the number of islands.",
     "m == grid.length\n"
     " * n == grid[i].length\n"
     " * 1 <= m, n <= 300\n"
     " * grid[i][j] is '0' or '1'.",
     "#include <iostream>\n#include <vector>\nusing namespace std;",
     "int numIslands(vector<vector<char>>& grid)",
     "    vector<vector<char>> g1 = {\n"
     "        {'1','1','1','1','0'},\n"
     "        {'1','1','0','1','0'},\n"
     "        {'1','1','0','0','0'},\n"
     "        {'0','0','0','0','0'}};\n"
     '    cout << sol.numIslands(g1) << "\\n"; // 1\n'
     "    vector<vector<char>> g2 = {\n"
     "        {'1','1','0','0','0'},\n"
     "        {'1','1','0','0','0'},\n"
     "        {'0','0','1','0','0'},\n"
     "        {'0','0','0','1','1'}};\n"
     '    cout << sol.numIslands(g2) << "\\n"; // 3'),

    ("207_course_schedule", "207. Course Schedule", "Medium",
     "DFS, BFS, Graph, Topological Sort",
     "There are a total of numCourses courses. You are given an array\n"
     " * prerequisites where prerequisites[i] = [ai, bi] indicates that you\n"
     " * must take course bi first if you want to take course ai.\n"
     " * Return true if you can finish all courses.",
     "1 <= numCourses <= 2000\n"
     " * 0 <= prerequisites.length <= 5000",
     DEFAULT_HEADER.strip(),
     "bool canFinish(int numCourses, vector<vector<int>>& prerequisites)",
     "    vector<vector<int>> p1 = {{1,0}};\n"
     '    cout << sol.canFinish(2, p1) << "\\n"; // 1\n'
     "    vector<vector<int>> p2 = {{1,0},{0,1}};\n"
     '    cout << sol.canFinish(2, p2) << "\\n"; // 0'),

    ("208_implement_trie", "208. Implement Trie (Prefix Tree)", "Medium",
     "Hash Table, String, Design, Trie",
     "Implement the Trie class with insert, search, and startsWith methods.",
     "1 <= word.length, prefix.length <= 2000\n"
     " * word and prefix consist only of lowercase English letters.\n"
     " * At most 3 * 10^4 calls in total to insert, search, and startsWith.",
     "#include <iostream>\n#include <string>\nusing namespace std;",
     "// Design Trie class",
     "    // Trie t;\n"
     '    // t.insert("apple");\n'
     '    // cout << t.search("apple") << "\\n"; // 1\n'
     '    // cout << t.search("app") << "\\n"; // 0\n'
     '    // cout << t.startsWith("app") << "\\n"; // 1\n'
     '    cout << "Trie design problem" << "\\n";'),

    ("211_design_add_and_search_words",
     "211. Design Add and Search Words Data Structure", "Medium",
     "String, DFS, Design, Trie",
     "Design a data structure that supports addWord and search where '.' can\n"
     " * match any letter.",
     "1 <= word.length <= 25\n"
     " * word in addWord consists of lowercase English letters.\n"
     " * word in search consist of '.' or lowercase English letters.",
     "#include <iostream>\n#include <string>\nusing namespace std;",
     "// Design WordDictionary class",
     "    // WordDictionary wd;\n"
     '    // wd.addWord("bad"); wd.addWord("dad"); wd.addWord("mad");\n'
     '    // cout << wd.search("pad") << "\\n"; // 0\n'
     '    // cout << wd.search("bad") << "\\n"; // 1\n'
     '    // cout << wd.search(".ad") << "\\n"; // 1\n'
     '    // cout << wd.search("b..") << "\\n"; // 1\n'
     '    cout << "WordDictionary design problem" << "\\n";'),

    ("213_house_robber_ii", "213. House Robber II", "Medium",
     "Array, Dynamic Programming",
     "All houses are arranged in a circle. Return the maximum amount you can\n"
     " * rob without robbing two adjacent houses (first and last are adjacent).",
     "1 <= nums.length <= 100\n"
     " * 0 <= nums[i] <= 1000",
     DEFAULT_HEADER.strip(),
     "int rob(vector<int>& nums)",
     "    vector<int> n1 = {2,3,2};\n"
     '    cout << sol.rob(n1) << "\\n"; // 3\n'
     "    vector<int> n2 = {1,2,3,1};\n"
     '    cout << sol.rob(n2) << "\\n"; // 4'),

    ("230_kth_smallest_element_in_bst", "230. Kth Smallest Element in a BST", "Medium",
     "Tree, DFS, Binary Search Tree",
     "Given the root of a binary search tree, and an integer k, return the\n"
     " * kth smallest value (1-indexed) of all the values of the nodes in the tree.",
     "The number of nodes in the tree is n.\n"
     " * 1 <= k <= n <= 10^4\n"
     " * 0 <= Node.val <= 10^4",
     TREE_HEADER.strip(),
     "int kthSmallest(TreeNode* root, int k)",
     "// [3,1,4,null,2], k=1 → 1\n"
     "    TreeNode* r = new TreeNode(3);\n"
     "    r->left = new TreeNode(1); r->right = new TreeNode(4);\n"
     "    r->left->right = new TreeNode(2);\n"
     '    cout << sol.kthSmallest(r, 1) << "\\n"; // 1'),

    ("235_lowest_common_ancestor_of_bst",
     "235. Lowest Common Ancestor of a Binary Search Tree", "Medium",
     "Tree, DFS, Binary Search Tree",
     "Given a BST and two nodes p and q, find their lowest common ancestor.",
     "The number of nodes in the tree is in the range [2, 10^5].\n"
     " * -10^9 <= Node.val <= 10^9\n"
     " * All Node.val are unique.",
     TREE_HEADER.strip(),
     "TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)",
     "// [6,2,8,0,4,7,9], p=2, q=8 → 6\n"
     "    TreeNode* r = new TreeNode(6);\n"
     "    r->left = new TreeNode(2); r->right = new TreeNode(8);\n"
     "    r->left->left = new TreeNode(0); r->left->right = new TreeNode(4);\n"
     "    r->right->left = new TreeNode(7); r->right->right = new TreeNode(9);\n"
     "    TreeNode* res = sol.lowestCommonAncestor(r, r->left, r->right);\n"
     '    cout << (res ? res->val : -1) << "\\n"; // 6'),

    ("238_product_of_array_except_self", "238. Product of Array Except Self", "Medium",
     "Array, Prefix Sum",
     "Given an integer array nums, return an array answer such that answer[i]\n"
     " * is equal to the product of all the elements of nums except nums[i].\n"
     " * Must run in O(n) without using the division operation.",
     "2 <= nums.length <= 10^5\n"
     " * -30 <= nums[i] <= 30",
     DEFAULT_HEADER.strip(),
     "vector<int> productExceptSelf(vector<int>& nums)",
     "    vector<int> n1 = {1,2,3,4};\n"
     "    auto r1 = sol.productExceptSelf(n1);\n"
     "    for(int x : r1) cout << x << \" \";\n"
     '    cout << "\\n"; // 24 12 8 6'),

    ("287_find_the_duplicate_number", "287. Find the Duplicate Number", "Medium",
     "Array, Two Pointers, Binary Search",
     "Given an array of integers nums containing n+1 integers where each\n"
     " * integer is in the range [1, n], there is only one repeated number.\n"
     " * Return this repeated number without modifying the array, using O(1) space.",
     "1 <= n <= 10^5\n"
     " * nums.length == n + 1\n"
     " * 1 <= nums[i] <= n",
     DEFAULT_HEADER.strip(),
     "int findDuplicate(vector<int>& nums)",
     "    vector<int> n1 = {1,3,4,2,2};\n"
     '    cout << sol.findDuplicate(n1) << "\\n"; // 2\n'
     "    vector<int> n2 = {3,1,3,4,2};\n"
     '    cout << sol.findDuplicate(n2) << "\\n"; // 3'),

    ("300_longest_increasing_subsequence", "300. Longest Increasing Subsequence", "Medium",
     "Array, Binary Search, Dynamic Programming",
     "Given an integer array nums, return the length of the longest strictly\n"
     " * increasing subsequence.",
     "1 <= nums.length <= 2500\n"
     " * -10^4 <= nums[i] <= 10^4",
     DEFAULT_HEADER.strip(),
     "int lengthOfLIS(vector<int>& nums)",
     "    vector<int> n1 = {10,9,2,5,3,7,101,18};\n"
     '    cout << sol.lengthOfLIS(n1) << "\\n"; // 4\n'
     "    vector<int> n2 = {0,1,0,3,2,3};\n"
     '    cout << sol.lengthOfLIS(n2) << "\\n"; // 4'),

    ("322_coin_change", "322. Coin Change", "Medium",
     "Array, Dynamic Programming, BFS",
     "Given an array of coins and an amount, return the fewest number of\n"
     " * coins needed to make up that amount. Return -1 if it's not possible.",
     "1 <= coins.length <= 12\n"
     " * 1 <= coins[i] <= 2^31 - 1\n"
     " * 0 <= amount <= 10^4",
     DEFAULT_HEADER.strip(),
     "int coinChange(vector<int>& coins, int amount)",
     "    vector<int> c1 = {1,5,6,9};\n"
     '    cout << sol.coinChange(c1, 11) << "\\n"; // 2\n'
     "    vector<int> c2 = {2};\n"
     '    cout << sol.coinChange(c2, 3) << "\\n"; // -1'),

    ("323_number_of_connected_components",
     "323. Number of Connected Components in an Undirected Graph", "Medium",
     "DFS, BFS, Union Find, Graph",
     "Given n nodes labeled from 0 to n-1 and a list of undirected edges,\n"
     " * return the number of connected components.",
     "1 <= n <= 2000\n"
     " * 1 <= edges.length <= 5000\n"
     " * edges[i].length == 2\n"
     " * 0 <= ai <= bi < n\n"
     " * ai != bi",
     DEFAULT_HEADER.strip(),
     "int countComponents(int n, vector<vector<int>>& edges)",
     "    vector<vector<int>> e1 = {{0,1},{1,2},{3,4}};\n"
     '    cout << sol.countComponents(5, e1) << "\\n"; // 2\n'
     "    vector<vector<int>> e2 = {{0,1},{1,2},{2,3},{3,4}};\n"
     '    cout << sol.countComponents(5, e2) << "\\n"; // 1'),

    ("347_top_k_frequent_elements", "347. Top K Frequent Elements", "Medium",
     "Array, Hash Table, Heap",
     "Given an integer array nums and an integer k, return the k most\n"
     " * frequent elements.",
     "1 <= nums.length <= 10^5\n"
     " * -10^4 <= nums[i] <= 10^4\n"
     " * k is in the range [1, the number of unique elements in the array].",
     "#include <iostream>\n#include <vector>\n#include <unordered_map>\n"
     "#include <queue>\nusing namespace std;",
     "vector<int> topKFrequent(vector<int>& nums, int k)",
     "    vector<int> n1 = {1,1,1,2,2,3};\n"
     "    auto r1 = sol.topKFrequent(n1, 2);\n"
     "    for(int x : r1) cout << x << \" \";\n"
     '    cout << "\\n"; // 1 2'),

    ("371_sum_of_two_integers", "371. Sum of Two Integers", "Medium",
     "Math, Bit Manipulation",
     "Given two integers a and b, return the sum of the two integers without\n"
     " * using the operators + and -.",
     "-1000 <= a, b <= 1000",
     "#include <iostream>\nusing namespace std;",
     "int getSum(int a, int b)",
     '    cout << sol.getSum(1, 2) << "\\n"; // 3\n'
     '    cout << sol.getSum(2, 3) << "\\n"; // 5'),

    ("416_partition_equal_subset_sum", "416. Partition Equal Subset Sum", "Medium",
     "Array, Dynamic Programming",
     "Given an integer array nums, return true if you can partition the array\n"
     " * into two subsets such that the sum of the elements in both subsets\n"
     " * is equal.",
     "1 <= nums.length <= 200\n"
     " * 1 <= nums[i] <= 100",
     DEFAULT_HEADER.strip(),
     "bool canPartition(vector<int>& nums)",
     "    vector<int> n1 = {1,5,11,5};\n"
     '    cout << sol.canPartition(n1) << "\\n"; // 1\n'
     "    vector<int> n2 = {1,2,3,5};\n"
     '    cout << sol.canPartition(n2) << "\\n"; // 0'),

    ("417_pacific_atlantic_water_flow", "417. Pacific Atlantic Water Flow", "Medium",
     "Array, DFS, BFS, Matrix",
     "Find all cells from which water can flow to both the Pacific and Atlantic\n"
     " * oceans.",
     "m == heights.length\n"
     " * n == heights[r].length\n"
     " * 1 <= m, n <= 200\n"
     " * 0 <= heights[i][j] <= 10^5",
     DEFAULT_HEADER.strip(),
     "vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)",
     "    vector<vector<int>> h = {{1,2,2,3,5},{3,2,3,4,4},\n"
     "                             {2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};\n"
     "    auto r = sol.pacificAtlantic(h);\n"
     '    cout << r.size() << "\\n"; // 7'),

    ("424_longest_repeating_character_replacement",
     "424. Longest Repeating Character Replacement", "Medium",
     "Hash Table, String, Sliding Window",
     "You are given a string s and an integer k. You can choose any character\n"
     " * of the string and change it to any other uppercase English character.\n"
     " * Return the length of the longest substring containing the same letter\n"
     " * you can get after performing the above operations at most k times.",
     "1 <= s.length <= 10^5\n"
     " * s consists of only uppercase English letters.\n"
     " * 0 <= k <= s.length",
     "#include <iostream>\n#include <string>\n#include <vector>\nusing namespace std;",
     "int characterReplacement(string s, int k)",
     '    cout << sol.characterReplacement("ABAB", 2) << "\\n"; // 4\n'
     '    cout << sol.characterReplacement("AABABBA", 1) << "\\n"; // 4'),

    ("435_non_overlapping_intervals", "435. Non-Overlapping Intervals", "Medium",
     "Array, Dynamic Programming, Greedy, Sorting",
     "Given an array of intervals, return the minimum number of intervals\n"
     " * you need to remove to make the rest of the intervals non-overlapping.",
     "1 <= intervals.length <= 10^5\n"
     " * intervals[i].length == 2\n"
     " * -5 * 10^4 <= starti < endi <= 5 * 10^4",
     "#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;",
     "int eraseOverlapIntervals(vector<vector<int>>& intervals)",
     "    vector<vector<int>> iv1 = {{1,2},{2,3},{3,4},{1,3}};\n"
     '    cout << sol.eraseOverlapIntervals(iv1) << "\\n"; // 1\n'
     "    vector<vector<int>> iv2 = {{1,2},{1,2},{1,2}};\n"
     '    cout << sol.eraseOverlapIntervals(iv2) << "\\n"; // 2'),

    ("647_palindromic_substrings", "647. Palindromic Substrings", "Medium",
     "String, Dynamic Programming",
     "Given a string s, return the number of palindromic substrings in it.",
     "1 <= s.length <= 1000\n"
     " * s consists of lowercase English letters.",
     "#include <iostream>\n#include <string>\nusing namespace std;",
     "int countSubstrings(string s)",
     '    cout << sol.countSubstrings("abc") << "\\n"; // 3\n'
     '    cout << sol.countSubstrings("aaa") << "\\n"; // 6'),

    ("261_graph_valid_tree", "261. Graph Valid Tree", "Medium",
     "DFS, BFS, Union Find, Graph",
     "You have a graph of n nodes labeled from 0 to n-1. Given an integer n\n"
     " * and a list of edges, return true if these edges make up a valid tree.",
     "1 <= n <= 2000\n"
     " * 0 <= edges.length <= 5000\n"
     " * edges[i].length == 2\n"
     " * 0 <= ai < bi < n",
     DEFAULT_HEADER.strip(),
     "bool validTree(int n, vector<vector<int>>& edges)",
     "    vector<vector<int>> e1 = {{0,1},{0,2},{0,3},{1,4}};\n"
     '    cout << sol.validTree(5, e1) << "\\n"; // 1\n'
     "    vector<vector<int>> e2 = {{0,1},{1,2},{2,3},{1,3},{1,4}};\n"
     '    cout << sol.validTree(5, e2) << "\\n"; // 0'),

    ("1143_longest_common_subsequence", "1143. Longest Common Subsequence", "Medium",
     "String, Dynamic Programming",
     "Given two strings text1 and text2, return the length of their longest\n"
     " * common subsequence.",
     "1 <= text1.length, text2.length <= 1000\n"
     " * text1 and text2 consist of only lowercase English letters.",
     "#include <iostream>\n#include <string>\n#include <vector>\nusing namespace std;",
     "int longestCommonSubsequence(string text1, string text2)",
     '    cout << sol.longestCommonSubsequence("abcde", "ace") << "\\n"; // 3\n'
     '    cout << sol.longestCommonSubsequence("abc", "abc") << "\\n"; // 3\n'
     '    cout << sol.longestCommonSubsequence("abc", "def") << "\\n"; // 0'),

    # ── Hard ─────────────────────────────────────────────────────────────
    ("4_median_of_two_sorted_arrays", "4. Median of Two Sorted Arrays", "Hard",
     "Array, Binary Search, Divide and Conquer",
     "Given two sorted arrays nums1 and nums2 of size m and n respectively,\n"
     " * return the median of the two sorted arrays. Must run in O(log(m+n)).",
     "nums1.length == m\n"
     " * nums2.length == n\n"
     " * 0 <= m <= 1000\n"
     " * 0 <= n <= 1000\n"
     " * -10^6 <= nums1[i], nums2[i] <= 10^6",
     DEFAULT_HEADER.strip(),
     "double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)",
     "    vector<int> n1 = {1,3}, n2 = {2};\n"
     '    cout << sol.findMedianSortedArrays(n1, n2) << "\\n"; // 2.0\n'
     "    vector<int> n3 = {1,2}, n4 = {3,4};\n"
     '    cout << sol.findMedianSortedArrays(n3, n4) << "\\n"; // 2.5'),

    ("10_regular_expression_matching", "10. Regular Expression Matching", "Hard",
     "String, Dynamic Programming, Recursion",
     "Given an input string s and a pattern p, implement regular expression\n"
     " * matching with support for '.' and '*'.\n"
     " * '.' matches any single character.\n"
     " * '*' matches zero or more of the preceding element.",
     "1 <= s.length <= 20\n"
     " * 1 <= p.length <= 20",
     "#include <iostream>\n#include <string>\n#include <vector>\nusing namespace std;",
     "bool isMatch(string s, string p)",
     '    cout << sol.isMatch("aa", "a") << "\\n"; // 0\n'
     '    cout << sol.isMatch("aa", "a*") << "\\n"; // 1\n'
     '    cout << sol.isMatch("ab", ".*") << "\\n"; // 1'),

    ("23_merge_k_sorted_lists", "23. Merge K Sorted Lists", "Hard",
     "Linked List, Divide and Conquer, Heap",
     "You are given an array of k linked-lists lists, each sorted in\n"
     " * ascending order. Merge all the linked-lists into one sorted list.",
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
     "    // [[1,4,5],[1,3,4],[2,6]] → [1,1,2,3,4,4,5,6]\n"
     "    ListNode* l1 = new ListNode(1);\n"
     "    l1->next = new ListNode(4); l1->next->next = new ListNode(5);\n"
     "    ListNode* l2 = new ListNode(1);\n"
     "    l2->next = new ListNode(3); l2->next->next = new ListNode(4);\n"
     "    ListNode* l3 = new ListNode(2);\n"
     "    l3->next = new ListNode(6);\n"
     "    vector<ListNode*> lists = {l1, l2, l3};\n"
     "    ListNode* r = sol.mergeKLists(lists);\n"
     '    while(r){ cout << r->val << " "; r = r->next; } cout << "\\n";'),

    ("42_trapping_rain_water", "42. Trapping Rain Water", "Hard",
     "Array, Two Pointers, Stack, Dynamic Programming",
     "Given n non-negative integers representing an elevation map where the\n"
     " * width of each bar is 1, compute how much water it can trap after\n"
     " * raining.",
     "n == height.length\n"
     " * 1 <= n <= 2 * 10^4\n"
     " * 0 <= height[i] <= 10^5",
     DEFAULT_HEADER.strip(),
     "int trap(vector<int>& height)",
     "    vector<int> h1 = {0,1,0,2,1,0,1,3,2,1,2,1};\n"
     '    cout << sol.trap(h1) << "\\n"; // 6\n'
     "    vector<int> h2 = {4,2,0,3,2,5};\n"
     '    cout << sol.trap(h2) << "\\n"; // 9'),

    ("51_n_queens", "51. N-Queens", "Hard",
     "Array, Backtracking",
     "The n-queens puzzle is the problem of placing n queens on an n x n\n"
     " * chessboard such that no two queens attack each other.\n"
     " * Return all distinct solutions.",
     "1 <= n <= 9",
     "#include <iostream>\n#include <vector>\n#include <string>\nusing namespace std;",
     "vector<vector<string>> solveNQueens(int n)",
     '    auto r = sol.solveNQueens(4);\n'
     '    cout << r.size() << "\\n"; // 2'),

    ("76_minimum_window_substring", "76. Minimum Window Substring", "Hard",
     "Hash Table, String, Sliding Window",
     "Given two strings s and t, return the minimum window substring of s\n"
     " * such that every character in t is included in the window.\n"
     " * Return empty string if no such window exists.",
     "m == s.length\n"
     " * n == t.length\n"
     " * 1 <= m, n <= 10^5",
     "#include <iostream>\n#include <string>\n#include <unordered_map>\nusing namespace std;",
     "string minWindow(string s, string t)",
     '    cout << sol.minWindow("ADOBECODEBANC", "ABC") << "\\n"; // BANC\n'
     '    cout << sol.minWindow("a", "a") << "\\n"; // a\n'
     '    cout << sol.minWindow("a", "aa") << "\\n"; // ""'),

    ("84_largest_rectangle_in_histogram",
     "84. Largest Rectangle in Histogram", "Hard",
     "Array, Stack, Monotonic Stack",
     "Given an array of integers heights representing the histogram's bar\n"
     " * height where the width of each bar is 1, return the area of the\n"
     " * largest rectangle in the histogram.",
     "1 <= heights.length <= 10^5\n"
     " * 0 <= heights[i] <= 10^4",
     "#include <iostream>\n#include <vector>\n#include <stack>\nusing namespace std;",
     "int largestRectangleArea(vector<int>& heights)",
     "    vector<int> h1 = {2,1,5,6,2,3};\n"
     '    cout << sol.largestRectangleArea(h1) << "\\n"; // 10\n'
     "    vector<int> h2 = {2,4};\n"
     '    cout << sol.largestRectangleArea(h2) << "\\n"; // 4'),

    ("124_binary_tree_maximum_path_sum", "124. Binary Tree Maximum Path Sum", "Hard",
     "Dynamic Programming, Tree, DFS, Binary Tree",
     "A path in a binary tree is a sequence of nodes where each pair of\n"
     " * adjacent nodes has an edge connecting them. The path does not need\n"
     " * to pass through the root. Return the maximum path sum.",
     "The number of nodes in the tree is in the range [1, 3 * 10^4].\n"
     " * -1000 <= Node.val <= 1000",
     TREE_HEADER.strip(),
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

    ("127_word_ladder", "127. Word Ladder", "Hard",
     "Hash Table, String, BFS",
     "Given beginWord, endWord, and a wordList, return the number of words in\n"
     " * the shortest transformation sequence from beginWord to endWord.\n"
     " * Return 0 if no such sequence exists.",
     "1 <= beginWord.length <= 10\n"
     " * endWord.length == beginWord.length\n"
     " * 1 <= wordList.length <= 5000",
     "#include <iostream>\n#include <string>\n#include <vector>\n"
     "#include <unordered_set>\n#include <queue>\nusing namespace std;",
     "int ladderLength(string beginWord, string endWord, vector<string>& wordList)",
     '    vector<string> wl1 = {"hot","dot","dog","lot","log","cog"};\n'
     '    cout << sol.ladderLength("hit", "cog", wl1) << "\\n"; // 5\n'
     '    vector<string> wl2 = {"hot","dot","dog","lot","log"};\n'
     '    cout << sol.ladderLength("hit", "cog", wl2) << "\\n"; // 0'),

    ("295_find_median_from_data_stream", "295. Find Median from Data Stream", "Hard",
     "Two Pointers, Design, Sorting, Heap",
     "The MedianFinder class finds the median from a data stream.\n"
     " * addNum(int num): adds num to the data structure.\n"
     " * findMedian(): returns the median of current data stream.",
     "-10^5 <= num <= 10^5\n"
     " * At most 5 * 10^4 calls to addNum and findMedian.",
     "#include <iostream>\n#include <queue>\nusing namespace std;",
     "// Design MedianFinder class",
     "    // MedianFinder mf;\n"
     "    // mf.addNum(1); mf.addNum(2);\n"
     '    // cout << mf.findMedian() << "\\n"; // 1.5\n'
     "    // mf.addNum(3);\n"
     '    // cout << mf.findMedian() << "\\n"; // 2.0\n'
     '    cout << "MedianFinder design problem" << "\\n";'),

    ("297_serialize_and_deserialize_binary_tree",
     "297. Serialize and Deserialize Binary Tree", "Hard",
     "String, Tree, DFS, BFS, Design, Binary Tree",
     "Design an algorithm to serialize and deserialize a binary tree.",
     "The number of nodes in the tree is in the range [0, 10^4].\n"
     " * -1000 <= Node.val <= 1000",
     "#include <iostream>\n#include <string>\n#include <sstream>\n#include <queue>\nusing namespace std;\n\n"
     "struct TreeNode {\n"
     "    int val;\n"
     "    TreeNode* left;\n"
     "    TreeNode* right;\n"
     "    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}\n"
     "};",
     "// Design Codec class with serialize and deserialize",
     "    // Codec codec;\n"
     "    TreeNode* r = new TreeNode(1);\n"
     "    r->left = new TreeNode(2);\n"
     "    r->right = new TreeNode(3);\n"
     "    r->right->left = new TreeNode(4);\n"
     "    r->right->right = new TreeNode(5);\n"
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
