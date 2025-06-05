class Solution {
public:
    bool binarySearch(vector<int>row,int target){
        int left=0;
        int right=row.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(row[mid]<target){
                left=mid+1;
            }else if(row[mid]>target){
                right=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(binarySearch(matrix[i],target)){
                return true;
            }
        }
        return false;
    }
};