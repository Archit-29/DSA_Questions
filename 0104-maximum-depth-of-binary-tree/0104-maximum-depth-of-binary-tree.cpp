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

    void depth(TreeNode*node, int height,int&ans){
        if(node->left==NULL && node->right==NULL){
            ans=max(ans,height);
            return;
        }
        if(node->left) depth(node->left,height+1,ans);
        if(node->right) depth(node->right,height+1,ans);
    }

    int maxDepth(TreeNode* root) {
       int ans=0;
       if(root==NULL) return ans;
       
       depth(root,1,ans);
       return ans;
    }
};