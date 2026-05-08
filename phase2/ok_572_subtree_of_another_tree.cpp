/*
 * 572. Subtree of Another Tree
 * Difficulty: Easy
 * Tags: Tree, DFS, Binary Tree, String Matching
 *
 * Description:
 * Given the roots of two binary trees root and subRoot, return true if
 * there is a subtree of root with the same structure and node values
 * as subRoot, and false otherwise.
 *
 * Constraints:
 * - The number of nodes in the root tree is in the range [1, 2000].
 * The number of nodes in the subRoot tree is in the range [1, 1000].
 * -10^4 <= root.val, subRoot.val <= 10^4
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;//空節點不是子樹
        if(isSameTree(root, subRoot)) return true;//如果兩棵樹相同，則返回true
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);//遞歸檢查左右子樹
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;// p 和 q 都是 null → 兩棵樹同時走到底，完全一樣 → true
        if(!p || !q) return false;// 只有一個是 null → 一個有節點一個沒有，結構不同 → false
        if(p->val != q->val) return false;//節點值不同
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);//遞歸檢查左右子樹
    }
};

int main() {
    Solution sol;

    // root=[3,4,5,1,2], subRoot=[4,1,2] → true
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4); root->right = new TreeNode(5);
    root->left->left = new TreeNode(1); root->left->right = new TreeNode(2);
    TreeNode* sub = new TreeNode(4);
    sub->left = new TreeNode(1); sub->right = new TreeNode(2);
    cout << sol.isSubtree(root, sub) << "\n"; // 1

    // root=[3,4,5,1,2,null,null,null,null,0], subRoot=[4,1,2] → false
    root->left->left->left = new TreeNode(0);
    cout << sol.isSubtree(root, sub) << "\n"; // 0

    return 0;
}
