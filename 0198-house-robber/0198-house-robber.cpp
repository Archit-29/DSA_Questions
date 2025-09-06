class Solution {
public:

    int f(int index, vector<int>&dp, vector<int>&nums){

        if(index==0) return nums[index];
        if(index<0) return 0;
        if(dp[index]!=-1) return dp[index];
        
        int rob= nums[index]+f(index-2,dp,nums);
        int notRob= 0+f(index-1,dp,nums);
        return dp[index]=max(rob,notRob);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);

        return f(n-1,dp,nums);
    }
};