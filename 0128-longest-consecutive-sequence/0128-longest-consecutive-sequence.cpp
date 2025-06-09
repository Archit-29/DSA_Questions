class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_set<int>st;
       int length=0;
       for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
       } 
       for(auto it : st){

            if(st.find(it-1)==st.end()){
                int count=1;
                int x=it;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    count++;
                }
                length=max(length,count);
            }
       }
       return length;
    }
};