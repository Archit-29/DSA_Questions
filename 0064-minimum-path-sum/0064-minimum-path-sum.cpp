class Solution {
public:
    int helper(int row, int col, vector<vector<int>>&grid,vector<vector<int>>&dp){
        int m=grid.size();
        int n=grid[0].size();

        if(row==m-1 && col==n-1) return grid[m-1][n-1];
        if(row>=m || col>=n) return 1e9;
        if(dp[row][col]!=-1) return dp[row][col];

        int down=grid[row][col] + helper(row+1,col,grid,dp);
        int right= grid[row][col]+ helper(row,col+1,grid,dp);

        return dp[row][col]=min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));

        return helper(0,0,grid,dp);
    }
};