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
    bool helper(TreeNode*node, long lowerBound, long upperBound){
        if(node==NULL) return true;

        if(node->val >=upperBound || node->val<=lowerBound) return false;

        return helper(node->left,lowerBound,node->val) && helper(node->right,node->val,upperBound);
    }
public:
    bool isValidBST(TreeNode* root) {
        long upperbound=LONG_MAX;
        long lowerbound=LONG_MIN;
        return helper(root,lowerbound,upperbound);
    }
};