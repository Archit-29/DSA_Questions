class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        int ans=0;
        for(auto it:nums) st.insert(it);

        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int count=1;
                int x= it+1;
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