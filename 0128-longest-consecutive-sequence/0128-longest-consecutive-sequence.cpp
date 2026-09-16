class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int ans=0;

        for(auto it:st){
            int count=0;
            if(st.find(it-1)==st.end()){
                count++;
                int num=it+1;
                while(st.find(num)!=st.end()){
                     count++;
                     num=num+1;
                }   
                ans=max(ans,count);
            }
        }
        return ans;
    }
};