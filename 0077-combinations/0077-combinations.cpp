class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(n,k,1,temp,ans);
        return ans;

    }

    void helper(int n, int k ,int index, vector<int>&temp, vector<vector<int>>&ans){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int i=index;i<=n;i++){
                temp.push_back(i);
                helper(n,k,i+1,temp,ans);
                temp.pop_back();
            }
        }
    };