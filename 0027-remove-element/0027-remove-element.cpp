class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l=0;
        int r=nums.size()-1;

        if (nums.size()==0)return 0;

        while(l<r){
            if(nums[l]==val && nums[r]!=val){
                swap(nums[l],nums[r]);
                l++;
                r--;
            }else if(nums[l]!=val) l++;
            else if (nums[r]==val) r--;
        }
        
        if(nums[l]==val){
            return l;
        }else {
            return l+1;
        }
    }
};