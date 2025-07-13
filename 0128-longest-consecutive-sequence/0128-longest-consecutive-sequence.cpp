class Solution {
public:
    int  longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int count=0;
        int ans=0;
        int x=0;

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                count=0;
                x=it;
                while(st.find(x)!=st.end()){
                    count++;
                    x=x+1;
                }
                ans=max(ans,count);   
            }
        }
        return ans;
    }
};