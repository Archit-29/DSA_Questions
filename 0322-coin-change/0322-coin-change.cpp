class Solution {
public:
    int f(int index, int amount, vector<vector<int>>&dp,vector<int>&coins){

        if (amount == 0) return 0;
        
        if(index==0){
            if(amount%coins[index]==0) return amount/coins[index];
            else return 1e9;
        }

        if(dp[index][amount]!=-1) return dp[index][amount];

        int notPick=0+f(index-1,amount,dp,coins);
        int pick=1e9;
        if(coins[index]<=amount){
            pick= 1+f(index,amount-coins[index],dp,coins);
        }
        return dp[index][amount]=min(pick,notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans=f(n-1,amount,dp,coins);
        return (ans==1e9) ? -1 : ans;
    }
};