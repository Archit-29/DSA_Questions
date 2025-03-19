/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        int height = 1;
        bst(root, height);
        if (height == 1)
            return true;
        else
            return false;
    }

    int bst(TreeNode* node, int& height) {

        if (node == NULL)
            return 0;

        int lh = bst(node->left, height);
        int rh = bst(node->right, height);

        if (abs(lh - rh) > 1)
            height = 0;
        return 1 + max(lh, rh);
    }
};