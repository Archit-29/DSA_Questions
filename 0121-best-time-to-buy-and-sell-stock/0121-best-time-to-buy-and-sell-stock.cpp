class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int ans=0;
        int maxi=INT_MIN;
        for(int i=1;i<prices.size();i++){
            if((prices[i]-buy)>0) ans=prices[i]-buy;
            maxi=max(ans,maxi);
            if(prices[i]<buy){
                buy=prices[i];
            }
        }
        return maxi;
    }
};