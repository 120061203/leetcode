/*
 * 297. Serialize and Deserialize Binary Tree
 * Difficulty: Hard
 * Tags: String, Tree, DFS, BFS, Design, Binary Tree
 *
 * Description:
 * Design an algorithm to serialize and deserialize a binary tree.
 * Serialization is the process of converting a data structure into a
 * sequence of bits so that it can be stored or transmitted and
 * reconstructed later.
 *
 * Constraints:
 * - The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
 */

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    // 前序 DFS 序列化：根→左→右，null 記為 "#"
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "#,";
            return;
        }
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    // 從 stringstream 依序讀 token 還原樹
    TreeNode* deserializeHelper(istringstream& ss) {
        string token;
        getline(ss, token, ','); // 讀到下一個 ','
        if (token == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(token));
        node->left  = deserializeHelper(ss);
        node->right = deserializeHelper(ss);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    TreeNode* deserialize(string data) {
        istringstream ss(data);
        return deserializeHelper(ss);
    }
};

int main() {
    Codec codec;

    TreeNode* r = new TreeNode(1);
    r->left = new TreeNode(2); r->right = new TreeNode(3);
    r->right->left = new TreeNode(4); r->right->right = new TreeNode(5);

    string s = codec.serialize(r);
    cout << s << "\n"; // 1,2,#,#,3,4,#,#,5,#,#,

    TreeNode* res = codec.deserialize(s);
    cout << (res ? res->val : -1) << "\n";             // 1
    cout << (res->right ? res->right->val : -1) << "\n"; // 3

    return 0;
}
