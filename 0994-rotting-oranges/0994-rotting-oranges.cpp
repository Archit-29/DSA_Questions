class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<pair<int,int>,int>>q;
        int vis[n][m];
        int countFresh=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }else{
                    vis[i][j]=0;
                }
                if(grid[i][j]==1) countFresh++;
            }
        }

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        int tm=0;
        int count=0;

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                tm=max(tm,t);

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
                && vis[nrow][ncol]==0 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                    count++;
                }
            }
        }

        if(count!=countFresh) return -1;
        return tm;
    }
};