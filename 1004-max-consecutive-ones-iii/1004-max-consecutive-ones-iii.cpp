class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
       int right=0;
       int left=0;
       int zero_count=0;
       int length=0;

       while(right<nums.size()){
        if(nums[right]==0){
            zero_count++;
        }
        while(zero_count>k){
             if(nums[left]==0){
            zero_count--;
             }
            left++;
        }
       
        length=max(length,right-left+1);
        right++;
        
       }
       return length;
    }
};