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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        return valid(root, INT_MIN, INT_MAX);
    }

private:

    bool valid(TreeNode* node, int low, int high) {
        if (!node) return true;

        if (node->val <= low || high <= node->val) return false;

        return valid(node->left, low, node->val) && valid(node->right, node->val, high);
    }
};
