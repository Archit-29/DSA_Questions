class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
       queue<pair<pair<int,int>,int>>q; 
       int rottenCount=0;
       int freshCount=0;
       int time=0;

       int delrow[4]={-1,0,1,0};
       int delcol[4]={0,1,0,-1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else if(grid[i][j]==1){
                    freshCount++;
                }
            }
        }

        while(!q.empty()){
            auto p=q.front();
            int row=p.first.first;
            int col=p.first.second;
            time=p.second;
            q.pop();

            for(int i=0 ;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol]=2;
                    rottenCount++;
                }

            }

        }

        if(rottenCount != freshCount) return -1;
        return time;


    }
};