class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount=0;
        int l=0;
        int ans=0;
        int r=0;

        while(r<nums.size()){

            if(nums[r]==0) zeroCount++;

            while(zeroCount > k){
                if(nums[l]==0) zeroCount--;
                l++;
            }

            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};