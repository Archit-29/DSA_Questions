class Solution {
public:
    int f(int index, int canbuy, int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){

        if(index==prices.size()) return 0;
        if(cap==0) return 0;
        if(dp[index][canbuy][cap]!=-1) return dp[index][canbuy][cap];


        if(canbuy){
            return dp[index][canbuy][cap]=max( -prices[index]+f(index+1,0,cap,prices,dp),
                                                0+f(index+1,1,cap,prices,dp));
        }
        else{
            return dp[index][canbuy][cap]=max( prices[index]+f(index+1,1,cap-1,prices,dp),
                                                0+f(index+1,0,cap,prices,dp));
        }

    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,1,2,prices,dp);
    }
};