/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }

    // isBalanced, height
    pair<bool, int> dfs(TreeNode* node) {
        if (!node) return {true, 0};

        pair<bool, int> left = dfs(node->left);
        pair<bool, int> right = dfs(node->right);
        if (left.first && right.first && abs(right.second - left.second) <= 1) {
            return {true, 1 + max(right.second, left.second)};
        }
        return {false, 0};
    }
};
