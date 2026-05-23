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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s{};
        vector<int> res{};
        TreeNode* curr = root;
        while (curr || !s.empty()) {
            if (curr) {
                s.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = s.top(); s.pop();
                res.push_back(node->val);
                curr = node->right;
            }
        }
        return res;
    }
};