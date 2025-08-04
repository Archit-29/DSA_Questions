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
class prop {
    public:
        bool isBst;
        int maxVal;
        int minVal;
        int sum;

            prop(){
                isBst=true;
                maxVal=INT_MIN;
                minVal=INT_MAX;
                sum=0;
            }
};


class Solution {
public:
    prop checkSumBST(TreeNode* root,int &ans) {
        if(root==NULL) return prop();
        prop pd;
        prop pdLeft=checkSumBST(root->left,ans);
        prop pdRight=checkSumBST(root->right,ans);

        if(pdLeft.isBst==true && pdRight.isBst==true && pdLeft.maxVal<root->val && root->val<pdRight.minVal){
            pd.isBst=true;
            pd.maxVal=max(root->val,pdRight.maxVal);
            pd.minVal=min(root->val,pdLeft.minVal);
            pd.sum=root->val+pdLeft.sum+pdRight.sum;
        }
        else{
            pd.isBst=false;
            pd.sum=0;
        }
        ans=max(ans,pd.sum);
        return pd;
    }

    int maxSumBST(TreeNode*root){
        int ans=INT_MIN;
        checkSumBST(root,ans);
        return ans;
    }
    
};