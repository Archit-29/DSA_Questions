class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,target,ds,candidates,ans);
        return ans;
    }

    void helper(int i,int target,vector<int>&ds,vector<int>&candidates,vector<vector<int>>&ans){

        if(i==candidates.size()) return;
        if(target==0){
            ans.push_back(ds);
            return;
        }

        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            helper(i,target-candidates[i],ds,candidates,ans);
            ds.pop_back();
        }

        helper(i+1,target,ds,candidates,ans);
    }
};