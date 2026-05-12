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
        //用BFS，queue結構儲存每一層的節點，每次處理一層的節點，處理完後將下一層的節點加入queue
        vector<vector<int>> result;//初始化結果
        if(!root) return result;//如果root為空，則返回結果
        queue<TreeNode*> q;//初始化queue
        q.push(root);//將root加入queue
        while(!q.empty()){
            int size = q.size();//記錄這層有幾個節點
            vector<int> level;//初始化這層的結果
            for(int i = 0; i < size; i++){
                TreeNode* cur = q.front(); q.pop();//取出節點
                level.push_back(cur->val);//加入這層的結果
                if(cur->left) q.push(cur->left);//左子加入queue（下一層）
                if(cur->right) q.push(cur->right);//右子加入queue（下一層）
            }
            result.push_back(level);//這層結束，加入結果
        }
        return result;
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
