class Solution {
public:
    int f(int index, int amount,vector<vector<int>>&dp, vector<int>&coins){

        if(index==0){
            if(amount%coins[0]==0) return amount/coins[0];
            else{
                return 1e9;
            }
        }

        if(dp[index][amount]!=-1) return dp[index][amount];
        
        int notPick=f(index-1,amount,dp,coins);
        int pick=1e9;
        if(coins[index]<=amount){
            pick=1+f(index,amount-coins[index],dp,coins);
        }
        return dp[index][amount]=min(pick,notPick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=1e9;
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        ans=f(n-1,amount,dp,coins);
        if(ans==1e9) return -1;
        else return ans;
    }
};