class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        int freshcount=0;
        int rottencount=0;
        int time=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    freshcount++;
                }
            }
        }    
               
                while(!q.empty()){
                    int row=q.front().first.first;
                    int col=q.front().first.second;
                    time=q.front().second;
                    q.pop();

                    for(int i=0;i<4;i++){
                        int nrow=row+delrow[i];
                        int ncol=col+delcol[i];

                        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                         vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                            q.push({{nrow,ncol},time+1});
                            vis[nrow][ncol]=2;
                            rottencount++;
                         }
                    }
                }
                if(rottencount!=freshcount) return -1;

        return time;
    }
};