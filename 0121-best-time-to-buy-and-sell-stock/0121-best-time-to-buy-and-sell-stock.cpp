class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy=prices[0];
        int maxi=0;
        for(int i=1;i<prices.size();i++){
            
            if(prices[i]<buy){
                buy=prices[i];
            }
           else {
                int profit = prices[i] - buy;
                maxi = max(maxi, profit);
            }  
        }
        return maxi;
    }
};