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
    int goodNodes(TreeNode* root) {
        good(root, INT_MIN);
        return goodNum;
    }

private:
    int goodNum{0};

    void good(TreeNode* node, int curr_max) {
        if (!node) return;

        if (curr_max <= node->val) {
            goodNum++;
            curr_max = node->val;
        }

        good(node->left, curr_max);
        good(node->right, curr_max);
    }
};
