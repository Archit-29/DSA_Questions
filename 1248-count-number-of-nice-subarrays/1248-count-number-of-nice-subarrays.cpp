class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int r=0;
        int count=0;
        int sum=0;

        while(r<nums.size()){
            if(nums[r]%2==1){
                sum++;
            }
            if(sum==k) count++;
            
            int rem=sum-k;
            if(mp.find(rem)!=mp.end()){
                count+=mp[rem];
            }
            mp[sum]++;
            r++;
        }
        return count;
    }
};