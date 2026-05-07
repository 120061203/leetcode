/*
 * 100. Same Tree
 * Difficulty: Easy
 * Tags: Tree, DFS, BFS, Binary Tree
 *
 * Description:
 * Given the roots of two binary trees p and q, write a function to check
 * if they are the same or not.
 *
 * Constraints:
 * - The number of nodes in both trees is in the range [0, 100].
 * -10^4 <= Node.val <= 10^4
 */

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

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

    }
};

int main() {
    Solution sol;

    // p=[1,2,3], q=[1,2,3] → true
    TreeNode* p1 = new TreeNode(1);
    p1->left = new TreeNode(2); p1->right = new TreeNode(3);
    TreeNode* q1 = new TreeNode(1);
    q1->left = new TreeNode(2); q1->right = new TreeNode(3);
    cout << sol.isSameTree(p1, q1) << "\n"; // 1
    // p=[1,2], q=[1,null,2] → false
    TreeNode* p2 = new TreeNode(1); p2->left = new TreeNode(2);
    TreeNode* q2 = new TreeNode(1); q2->right = new TreeNode(2);
    cout << sol.isSameTree(p2, q2) << "\n"; // 0

    return 0;
}
