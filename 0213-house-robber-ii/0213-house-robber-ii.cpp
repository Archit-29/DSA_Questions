class Solution {
public:

    int f(int index,vector<int>&nums,vector<int>&dp){
        if(index==0) return nums[index];
        if(index<0)return 0;
        if(dp[index]!=-1)return dp[index];
        int pick=f(index-2,nums,dp)+nums[index];
        int notpick=f(index-1,nums,dp)+0;

        return dp[index]=max(pick,notpick);
    }

    int robSimple(vector<int>& nums) {
       int n=nums.size();
       vector<int>dp(n,-1);
       return f(n-1,nums,dp);
    }

    int rob(vector<int>&nums){
        int n=nums.size();
         vector<int>temp1,temp2;
         if (n == 1) return nums[0];
    
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        int ans1=robSimple(temp1);
        int ans2=robSimple(temp2);

        return max(ans1,ans2);
    }
};