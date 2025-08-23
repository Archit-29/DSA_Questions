class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums,k)-atMost(nums,k-1);
    }

    int atMost(vector<int>&nums,int k){
        if(k<0) return 0;
        int l=0;
        int r=0;
        int count=0;
        unordered_map<int,int>mp;

        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
};