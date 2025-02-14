class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        int total_area=0;
        int area=0;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    area=0;

                    while(!q.empty()){
                        
                        int row=q.front().first;
                        int col=q.front().second;
                        q.pop();
                        area++;

                        for(int i=0;i<4;i++){
                            int nrow=row+delrow[i];
                            int ncol=col+delcol[i];

                            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && 
                            vis[nrow][ncol]!=1 && grid[nrow][ncol]==1){
                                q.push({nrow,ncol});
                                vis[nrow][ncol]=1;
                            }
                        }   
                    }
                     total_area=max(area,total_area);
                }
            }
        }

        return total_area;
    }
};