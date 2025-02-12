class Solution {
public:

    int sumofdigit(int num){
        int sum=0;
        
        while(num>0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int maxsum=-1;
        for(int i=0;i<nums.size();i++){
            int digitsum=sumofdigit(nums[i]);
            mp[digitsum].push_back(nums[i]);
        }

        for(auto pair : mp){
            vector<int> values = pair.second;
            if(values.size()>1){
                sort(values.rbegin(),values.rend());
                maxsum=max(maxsum,values[0]+values[1]);
            }
        }
        return maxsum;

        
    }
};