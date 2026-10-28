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
        queue<TreeNode*> q{};
        q.push(root);
        while (!q.empty()) {
            // we want to get the rightmost in the last level
            vector<int> level{};
            const int N = q.size();
            for (int i = 0; i < N; i++) {
                TreeNode* node = q.front(); q.pop();

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                level.push_back(node->val);
            }
            int last_val = level.at(level.size() - 1);
            res.push_back(last_val);
        }

        return res;
    }
};
