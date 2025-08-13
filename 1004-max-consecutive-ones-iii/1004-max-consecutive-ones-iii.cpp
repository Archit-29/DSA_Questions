class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int maxLen=0;
        int zero_count=0;
        while(r<nums.size()){

            if(nums[r]==0){
                zero_count++;
            }

            if(zero_count>k){
                if(nums[l]==0){
                    zero_count--;
                }
                l++;
            }

            maxLen=max(maxLen,r-l+1);
            r++;
        }
        return maxLen;
    }
};