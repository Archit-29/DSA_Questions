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
class prop{

    public:
        bool isbst;
        int maximum;
        int minimum;
        int sum;
        prop(){
            isbst=true;
            maximum=INT_MIN;
            minimum=INT_MAX;
            sum=0;
        }
};

class Solution {
public:

    prop getSum(TreeNode*node,int&ans){
        if(node==NULL) return prop();

        prop pd;
        prop pdl= getSum(node->left,ans);
        prop pdr=getSum(node->right,ans);

            if(pdl.isbst==true && pdr.isbst==true && pdl.maximum<node->val && node->val<pdr.minimum){
                pd.sum= node->val + pdl.sum + pdr.sum;
                pd.isbst=true;
                pd.minimum=min(node->val,pdl.minimum);
                pd.maximum=max(node->val,pdr.maximum);
            }else{
                pd.isbst=false;
                pd.sum=0;
            }

            ans=max(ans,pd.sum);
            return pd;
    }


    int maxSumBST(TreeNode* root) {
        int ans=INT_MIN;
        getSum(root,ans);
        return ans>0 ? ans : 0;
    }
};