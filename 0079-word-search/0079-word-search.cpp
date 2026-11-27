class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<char>> vis(m, vector<char>(n, '0'));

        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]==word[0] && dfs(row,col,0,m,n,vis,board,word)) return true;
            }
        }

        return false;
    }

    bool dfs(int row,int col, int index,int m, int n, vector<vector<char>>&vis, vector<vector<char>>& board,string word){

        if(index==word.size()) return true;

        if(row<0 || row>=m || col<0 || col>=n || board[row][col]!=word[index] || vis[row][col]!='0') return false;

        vis[row][col]='1';
        bool res= dfs(row+1,col,index+1,m,n,vis,board,word) || dfs(row-1,col,index+1,m,n,vis,board,word) || dfs(row,col+1,index+1,m,n,vis,board,word) || dfs(row,col-1,index+1,m,n,vis,board,word);
        vis[row][col]='0';

        return res;
    }
};