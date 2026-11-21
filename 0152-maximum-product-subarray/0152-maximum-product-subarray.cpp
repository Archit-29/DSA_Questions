class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long prefix=1;
        long suffix=1;
        long maxi=LONG_MIN;
        int n=nums.size();

        for(int i=0;i<nums.size();i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;

            prefix=prefix*nums[i];
            suffix=suffix*nums[n-1-i];
            maxi=max(maxi,max(prefix,suffix));
        }

        return maxi;
    }
};