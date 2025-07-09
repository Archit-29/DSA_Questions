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

    void helper(TreeNode*node,int&ans,int& count){
        if(node==NULL || count==0) return ;

        helper(node->left,ans,count);
        count--;
        if(count==0) {
            ans=node->val;
            return;
        }
        helper(node->right,ans,count);
        
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=k;
        int ans;
       helper(root,ans,count);
       return ans;
    }
};