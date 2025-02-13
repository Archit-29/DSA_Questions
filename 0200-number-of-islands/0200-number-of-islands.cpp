class Solution {
public:

    queue<pair<int,int>>q;

    void bfs(int row, int col , int n , int m ,vector<vector<char>>& grid , vector<vector<char>>& vis){
        q.push({row,col});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];

                if(nrow<n&& nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol] == '1' && vis[nrow][ncol]!='1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]='1';
                }
            }
         }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<char>>vis(n,vector<char>(m,'0'));
        int count=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]!='1'){
                    count++;
                    bfs(i,j,n,m,grid,vis);
                }
            }
        }
        return count;

       
        }


    };