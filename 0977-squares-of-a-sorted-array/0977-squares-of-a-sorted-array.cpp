class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int l=0;
        int r=n-1;
        int z=n-1;
        while(l<=r){
            
            if(nums[l]*nums[l]>nums[r]*nums[r]){
                ans[z]=nums[l]*nums[l];
                l++;
            }
            else{
                ans[z]=nums[r]*nums[r];
                r--;
            }
            z--;
        }
        return ans;
    }
};