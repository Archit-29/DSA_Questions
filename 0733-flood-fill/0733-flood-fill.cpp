class Solution {
public:

    void helper(int row,int col, int color,int ogcolor,vector<vector<int>>& image){
        int m=image.size();
        int n=image[0].size();
        if(row>=m || row<0 || col>=n || col<0) return;
        if(image[row][col]==color) return;
        if(image[row][col]!=ogcolor) return;

        image[row][col]=color;
        helper(row+1,col,color,ogcolor,image);
        helper(row-1,col,color,ogcolor,image);
        helper(row,col+1,color,ogcolor,image);
        helper(row,col-1,color,ogcolor,image);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ogcolor=image[sr][sc];
        if(ogcolor==color) return image;

        helper(sr,sc,color,ogcolor,image);
        return image;
    }
};