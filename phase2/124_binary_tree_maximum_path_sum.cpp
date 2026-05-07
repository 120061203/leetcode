/*
 * 124. Binary Tree Maximum Path Sum
 * Difficulty: Hard
 * Tags: Dynamic Programming, Tree, DFS, Binary Tree
 *
 * Description:
 * A path in a binary tree is a sequence of nodes where each pair of
 * adjacent nodes has an edge connecting them. The path does not need
 * to pass through the root. Return the maximum path sum.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [1, 3 * 10^4].
 * -1000 <= Node.val <= 1000
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
    int maxPathSum(TreeNode* root) {

    }
};

int main() {
    Solution sol;

    // [1,2,3] → 6
    TreeNode* r1 = new TreeNode(1);
    r1->left = new TreeNode(2); r1->right = new TreeNode(3);
    cout << sol.maxPathSum(r1) << "\n"; // 6
    // [-10,9,20,null,null,15,7] → 42
    TreeNode* r2 = new TreeNode(-10);
    r2->left = new TreeNode(9); r2->right = new TreeNode(20);
    r2->right->left = new TreeNode(15); r2->right->right = new TreeNode(7);
    cout << sol.maxPathSum(r2) << "\n"; // 42

    return 0;
}
