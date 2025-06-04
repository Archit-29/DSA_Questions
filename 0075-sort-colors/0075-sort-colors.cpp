class Solution {
public:
    void sortColors(vector<int>& nums) {
       int zero = 0,one = 0,two = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zero++;
            else if(nums[i]==1)one++;
            else{
                two++;
            }
        }
        int index=0;
        while(zero>0){
            nums[index++]=0;
            zero--;
        }
         while(one>0){
           nums[index++]=1;
            one--;
        }
         while(two>0){
           nums[index++]=2;
            two--;
        }

       
    }
};