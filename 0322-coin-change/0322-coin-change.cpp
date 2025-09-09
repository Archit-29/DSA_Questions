class Solution {
public:

    int f(int index, int target, vector<int>&coins, vector<vector<int>>&dp){

        if(index==0){
            if(target % coins[0]==0) return target/coins[0];
            return 1e9;
        } 

        if(dp[index][target]!=-1) return dp[index][target];
        
        int notPick= 0+f(index-1,target,coins,dp);
        int Pick=1e9;
        if(coins[index]<=target){
            Pick = 1+f(index,target-coins[index],coins,dp);
        }
        return dp[index][target]=min(Pick,notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        return (ans==1e9)?-1 : ans;
    }
};