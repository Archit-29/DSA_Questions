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

    bool dfs(TreeNode * node , int value, int targetSum){
        if(node==NULL) return false;
        value+=node->val;

        if(!node->left && !node->right){
            return value==targetSum;
        }
        return dfs(node->left,value,targetSum) || dfs(node->right,value,targetSum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
       return dfs(root,0,targetSum);
    }
};