class Solution {
public:

     vector<int> dir={-1,0,1,0,-1};
     int dfs(vector<vector<int>>&grid, vector<vector<bool>>&visited, int i, int j, int&row, int&col){
        int max_area=1;
        for(int d=0;d<4;d++){
            int nrow= i+dir[d];
            int ncol= j+dir[d+1];
            if(nrow>=0 && nrow<row && ncol>=0 && ncol<col &&
             !visited[nrow][ncol] && grid[nrow][ncol]>0){
                visited[nrow][ncol]=true;
                max_area+=dfs(grid,visited,nrow,ncol,row,col);
            }
        }
       return max_area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row=grid.size();
        int col=grid[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        int max_islands=0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    visited[i][j]=true;
                    max_islands= max(max_islands,dfs(grid,visited,i,j,row,col));
                }
            }
        }
        return max_islands;

    }
      
};