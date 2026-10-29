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
    int kthSmallest(TreeNode* root, int k) {
        left = k;
        int res = find(root);
        return res != INT_MAX ? res : prev;
    }

    int find(TreeNode* root) {
        if (!root) return INT_MAX;

        int l = find(root->left);
        if (l != INT_MAX) return l;
        if (--left == 0) return root->val;
        int r = find(root->right);
        if (r != INT_MAX) return r;
        if (left == 0) return root->val;
        prev = root->val;
        return std::min(l, r);
    }

private:
    int left{};
    int prev{};
};
