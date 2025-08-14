class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0,rsum=0;
        int sum=0;
        for(int i=0;i<k;i++){
            lsum+= cardPoints[i];
        }
        sum=max(sum,lsum);
        int rightIndex=cardPoints.size()-1;
        
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[rightIndex];
            rightIndex--;
            sum=max(sum,lsum+rsum);
        }

        return sum;

    }
};