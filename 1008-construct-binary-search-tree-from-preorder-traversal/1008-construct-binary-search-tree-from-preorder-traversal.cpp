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

    TreeNode* helper(int&index, int UpperBound, vector<int>&preorder){
        if(index==preorder.size() || preorder[index]>UpperBound) return NULL;

        TreeNode* node= new TreeNode(preorder[index]);
        index++;
        node->left=helper(index,node->val,preorder);
        node->right=helper(index,UpperBound,preorder);

        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return helper(index,INT_MAX,preorder);
    }
};