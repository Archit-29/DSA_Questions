class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n= isWater.size();
        int m= isWater[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> height(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }else{
                    visited[i][j]=0;
                }
            }
        }
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        while(!q.empty()){
            int row= q.front().first.first;
            int col = q.front().first.second;
            int steps= q.front().second;
            q.pop();

            height[row][col]=steps;

            for(int i=0;i<4;i++){
                int nrow= row + delrow[i];
                int ncol = col + delcol[i];


                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0){
                    visited[nrow][ncol]=1;
                    q.push({{nrow,ncol},steps+1});
                }
            }

        }
        return height;
    }
};