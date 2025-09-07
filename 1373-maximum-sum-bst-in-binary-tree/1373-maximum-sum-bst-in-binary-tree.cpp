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
class Prop{
    public:
    bool isBST;
    int minVal;
    int maxVal;
    int sum;

    Prop(){
        isBST=true;
        minVal=INT_MAX;
        maxVal=INT_MIN;
        sum=0;
    }
};

class Solution {
public:

    Prop helper(TreeNode*node, int &ans){

        if(node==NULL) return Prop();

        Prop left= helper(node->left,ans);
        Prop right= helper(node->right, ans);
        Prop curr;

        if(left.isBST && right.isBST && node->val>left.maxVal && node->val< right.minVal){
            curr.isBST=true;
            curr.minVal=min(node->val,left.minVal);
            curr.maxVal=max(node->val,right.maxVal);
            curr.sum= node->val+left.sum+right.sum;
        }
        else{
            curr.isBST=false;
            curr.sum=0;
        }
        
        ans=max(ans,curr.sum);
        return curr;
    }

    int maxSumBST(TreeNode* root) {
       int ans=0;
       helper(root,ans);
       return ans;
    }
};