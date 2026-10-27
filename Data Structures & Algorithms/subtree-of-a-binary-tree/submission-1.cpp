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

    // only tracks roots
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;

        // we assume subRoot will always be valid here
        bool tree = false;
        if (root->val == subRoot->val) {
            tree = subTree(root, subRoot);
        }
        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        return tree || left || right;
    }   

private:

    bool subTree(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true;

        if (!root && subRoot) return false;
        if (root && !subRoot) return false;

        if (root->val != subRoot->val) return false;
        bool left = subTree(root->left, subRoot->left);
        bool right = subTree(root->right, subRoot->right);
        return left && right;
    }
};
