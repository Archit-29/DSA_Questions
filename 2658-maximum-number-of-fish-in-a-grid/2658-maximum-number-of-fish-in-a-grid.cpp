class Solution {
public:

    bool isValid(int x, int y ,int &row,int&col){
        return (x>=0&& x<row && y>=0 && y<col);
    }
    vector<int> dir ={-1,0,1,0,-1};

    int dfs(vector<vector<int>>& grid,
    vector<vector<bool>>& visited,int &row,int&col,int   x, int y){

        int fish_count=grid[x][y];

        for(int i=0;i<4;i++){
            int newX= x+dir[i];
            int newY= y+dir[i+1];
            if(isValid(newX,newY,row,col) && !visited[newX][newY] && grid[newX][newY]>0){
                visited[newX][newY]=true;
                fish_count +=dfs(grid,visited,row,col,newX,newY);
            }
        }
        return fish_count;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int max_fish=0;
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]>0 && !visited[i][j]){
                    visited[i][j]=true;
                    max_fish = max(max_fish,dfs(grid,visited,row,col,i,j));
                }
            }    
        }
        return max_fish;
    }
};