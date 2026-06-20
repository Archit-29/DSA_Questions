class Solution {
public:
    void helper(int index, int target,vector<int>&candidates, vector<int>&ds,vector<vector<int>>&ans){

        if(index==candidates.size()){
           if(target==0) ans.push_back(ds);
            return;
        }

        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            helper(index,target-candidates[index],candidates,ds,ans);
            ds.pop_back();
        }

        helper(index+1,target,candidates,ds,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        helper(0,target,candidates,ds,ans);
        return ans;
    }
};