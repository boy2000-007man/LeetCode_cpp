/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        for (TreeNode *p; root; root->left = nullptr, root = root->right)
            if (root->left) {
                p = root->left;
                while (root->left->right)
                    root->left = root->left->right;
                root->left->right = root->right;
                root->right = p;
            }
    }
};