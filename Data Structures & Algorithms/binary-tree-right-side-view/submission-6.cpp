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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> res{};
        TreeNode* tmp = root;
        queue<TreeNode*> q;
        q.push(tmp);
        while (!q.empty()) {
            TreeNode* curr{nullptr};
            const int size = q.size();
            for (int i{}; i < size; i++) {
                curr = q.front(); q.pop();
                if (curr->left) {
                    q.push(curr->left);
                }
                if (curr->right) {
                    q.push(curr->right);
                }
            }
            if (curr) {
                res.push_back(curr->val);
            }
        }
        return res;
    }
};
