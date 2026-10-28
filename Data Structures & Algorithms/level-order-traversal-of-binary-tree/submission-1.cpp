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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res{};
        queue<TreeNode*> q{};
        q.push(root);
        while (!q.empty()) {
            const int N = q.size();
            vector<int> level{};
            for (int i = 0; i < N; i ++) {
                TreeNode* curr = q.front(); q.pop();
                //if (!curr) continue;
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right); 
                level.push_back(curr->val);
            }
            res.push_back(level);
        }
        return res;
    }
};
