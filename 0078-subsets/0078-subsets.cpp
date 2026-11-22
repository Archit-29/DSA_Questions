class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,nums,ds,ans);
        return ans;
    }

     void helper(int index,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
        if(index==nums.size()){
             ans.push_back(ds);
             return;
        }
        ds.push_back(nums[index]);
        helper(index+1,nums,ds,ans);
        ds.pop_back();
        helper(index+1,nums,ds,ans);
     }
};