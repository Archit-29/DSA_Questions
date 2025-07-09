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

    bool helper(TreeNode*node,unordered_set<int>&seen,int target){
        if(node==NULL) return false;
        if(seen.count(target-node->val)) return true;
        seen.insert(node->val);

        return helper(node->left,seen,target) || helper(node->right,seen,target);
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>seen;
        return helper(root,seen,k);
    }
};