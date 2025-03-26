class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 if(board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                 }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word,int row, int col , int i){
        
        if(i==word.size()) return true;

        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!=word[i]) return false;
        board[row][col]='0';

        bool status = dfs(board, word, row+1, col, i+1) || 
                      dfs(board, word, row, col+1, i+1) ||
                      dfs(board, word, row-1, col, i+1) ||
                      dfs(board, word, row, col-1, i+1);

        board[row][col]=word[i];
        return status;
    }
};