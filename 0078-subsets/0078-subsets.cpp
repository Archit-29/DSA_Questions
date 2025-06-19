class Solution {
public:

    void helper(int i, vector<int>&nums, vector<int>&ds,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        helper(i+1,nums,ds,ans);
        ds.pop_back();
        helper(i+1,nums,ds,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,nums,ds,ans);
        return ans;
    }
};