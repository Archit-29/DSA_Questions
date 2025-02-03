class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
    int inc_length=1;
    int dec_length=1;
    int container=1;
    int n=nums.size();

    for(int i=0;i<n-1;i++){
        if(nums[i]<nums[i+1]){
            inc_length++;
            dec_length=1;
        }
        else if(nums[i]>nums[i+1]){
            dec_length++;
            inc_length=1;
        }
        else{
            inc_length=1;
            dec_length=1;
        }
        container=max(container,max(inc_length,dec_length));
    }
    return container;
    }
};