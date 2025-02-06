class Solution {
public:

    int nc2(int n){
        return (n*(n-1))/2;
    }

    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                mp[nums[i]*nums[j]]++;
            }
        }

        int count=0;
        for(auto [product,freq]:mp){
            count += 8 * nc2(freq);
        }
        return count;
    }
};