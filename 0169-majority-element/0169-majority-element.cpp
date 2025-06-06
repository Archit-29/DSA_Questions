class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int maxi=0;
        int ans;
        for(auto it:mp){
            int count = it.second;
            if(count>maxi){
                ans=it.first;
                maxi=it.second;
            }
        }
        return ans;

    }
};