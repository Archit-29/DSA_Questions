class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();

        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            dfs(i,0,n,m,pacific,heights);
            dfs(i,m-1,n,m,atlantic,heights);
        }
        for(int j=0;j<m;j++){
            dfs(0,j,n,m,pacific,heights);
            dfs(n-1,j,n,m,atlantic,heights);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }

    void dfs(int row, int col ,int n,int m, vector<vector<int>>&ocean,vector<vector<int>>& heights){
        
        if(ocean[row][col]==1) return;
        
            ocean[row][col]=1;
            int delrow[4]={-1,0,1,0};
            int delcol[4]={0,1,0,-1};

            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i]; 

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && 
                ocean[nrow][ncol]!=1 && heights[nrow][ncol]>=heights[row][col]){
                    dfs(nrow,ncol,n,m,ocean,heights);
                }
            }

    }
};