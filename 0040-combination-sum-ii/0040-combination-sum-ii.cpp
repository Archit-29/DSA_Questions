class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        helper(0,target,candidates,ds,ans);
        return ans;
    }

    void helper(int ind, int target,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans){

        if(target==0){
            ans.push_back(ds);
            return;
        }

        for(int i=ind;i<candidates.size();i++){

            if(i>ind && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;

            ds.push_back(candidates[i]);
            helper(i+1,target-candidates[i],candidates,ds,ans);
            ds.pop_back();
        }
    }
};