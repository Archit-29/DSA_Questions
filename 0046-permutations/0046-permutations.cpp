class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>freq(nums.size(),0);
        vector<int>temp;
        vector<vector<int>>ans;
        helper(nums,freq,temp,ans);
        return ans;
    }

    void helper(vector<int>& nums,vector<int>freq,vector<int>temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                temp.push_back(nums[i]);
                freq[i]=1;
                helper(nums,freq,temp,ans);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
};