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

    bool helper(TreeNode*node,long Lowerbound, long Upperbound){
        if(node==NULL) return true;

        if(node->val <= Lowerbound || node->val >= Upperbound) return false;

     return helper(node->left,Lowerbound,node->val) && helper(node->right,node->val,Upperbound);
    }

    bool isValidBST(TreeNode* root) {
        long Upperbound=LONG_MAX;
        long Lowerbound=LONG_MIN;
        return helper(root,Lowerbound,Upperbound);
    }
};