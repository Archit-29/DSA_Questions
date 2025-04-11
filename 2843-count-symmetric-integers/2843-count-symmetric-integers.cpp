class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
       int count=0;
       while(low<=high){
        if(isSymmetric(low)) count++;
        low++;
        }
        return count;
    }

    bool isSymmetric(int number){
        string value=to_string(number);
        int n= value.size();
        if(n%2!=0)return false;
        int leftsum=0;
        int rightsum=0;
        for(int i=0;i<n/2;i++){
            leftsum += value[i]-'0';
            rightsum += value[n-1-i]-'0';
        }
        return leftsum==rightsum;
    }
};