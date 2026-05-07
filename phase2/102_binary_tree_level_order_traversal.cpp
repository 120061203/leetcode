/*
 * 102. Binary Tree Level Order Traversal
 * Difficulty: Medium
 * Tags: Tree, BFS, Binary Tree
 *
 * Description:
 * Given the root of a binary tree, return the level order traversal of
 * its nodes' values (i.e., from left to right, level by level).
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 2000].
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
    vector<vector<int>> levelOrder(TreeNode* root) {

    }
};

int main() {
    Solution sol;

    // [3,9,20,null,null,15,7] → [[3],[9,20],[15,7]]
    TreeNode* r = new TreeNode(3);
    r->left = new TreeNode(9); r->right = new TreeNode(20);
    r->right->left = new TreeNode(15); r->right->right = new TreeNode(7);
    auto res = sol.levelOrder(r);
    for(auto& lv : res){ for(int x : lv) cout << x << " "; cout << "\n"; }

    return 0;
}
