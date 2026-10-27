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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        
        if (root->val == key) {
            return del(root);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

private:

    TreeNode* del(TreeNode* node) {
        if (!node->left && !node->right) return nullptr;
        if (!node->left && node->right) return node->right;
        if (node->left && !node->right) return node->left;

        // we know both branches exist, we want to grab the leftmost on the right
        TreeNode* min = findMin(node->right);
        node->val = min->val;
        node->right = deleteNode(node->right, min->val);
        return node;
    }   

    TreeNode* findMin(TreeNode* node) {
        TreeNode* curr = node;
        // there are no more curr->left means end
        while (curr && curr->left) {
            curr = curr->left;
        }
        return curr;
    }
};