class Solution {
public:

    int f(int index, int canbuy, int k, vector<int>&prices, vector<vector<vector<int>>>&dp){

        if(index==prices.size()) return 0;
        if(k==0) return 0;
        if(dp[index][canbuy][k]!=-1) return dp[index][canbuy][k];

        if(canbuy){
            int buy= -prices[index]+f(index+1,0,k,prices,dp);
            int notbuy= 0+f(index+1,1,k,prices,dp);
            return dp[index][canbuy][k]=max(buy,notbuy);
        }
        else{
            int sell= prices[index]+f(index+1,1,k-1,prices,dp);
            int notsell=0+f(index+1,0,k,prices,dp);
            return dp[index][canbuy][k]=max(sell,notsell);
        }

    }



    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,prices,dp);
    }
};