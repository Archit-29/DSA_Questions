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
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans;
        helper(root,ans,count,k);
        return ans;
    }

    void helper(TreeNode* node,int &ans, int&count, int k){
        if(!node) return;
        helper(node->left,ans,count,k);
        count++;
        if(count==k) {
            ans=node->val;
            return;
        }
        helper(node->right,ans,count,k);
    }
};