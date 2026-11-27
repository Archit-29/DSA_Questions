class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        helper(0,n,board,ans);
        return ans;
    }

    bool isValid(int row,int col, int n, vector<string>&board){

        int dupRow=row;
        int dupCol=col;

        while(dupCol>=0){ //left row
            if(board[dupRow][dupCol]=='Q') return false;
            dupCol--;
        }
        dupCol=col;

        while(dupRow>=0){ // upper col
            if(board[dupRow][dupCol]=='Q')return false;
            dupRow--;
        }
        dupRow=row;

        while(dupRow>=0 && dupCol>=0){ //upper diagonal
            if(board[dupRow][dupCol]=='Q') return false;
            dupRow--;
            dupCol--;
        }

        dupRow=row;
        dupCol=col;

        while(dupRow<n && dupCol>=0){
            if(board[dupRow][dupCol]=='Q') return false;
            dupRow++;
            dupCol--;
        }
        
        return true;
    }

    void helper(int col, int n, vector<string>&board,vector<vector<string>>&ans){

        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row=0;row<n;row++){
            if(isValid(row,col,n,board)){
            board[row][col]='Q';
            helper(col+1,n,board,ans);
            board[row][col]='.';
            }
        }
    }
};