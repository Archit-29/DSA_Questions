class Solution {
public:

   int helper(int row, int col, int m, int n, vector<vector<int>>&dp){
        if(row>=m || row<0 || col>=n || col<0) return 0;
        if(dp[row][col]!=-1) return dp[row][col];

        if(row==m-1 && col == n-1) return 1;

        dp[row][col]=helper(row+1,col,m,n,dp)+helper(row,col+1,m,n,dp);

        return dp[row][col];
   }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);
    }
};