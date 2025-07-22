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

private:
    void helper(TreeNode*node,int &count , int&ans){
        if(node==NULL || count<=0) return;
        helper(node->left,count,ans);
        count--;
        if(count==0) {
            ans=node->val;
            return;
        }
        helper(node->right,count,ans);

    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count=k;
        int ans=0;
         helper(root,count,ans);
         return ans;
    }
};