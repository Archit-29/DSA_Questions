class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int streak=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                streak++;
                ans+=streak;
            }else{
                streak=0;
            }
        }
        return ans;
    }
};