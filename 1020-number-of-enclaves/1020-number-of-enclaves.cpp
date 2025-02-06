class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,int n,int m){
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        grid[row][col]=0;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];

            if(nrow>=0 && nrow<n && ncol<m && ncol>=0 && grid[nrow][ncol]==1){
                dfs(nrow,ncol,grid,n,m);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            if(grid[i][0]==1) dfs(i,0,grid,n,m);
            if(grid[i][m-1]==1) dfs(i,m-1,grid,n,m);
        }

        for(int j=0;j<m;j++){
            if(grid[0][j]==1) dfs(0,j,grid,n,m);
            if(grid[n-1][j]==1)dfs(n-1,j,grid,n,m);
        }

        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) count++; 
            }
        }
        return count;
    }
};