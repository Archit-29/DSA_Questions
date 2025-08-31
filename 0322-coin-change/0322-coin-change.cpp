class Solution {
public:
    int f(int index, int amount, vector<int>&coins,vector<vector<int>>&dp){

        if(index==0){
            if(amount % coins[0]==0) return amount/coins[0];
            else return 1e9;
        }

        if(dp[index][amount]!=-1) return dp[index][amount];

        int notTake=0+f(index-1,amount,coins,dp);

        int take=1e9;
        if(coins[index]<=amount){
            take=1+f(index,amount-coins[index],coins,dp);
        }

        return dp[index][amount]=min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans;

        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        ans= f(n-1,amount,coins,dp);

        if(ans==1e9) return -1;
        else return ans;
    }
};