class Solution {
public:

    void helper(int i, int target, vector<int>&candidates,vector<int>&ds, vector<vector<int>>&ans){

        if(target==0){
            ans.push_back(ds);
            return;
        }

        if(i==candidates.size()) return;

        if(candidates[i]<=target){
             ds.push_back(candidates[i]);
             helper(i,target-candidates[i],candidates,ds,ans);
             ds.pop_back();
        }

        helper(i+1,target,candidates,ds,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,target,candidates,ds,ans);
        return ans;
    }
};