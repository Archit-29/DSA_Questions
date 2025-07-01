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

    int helper(TreeNode*node,int&ans){
        if(node==NULL) return 0;

        int lh=helper(node->left,ans);
        int rh=helper(node->right,ans);

        if(abs(lh-rh)>1){
            ans=0;
        }
        return 1+max(lh,rh);
    }

    bool isBalanced(TreeNode* root) {
        int ans=1;
        helper(root,ans);
        if(ans==0) return false;
        return true;
    }
};